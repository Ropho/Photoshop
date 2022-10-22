#ifndef WIDGET_HPP
#define WIDGET_HPP


#include "../class_point/point.hpp"


class Widget {

    protected:
        Point start_ {};

        int width_  = 0;
        int height_ = 0;


    public:

        virtual ~Widget () {
            LOG;
        }

        Widget () = default;

        Widget (Point start, int width, int height) :
            start_ (start), width_ (width), height_ (height)
        {
            LOG;
        }

        virtual void draw  () = 0;

        // virtual void close () = 0;
        // virtual void move  () = 0;
        virtual bool on_click (int x, int y) = 0;
        // virtual void on_press () = 0;
        
        
        bool check_bound (int x, int y) {
            
            if (x <= start_.get_x () + width_ && x >= start_.get_x ()) {
                if (y <= start_.get_y () + height_ && y >= start_.get_y ()) 
                    return true;
            }
            return false;
        }

/////////////////////////////////////////////////FOR MANAGER CLASS
        virtual void add (Widget *widget) {};
        virtual void clear () {};

};


#endif