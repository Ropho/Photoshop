#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>

#define __PF __PRETTY_FUNCTION__

enum class LOG_LVL {

    INFO     = 1,
    FATAL    = 2,
    TRACE    = 3,
    ERROR    = 4,
};

class Logger {

    public:
        static Logger *Instance () {
            if (instance_) {
                instance_ = new Logger {};
            }
            return instance_;
        }

        void log (const char *func_name, LOG_LVL mode = LOG_LVL::INFO, const char *message = nullptr) {
            
            switch (mode) {
                
                case LOG_LVL::TRACE: {
                    fprintf (stderr, "\x1b[32m[TRACE] \x1b[95m%s \x1b[37m%s\x1b[0m\n", func_name, message);
                } break;

                case LOG_LVL::INFO: {
                    fprintf (stderr, "\x1b[36m[INFO] \x1b[95m%s \x1b[37m%s\x1b[0m\n", func_name, message);
                }break;

                case LOG_LVL::ERROR: {
                    fprintf (stderr, "\x1b[33m[ERROR] \x1b[95m%s \x1b[37m%s\x1b[0m\n", func_name, message);
                }break;
                case LOG_LVL::FATAL: {
                    fprintf (stderr, "\x1b[31m[FATAL] \x1b[95m%s \x1b[37m%s\x1b[0m\n", func_name, message);
                }break;

                default:
                    std::terminate ();
                break;
            }
        }

    protected:
        Logger () {
            log (__PF);
        }
        // ~Logger
    private:
        inline static Logger *instance_ = nullptr;
};

#endif