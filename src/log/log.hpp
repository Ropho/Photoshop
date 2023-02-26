#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
// #include <vector>
// #include "class_vector/vector.hpp"

#define __PF __PRETTY_FUNCTION__
#define __F  __FUNCTION__

// void log (const char *func_name);

enum MODES {

    INFO     = 1,
    CRITICAL = 2,
};

class Logger {

    public:


        Logger (FILE* out = stderr) :
            out_ (out)
        {}

        FILE *output_file () {
            return out_;
        }

        void log (const char *func_name, int mode = INFO, const char *message = nullptr) {
            
            switch (mode) {
                
                case INFO: {
    // fprintf (stderr, "\x1b[31mFUNC: \x1b[32m%s\x1b[0m\n", func_name);
                    fprintf (out_, "\x1b[33m[INFO] \x1b[92m%s \x1b[33m%s\x1b[0m\n", func_name, message);
                }break;

                case CRITICAL: {
                    fprintf (out_, "\x1b[31m[INFO] \x1b[92m%s \x1b[31m%s\x1b[0m\n", func_name, message);
                }break;

                default:
                
                break;
            }
        }

    private:
        FILE *out_ = nullptr;
};


extern Logger logger;


#endif