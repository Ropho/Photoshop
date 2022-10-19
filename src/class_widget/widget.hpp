#ifndef WIDGET_HPP
#define WIDGET_HPP


#include "../class_point/point.hpp"

#define LOG(str) do {                                           \
                log (__PRETTY_FUNCTION__, str);                 \
            } while (0)


class Widget {

    protected:
        Point start_ {};

        double width_ = 0;
        double height_ = 0;


    public:

        Widget (Point start, double width, double height) :
            start_ (start), width_ (width), height_ (height)
        {
            LOG("CTOR WIDGET");
        }

        virtual void log (const char *func_name, const char *str) {
            printf ("FUNC: %s \t MESSAGE: %s\n", func_name, str);
        }

        virtual void draw  () = 0;
        virtual void close () = 0;
        virtual void move  () = 0;
        virtual void on_click () = 0;
        virtual void on_press () = 0;

};


#endif