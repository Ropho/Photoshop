#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "widget.hpp"

namespace background {

    class Background : public Widget {

    public:
        Background (Widget *parent, const GLUT::Color& color) :
            Widget (parent),
            color_ (color)
            {
                logger.log (__PF);
                GLUT::Entity *entity = gl.init_background (color_);

                // NEW_CMD (ACTIONS::ADD_ENTITY, ENTITY_PTR, this, entity, GLUT::Entity *);
                // parent_ -> controller (cmd);
                // END_CMD;

            }

            void draw () {
                GLUT::Entity *entity = gl.init_background (color_);
                // gl.draw_background (color_);
            }

        bool on_click (int x, int y) override {return false;}
            
        private:
            GLUT::Color color_ = GLUT::Color::White;
    };



};


#endif