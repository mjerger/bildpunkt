#pragma once
#include "base.h"

#include <QDateTime>
#include <iostream>

class Log
{
public:
    Log() : level_(lvl_info)  {}
    ~Log() {}

    Log(Log const&)            = delete;
    void operator=(Log const&) = delete;

    static Log& get()
    {
        static Log instance;
        return instance;
    }

    enum level
    {
        lvl_verbose,
        lvl_debug,
        lvl_info,
        lvl_warning,
        lvl_error,
        lvl_explode
    };

private:
    std::mutex mutex_;
    level level_;

public:
    template<typename...A>
    void print(const char* file, const char* func, u32 line, level l, const string& format, A...args)
    {
        mutex_.lock();
        string out;
        out.reserve(256);

        // time
        out.append(QDateTime::currentDateTime().toString("HH:mm:ss:zzz"));

        // level
        static const char* level_strings[] = {" [VERBOSE] ",
                                              "   [DEBUG] ",
                                              "    [INFO] ",
                                              " [WARNING] ",
                                              "   [ERROR] ",
                                              " [EXPLODE] " };
        out.append(level_strings[l]);

        // format string
        const u32 num_args = sizeof...(A);
        var vars[num_args] = { (var(args))... };
        u32 var_index = 0;
        bool escape = false;
        for (QChar c : format)
        {
            if (!escape && c == '%' && var_index < num_args)
            {
                out.append(vars[var_index].toString());
                var_index++;
            }
            else
            {
                out.append(c);
            }
            escape = (c == '\\');
        }

        if (l == lvl_debug)
        {
            out.append(" (");
            out.append(file);
            out.append(" ");
            out.append(func);
            out.append(" ");
            out.append(string::number(line));
            out.append(")");
        }

        std::cout << out.toLocal8Bit().data() << std::endl;

        if (l == lvl_error || l == lvl_explode)
        {
            std::cerr << out.toLocal8Bit().data() << std::endl;
        }

        if (l == lvl_explode)
        {
            std::cerr << std::endl << ":( :( :(" << std::endl;
            explode();
        }

        mutex_.unlock();
    }
};


#define LOG Log::get()
#define LOGV(format, ...) Log::get().print(__FILE__, __func__, __LINE__, Log::lvl_verbose, format, __VA_ARGS__)
#define LOGD(format, ...) Log::get().print(__FILE__, __func__, __LINE__, Log::lvl_debug,   format, __VA_ARGS__)
#define LOGI(format, ...) Log::get().print(__FILE__, __func__, __LINE__, Log::lvl_info,    format, __VA_ARGS__)
#define LOGW(format, ...) Log::get().print(__FILE__, __func__, __LINE__, Log::lvl_warning, format, __VA_ARGS__)
#define LOGE(format, ...) Log::get().print(__FILE__, __func__, __LINE__, Log::lvl_error,   format, __VA_ARGS__)
#define EXPLODE(format, ...) Log::get().print(__FILE__, __func__, __LINE__, Log::lvl_explode, format, __VA_ARGS__)
