#ifndef GENERAL_HPP
#define GENERAL_HPP

#include <iostream>
#include <vector>

#define LOG do {                                           \
                log (__PRETTY_FUNCTION__);                 \
            } while (0)

void log (const char *func_name);


#endif