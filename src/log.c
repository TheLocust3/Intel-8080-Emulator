//
// Created by Jake Kinsella on 7/30/17.
//

#include "log.h"

void log(char *fmt, ...)
{
    if (!LOG) return;

    va_list ap;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);
}
