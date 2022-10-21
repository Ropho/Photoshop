#ifndef GENERAL_HPP
#define GENERAL_HPP

#include <iostream>
#include <vector>

#define LOG(str) do {                                           \
                log (__PRETTY_FUNCTION__, str);                 \
            } while (0)

void log (const char *func_name, const char *str);


#endif