#include "base.h"
#include <iostream>
#include <signal.h>

void crash()
{
    raise(SIGSEGV);
}
