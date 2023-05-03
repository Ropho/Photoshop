#ifndef TOOL_COLOR_CHANGER_HPP
#define TOOL_COLOR_CHANGER_HPP

#include "button.hpp"
#include "../cmd/set_tool_color.hpp"

    class Tool_Color_Changer : public Abstract_Button {
        public:
            Tool_Color_Changer (Coords coords, Widget* ptr, GLUT::Color color, const std::string &texture_path) :
                Abstract_Button (coords, ptr, texture_path),
                color_  (color)
            {
                Logger::Instance () -> log (__PF);
                init ();
            }

            void init () override {
                entities_.push_back (GLUT::GL::Instance()->init_border (coords_.strt (), coords_.width (), coords_.height ()));
                entities_.push_back (GLUT::GL::Instance()->init_canvas_background_changer (coords_.strt (), coords_.width (), coords_.height (), color_,
                                    Abstract_Button::texture_path ()));
            }

            ~Tool_Color_Changer () override {
                Logger::Instance () -> log (__PF);
            }

            void action_on_mouse_press () {
                Logger::Instance () -> log (__PF);
                
                Set_Tool_Color cmd (this, color_);

                Manager *man = dynamic_cast <Manager *> (parent_);
                if (man)
                    man -> controller (cmd);
                else {
                    Logger::Instance () -> log (__PF, LOG_LVL::FATAL, "unable to convert to manager");
                    std::terminate ();
                }
            }

            void action_on_mouse_release () override {}

            void draw () override {
                if (active_) {
                    this->Widget::draw ();
                }
            }

        private:
            GLUT::Color color_ = GLUT::Color::Black;
    };
 
#endif