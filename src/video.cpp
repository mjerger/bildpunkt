#include "video.h"

using namespace cv;

Video::Video() :
    loaded_(false),
    pos_(0),
    width_(0),
    height_(0),
    fps_(0.0),
    num_frames_(0),
    length_(0.0)
{
}

bool Video::load(QString file)
{
    vc_.release();

    if (vc_.open(file.toLatin1().data()))
    {
        width_      = u32(vc_.get(CAP_PROP_FRAME_WIDTH));
        height_     = u32(vc_.get(CAP_PROP_FRAME_HEIGHT));
        fps_        = dbl(vc_.get(CAP_PROP_FPS));
        num_frames_ = u32(vc_.get(CAP_PROP_FRAME_COUNT));
        length_     = frame_to_time(num_frames_);
    }
    else
    {
        width_ = height_ = num_frames_ = pos_ = 0;
        fps_ = length_ =  0.0;
    }

    loaded_ = valid();

    return loaded_;
}

void Video::close()
{
}

bool Video::valid()
{
    return loaded_ && width_ && height_ && fps_ > 0 && num_frames_ && length_ > 0;
}

u32 Video::width()
{
    return width_;
}

u32 Video::height()
{
    return height_;
}

dbl Video::fps()
{
    return fps_;
}

u32 Video::num_frames()
{
    return num_frames_;
}

dbl Video::length()
{
    return length_;
}

Mat Video::frame()
{
    capture();
    return frame_;
}

Mat Video::frame(u32 index)
{
    if (index != pos_ + 1)
    {
        vc_.set(CV_CAP_PROP_POS_FRAMES, index);
    }

    capture();
    return frame_;
}

dbl Video::frame_to_time(u32 index)
{
    if (!valid()) return 0.0;
    return dbl(index) / fps_;
}

u32 Video::time_to_frame(dbl time)
{
    if (!valid()) return 0.0;
    return u32(ceil(time * fps_));
}


void Video::capture()
{
    vc_.retrieve(frame_);
}

