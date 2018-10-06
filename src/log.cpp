#include "log.h"
#include <stdio.h>
#include <signal.h>

void debug(string fmt, string args...)
{
    log_base(stdout, "  DEBUG", fmt.toLatin1(), args.toLatin1().data());
}

void info(string fmt, string args...)
{
    log_base(stdout, "   INFO", fmt.toLatin1(), args.toLatin1().data());
}

void warning(string fmt, string args...)
{
    log_base(stderr, "WARNING", fmt.toLatin1(), args.toLatin1().data());
}

void error(string fmt, string args...)
{
    log_base(stderr, "  ERROR", fmt.toLatin1(), args.toLatin1().data());
}

void explode(string fmt, string args...)
{
    log_base(stderr, "EXPLODE", fmt.toLatin1(), args.toLatin1().data());
    log_base(stdout, "EXPLODE", fmt.toLatin1(), args.toLatin1().data());
    raise(SIGSEGV);
}

void log_base(FILE* stream, const char* level, const char* fmt...)
{
    va_list args;
    va_start (args, fmt);
    fprintf(stream, "%s ", level);
    vfprintf(stream, fmt, args);
    va_end (args);
}
