#ifndef WIDGER_HPP
#define WIDGET_HPP


#include "../class_point/point.hpp"

class Widget {

    private:
        Point start_ {};

        double width_ = 0;
        double height_ = 0;

    public:
        virtual void draw () = 0;
};


#endif