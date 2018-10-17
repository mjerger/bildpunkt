#pragma once
#include "base.h"

#include <QDateTime>
#include <iostream>

#define logv(...)    Log::get().print(__FILE__, __func__, __LINE__, Log::lvl_verbose, __VA_ARGS__)
#define logd(...)    Log::get().print(__FILE__, __func__, __LINE__, Log::lvl_debug,   __VA_ARGS__)
#define logi(...)    Log::get().print(__FILE__, __func__, __LINE__, Log::lvl_info,    __VA_ARGS__)
#define logw(...)    Log::get().print(__FILE__, __func__, __LINE__, Log::lvl_warning, __VA_ARGS__)
#define loge(...)    Log::get().print(__FILE__, __func__, __LINE__, Log::lvl_error,   __VA_ARGS__)
#define explode(...) Log::get().print(__FILE__, __func__, __LINE__, Log::lvl_explode, __VA_ARGS__)

class Log
{
public:
    Log()  {}
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

public:
    template<class...A>
    void print(const char* file, const char* func, u32 line, level l, A...args)
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
        var vars[] = { (var(args))... };
        u32 var_index = 1;
        bool escape = false;
        for (QChar c : vars[0].toString())
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

#ifdef NO_QT_DEBUG
        if (l == lvl_debug)
#endif
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
            crash();
        }

        mutex_.unlock();
    }
};
