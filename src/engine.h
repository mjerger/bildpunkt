#pragma once

#include "base.h"
#include "video.h"
#include <opencv2/opencv.hpp>

class Engine
{
public:
    Engine();

    void update();

    bool load(string path);
    void start();
    void stop();
    void seek(dbl ms = 0.0);
    void seek(u32 frame = 0.0);

private:
    void reset();

    bool running_;
    Video video_;
};
