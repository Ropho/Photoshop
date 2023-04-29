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
            Widget (coords, parent), color_ (color), coords_ (coords)
        {
            Logger::Instance()->log(__PF);
            init ();
        }
        
        void init () override {
            canvas_ = (GLUT::GL::Instance()->init_canvas (coords_, color_));
        }

        void init_dot (Point pnt, GLUT::Color color) {
            Logger::Instance() -> log (__PF);
            entities_.push_back (GLUT::GL::Instance ()-> init_dot (pnt, color));
        }

        void draw () override {
            GLUT::GL::Instance ()-> draw (canvas_.drawable);
            
            for (size_t i = 0; i < entities_.size (); i++)
                GLUT::GL::Instance ()-> draw (entities_[i].drawable);
        }

        bool on_mouse_release (int x, int y) override {
            if (check_bound (x, y)) {

                fprintf (stderr, "RELEASE IN CANVAS!!!!\n");

                Canvas_Param *param = new Canvas_Param;
                param->pnt = Point (x, y);

                End_Use_Current_Tool cmd (this, param);
                
                Manager *man = dynamic_cast <Manager *> (parent_); 
                man -> controller (cmd);

                delete param;

                return true;
            }
            return false;
        }

        bool on_mouse_move (int x, int y) override {
            if (check_bound (x, y)) {
                fprintf (stderr, "MOVE IN CANVAS!!!!\n");
                
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

        bool on_mouse_press (int x, int y) override {
            if (check_bound (x, y)) {
                fprintf (stderr, "PRESS IN CANVAS!!!!\n");
                
                Canvas_Param *param = new Canvas_Param;
                param->pnt = Point (x, y);

                Start_Use_Current_Tool cmd (this, param);
                
                Manager *man = dynamic_cast <Manager *> (parent_); 
                man -> controller (cmd);

                delete param;

                return true;
            }
            return false;
        }

        void set_color (GLUT::Color color) {
            color_ = color;
        }
        
        private:
            GLUT::Entity canvas_;
            GLUT::Color color_;
            Coords coords_;
};

#endif