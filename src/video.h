#pragma once

#include "base.h"
#include <opencv2/opencv.hpp>

class Video
{
public:
    Video();

    bool load(string file);
    void close();

    bool valid();

    u32 width();
    u32 height();
    dbl fps();
    u32 num_frames();
    dbl length();

    img frame();
    img frame(u32 index);

    dbl frame_to_time(u32 index);
    u32 time_to_frame(dbl time);

private:
    void capture();

    bool loaded_;
    cv::VideoCapture vc_;
    img frame_;
    u32 pos_;
    u32 width_;
    u32 height_;
    dbl fps_;
    u32 num_frames_;
    dbl length_;

};
