#include "base.h"
#include <iostream>
#include <signal.h>

void explode()
{
    raise(SIGSEGV);
}
