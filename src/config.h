#pragma once

#include "base.h"

class Config
{
public:
    Config();

    bool load(string file);
    bool reload();
    bool save();

    template<typename V> const V& get(string name);
    template<typename V> void set(string name, const V& value);

private:
    json get_section(string name);

    bool loaded_;
    string file_;
    QVariantMap entries_;
};
