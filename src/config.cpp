#include "config.h"

#include <QFile>
#include <QTextStream>

Config::Config() :
    loaded_(false)
{
}

bool Config::load(string file)
{
    loaded_ = false;
    entries_.clear();

    string str;
    QFile f(file);
    if (f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&f);
        bool has_line = true;
        while (has_line)
        {
            // read line
            string line = stream.readLine();
            has_line = !line.isNull();
            if (!has_line) break;

            // get key and value
            list<string> kv = line.split("=");
            if (kv.length() != 2)
            {
                warning("Invalid line in config file %s", file);
                continue;
            }
            string key = kv.first().trimmed();
            string value = kv.last().trimmed();

            // read key value pair
            if (entries_.contains(key))
            {
                warning("Duplicate entry in config file %s", file);
                continue;
            }

            loaded_ = true;
        }
    }
    f.close();

    return loaded_;
}

bool Config::reload()
{
    return load(file_);
}

bool Config::save()
{
    QFile f(file_);
    if (f.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&f);
        for (string key : entries_.keys())
        {
            var val = entries_[key];
            stream <<  key << '=' << val.toString() << endl;
        }
        return true;
    }

    return false;
}


template<typename V> const V& Config::get(string name)
{
    if (!entries_.contains(name) || !entries_[name].canConvert<V>())
    {
        return nullptr;
    }

    return entries_[name].value<V>();
}

template<typename V> void Config::set(string name, const V& value)
{
    entries_.insert(name, value);
}
