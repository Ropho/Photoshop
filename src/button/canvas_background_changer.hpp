#ifndef CANVAS_BACKGROUND_CHANGER_HPP
#define CANVAS_BACKGROUND_CHANGER_HPP

#include "button.hpp"
#include "../cmd/change_canvas_background.hpp"
#include "../manager/manager.hpp"

    class Canvas_Background_Changer : public Abstract_Button {

        public:
            Canvas_Background_Changer (Coords coords, Widget* ptr, GLUT::Color color, const std::string& texture_path) :
                Abstract_Button (coords, ptr, texture_path),
                color_  (color)
            {
                Logger::Instance ()->log (__PF);
                init ();
            }

            void init () override {
                entities_.push_back (GLUT::GL::Instance()->init_border (coords_.strt (), coords_.width (), coords_.height ()));
                entities_.push_back (GLUT::GL::Instance()->init_canvas_background_changer (coords_.strt (), coords_.width (), coords_.height (), color_, 
                                    Abstract_Button::texture_path ()));
            }

            ~Canvas_Background_Changer () {
                Logger::Instance ()->log (__PF);
            }

            void action_on_mouse_press () override {
                Logger::Instance ()->log (__PF);
                Change_Canvas_Background cmd (this, color_);
                
                Manager *caller = dynamic_cast <Manager *> (parent_);
                caller -> controller (cmd);
            }            
            void action_on_mouse_release () override {}

        private:
            GLUT::Color color_;
    };


#endif