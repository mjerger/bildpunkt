#include "config.h"
#include "log.h"

#include <QFile>
#include <QTextStream>

bool Config::load(string file)
{
    string str;
    QFile f(file);
    if (f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&f);

        int num_loaded = 0;
        int num_new = 0;

        while (true)
        {
            // read line
            string line = stream.readLine();
            if (line.isNull()) break;

            line = line.trimmed();
            if (line.isEmpty() || line.startsWith("#")) continue;

            // get key and value
            list<string> kv = line.split("=");
            if (kv.length() != 2)
            {
                logd("Invalid line in config file %: '%'", file, line);
                continue;
            }
            string key = kv.first().trimmed();
            string value = kv.last().trimmed();

            if (!entries_.contains(key)) num_new++;
            entries_.insert(key, value);
            num_loaded++;
        }
        logi("Loaded % config values from % (% are new)", num_loaded, file, num_new);

        f.close();
        return true;
    }
    else
    {
        logw("Could not open config file % (error %)", file, f.errorString());
        return false;
    }
}

bool Config::reload()
{
    return load(file_);
}

bool Config::save()
{
    if (file_.startsWith(":"))
    {
        return false;
    }

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
