#ifndef CANVAS_HPP
#define CANVAS_HPP


#include "../widget/widget.hpp"

class Canvas : public Widget {

    public:

        ~Canvas () {
            Logger::Instance()->log(__PF);
        }

        Canvas (Coords coords, GLUT::Color color, Widget *parent) :
            Widget (coords, parent), color_ (color), coords_ (coords)
        {
            Logger::Instance()->log(__PF);
            init ();
        }
        
        // void close ();
        // void move  ();
        void init () override {
            drawable_.push_back (GLUT::GL::Instance()->init_canvas (coords_, color_));
        }

        bool on_click (int x, int y) {
            if (check_bound (x, y)) {
                fprintf (stderr, "IN CANVAS!!!!\n");
                
                // NEW_CMD (ACTIONS::USE_TOOL, POINT, this, Point (x, y), Point);
                // Cmd <Point> cmd (ACTIONS::USE_TOOL, static_cast <void *> (this), Point (x, y));
                // parent_ -> controller (cmd);
                // END_CMD;
                return true;
            }
            return false;
        }

        void set_color (GLUT::Color color) {
            color_ = color;
        }
        
        private:
            GLUT::Color color_;
            Coords coords_;
};

#endif