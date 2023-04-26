#ifndef CANVAS_BACKGROUND_CHANGER_HPP
#define CANVAS_BACKGROUND_CHANGER_HPP

#include "button.hpp"
#include "../cmd/change_canvas_background.hpp"
#include "../manager/manager.hpp"

    class Canvas_Background_Changer : public Abstract_Button {

        public:
            Canvas_Background_Changer (Coords coords, Widget* ptr, GLUT::Color color) :
                Abstract_Button (coords, ptr),
                color_  (color)
            {
                Logger::Instance ()->log (__PF);

                drawable_.push_back (GLUT::GL::Instance()->init_border (coords_.strt (), coords_.width (), coords_.height ()));
                drawable_.push_back (GLUT::GL::Instance()->init_canvas_background_changer (coords_.strt (), coords_.width (), coords_.height (), color_));
            }

            ~Canvas_Background_Changer () {
                Logger::Instance ()->log (__PF);
            }

            void action () override {
                Logger::Instance ()->log (__PF);
                Change_Canvas_Background cmd (this, color_);
                
                Manager *caller = dynamic_cast <Manager *> (parent_);
                caller -> controller (cmd);
            }            

        private:
            GLUT::Color color_;
    };


#endif