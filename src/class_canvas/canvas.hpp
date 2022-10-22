#ifndef CANVAS_HPP
#define CANVAS_HPP


#include "../class_point/point.hpp"
#include "../class_widget/widget.hpp"
#include "../general.hpp"
#include "../graph_lib/lib.hpp"

class Canvas : public Widget {

    public:

        ~Canvas () {
            LOG;
        }

        Canvas (Point start, int width, int height) :
            Widget (start, width, height)
        {
            LOG;
        }

        void draw  () {
            
            gl.draw_canvas (start_, width_, height_, color_);
        }
        
        // void close ();
        // void move  ();
        bool on_click (int x, int y) {
            if (check_bound (x, y)) {
                fprintf (stderr, "IN CANVAS!!!!\n");
                return true;
            }
            return false;
        }

        // void on_press ();

        int color_ = GLUT::BLUE;
};

#endif