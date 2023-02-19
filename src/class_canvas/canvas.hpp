#ifndef CANVAS_HPP
#define CANVAS_HPP


#include "../class_widget/widget.hpp"
#include "../log/log.hpp"
#include "../graph_lib/lib.hpp"


class Canvas : public Widget {

    public:

        ~Canvas () {
            logger.log (__PF);
        }

        Canvas (Coords coords, Widget *parent) :
            Widget (coords, parent)
        {
            gl.init_canvas (coords_);
            gl.change_canvas (color_);
            logger.log (__PF);
        }

        void draw  () {
            gl.draw_canvas ();
        }
        
        // void close ();
        // void move  ();
        bool on_click (int x, int y) {
            if (check_bound (x, y)) {
                fprintf (stderr, "IN CANVAS!!!!\n");
                
                Cmd <Point> cmd (ACTIONS::USE_TOOL, Point (x, y));
                parent_ -> controller (cmd);

                return true;
            }
            return false;
        }

        void set_color (int color) {
            color_ = color;
            gl.change_canvas (color_);
        }
        
        private:
            int color_ = GLUT::WHITE;
};

#endif