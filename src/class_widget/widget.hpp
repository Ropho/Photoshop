#ifndef WIDGET_HPP
#define WIDGET_HPP


#include "../class_point/point.hpp"


class Widget {

    protected:
        Point start_ {};

        double width_ = 0;
        double height_ = 0;


    public:

        virtual ~Widget () {
            LOG ("~WIDGET");
        }

        Widget (Point start, double width, double height) :
            start_ (start), width_ (width), height_ (height)
        {
            LOG("WIDGET ()");
        }

        virtual void draw  () = 0;
        // virtual void close () = 0;
        // virtual void move  () = 0;
        // virtual void on_click () = 0;
        // virtual void on_press () = 0;

};


#endif