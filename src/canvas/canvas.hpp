#ifndef CANVAS_HPP
#define CANVAS_HPP


#include "../widget/widget.hpp"
#include "../cmd/use.hpp"

struct Canvas_Param {
    Point pnt;
};

class Canvas : public Widget {

    public:

        ~Canvas () {
            Logger::Instance()->log(__PF);
        }

        Canvas (Coords coords, GLUT::Color color, Widget *parent) :
            Widget (coords, parent), background_color_ (color), background_coords_ (coords)
        {
            Logger::Instance()->log(__PF);
            init ();
        }
        
        void init () override {
            drawable_.push_back (GLUT::GL::Instance()->init_canvas (background_coords_, background_color_));
        }

        void init_dot (Point pnt, GLUT::Color color) {
            Logger::Instance() -> log (__PF);
            drawable_.push_back (GLUT::GL::Instance ()-> init_dot (pnt, color));
        }

        bool on_click (int x, int y) {
            if (check_bound (x, y)) {
                fprintf (stderr, "IN CANVAS!!!!\n");
                
                Canvas_Param *param = new Canvas_Param;
                param->pnt = Point (x, y);

                Use_Current_Tool cmd (this, param);
                
                Manager *man = dynamic_cast <Manager *> (parent_); 
                man -> controller (cmd);

                delete param;

                return true;
            }
            return false;
        }

        void set_color (GLUT::Color color) {
            background_color_ = color;
        }
        
        private:
            GLUT::Color background_color_;
            Coords background_coords_;
};

#endif