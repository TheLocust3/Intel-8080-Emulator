//
// Created by Jake Kinsella on 7/30/17.
//

#include <printf.h>
#include "log.h"

void log(char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);
    va_start(ap, fmt);
    va_end(ap);
}
