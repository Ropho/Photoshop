#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "widget.hpp"

    class Background : public Widget {

    public:
        Background (Widget *parent, const GLUT::Color& color) :
            Widget (parent),
            color_ (color)
            {
                Logger::Instance()->log (__PF);

                init ();
            }

        void init () override {
            background_ = (GLUT::GL::Instance()->init_background (color_));
            entities_.push_back (background_);
        }

        bool on_mouse_release (int x, int y) override {return false;}
        bool on_mouse_press (int x, int y) override {return false;}
        bool on_mouse_move  (int x, int y) override {return false;}

        private:
            GLUT::Color color_;
            GLUT::Entity background_;
    };



#endif