#pragma once

#include <QtCore>

#include <cstdint>
using chr = unsigned char;
using u8  = uint8_t;
using s8  = int8_t;
using u16 = uint16_t;
using s16 = int16_t;
using u32 = uint32_t;
using s32 = int32_t;
using u64 = uint64_t;
using s64 = int64_t;
using flt = float;
using dbl = double;

#include <QString>
#include <QJsonObject>
#include <QVariant>
#include <QList>
#include <QMap>
#include <QSet>

using string = QString;
using json = QJsonObject;
using var = QVariant;
template <class V> using list = QList<V>;
template <class K, class V> using map = QMap<K,V>;
template <class V> using set = QSet<V>;

#include <opencv/cv.h>
using img = cv::Mat;
using v2 = cv::Vec2d;
using v3 = cv::Vec3d;

template<class...A> string format(A...args)
{
    string result;
    result.reserve(256);

    const u32 num_args = sizeof...(A);
    var vars[] = { (var(args))... };
    u32 var_index = 1;
    bool escape = false;
    for (QChar c : vars[0].toString())
    {
        if (!escape && c == '%' && var_index < num_args)
        {
            result.append(vars[var_index].toString());
            var_index++;
        }
        else
        {
            result.append(c);
        }
        escape = (c == '\\');
    }

    return result;
}

extern void crash();

class App;
