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

        Canvas (Coords coords, Widget *parent) :
            Widget (coords, parent)
        {
            LOG;
        }

        void draw  () {
            
            gl.draw_canvas (coords_.strt (), coords_.width (), coords_.height (), color_);
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

        void set_color (int color) {
            color_ = color;
        }

        // void on_press ();

        private:
            int color_ = GLUT::BLUE;
};

#endif