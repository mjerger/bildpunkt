#pragma once

#include "base.h"

extern void debug  (string fmt, string args...);
extern void info   (string fmt, string args...);
extern void warning(string fmt, string args...);
extern void error  (string fmt, string args...);
extern void explode(string fmt, string args...);
extern void log_base(FILE* stream, const char* level, const char* fmt...);
