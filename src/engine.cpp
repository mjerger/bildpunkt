#include "engine.h"

using namespace cv;

Engine::Engine()
{
}

void Engine::update()
{
    if (!running_) return;

}

bool Engine::load(string file)
{
    reset();
    return video_.load(file);
}

void Engine::reset()
{
    running_ = false;
}

void Engine::start()
{
    reset();
    running_ = true;
}

void Engine::stop()
{
    running_ = false;
}

void Engine::seek(dbl ms)
{
    if (!running_ || !video_.valid()) return;
}


void Engine::seek(u32 frame)
{
    if (!running_ || !video_.valid()) return;
}

