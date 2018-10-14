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
template <typename V> using list = QList<V>;
template <typename K, typename V> using map = QMap<K,V>;
template <typename V> using set = QSet<V>;

#include <opencv/cv.h>
using img = cv::Mat;
using v2 = cv::Vec2d;
using v3 = cv::Vec3d;

extern void explode();

namespace version
{
    static const u8 major = 0;
    static const u8 minor = 1;
}
