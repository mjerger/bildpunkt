#pragma once

#include "base.h"
#include "log.h"

class Config
{
public:
    Config();

    bool load(string file);
    bool reload();
    bool save();

    template<typename V> V get(string name)
    {
        if (!entries_.contains(name) || !entries_[name].canConvert<V>())
        {
            EXPLODE("Invalid config entry '%'", name);
        }

        return entries_[name].value<V>();
    }

    template<typename V> void set(string name, const V& value)
    {
        entries_.insert(name, value);
    }

private:

    bool loaded_;
    string file_;
    QVariantMap entries_;
};
