#ifndef TOOL_BUTTON_HPP
#define TOOL_BUTTON_HPP

#include "../cmd/current.hpp"

    class Tool_Button : public Abstract_Button {

        public:
            Tool_Button (Coords coords, Widget* ptr, Abstract_Tool* tool, const std::string &texture_path) :
                Abstract_Button (coords, ptr, texture_path), 
                tool_ (tool)
            {
                Logger::Instance () -> log (__PF);
                init ();
            }

            void init () override {
                entities_.push_back (GLUT::GL::Instance()->init_border (coords_.strt (), coords_.width (), coords_.height ()));
                entities_.push_back (GLUT::GL::Instance()->init_canvas_background_changer (coords_.strt (), coords_.width (), coords_.height (), GLUT::Color::Red,
                                    Abstract_Button::texture_path ()));
            }

            ~Tool_Button () {
                Logger::Instance () -> log (__PF);
                delete tool_;
            }

            void action_on_mouse_press () override {
                if (!active_) {
                Logger::Instance () -> log (__PF);
                    active_ = true;

                    Set_Current cmd (this, tool_);
                    Manager *man = dynamic_cast <Manager *> (parent_);
                    if (man == nullptr) {
                        std::terminate ();
                    }
                    man -> controller (cmd);

                }
                else {
                    active_ = false;

                    Remove_Current cmd (this);
                    Manager *man = dynamic_cast <Manager *> (parent_);
                    if (man == nullptr) {
                        std::terminate ();
                    }
                    man -> controller (cmd);
                }
            }

            void action_on_mouse_release () override {}

        protected:
            Abstract_Tool *tool_ = nullptr;
    };

#endif