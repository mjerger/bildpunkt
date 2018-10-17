#pragma once

#include "base.h"
#include "log.h"

class Config : public QObject
{
    Q_OBJECT

public:
    Config() : QObject() {}
    virtual ~Config() {}

    bool load(string file);
    bool reload();
    bool save();

    template<typename V> V get(string name)
    {
        if (!entries_.contains(name) || !entries_[name].canConvert<V>())
        {
            explode("Invalid config entry '%'", name);
        }

        return entries_[name].value<V>();
    }

    template<typename V> void set(string name, const V& value)
    {
        entries_.insert(name, value);
    }

signals:
    void settings_changed();


private:

    bool loaded_;
    string file_;
    QVariantMap entries_;
};
