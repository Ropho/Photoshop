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

                drawable_.push_back (GLUT::GL::Instance()->init_background (color_));

                // Add_entity cmd (background, "background", this);
                // parent -> controller (cmd);
                // NEW_CMD (ACTIONS::ADD_ENTITY, ENTITY_PTR, this, entity, GLUT::Entity *);
                // parent_ -> controller (cmd);
                // END_CMD;
            }

        bool on_click (int x, int y) override {return false;}
            
        private:
            GLUT::Color color_;
    };



#endif