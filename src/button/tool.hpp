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
                drawable_.push_back (GLUT::GL::Instance()->init_border (coords_.strt (), coords_.width (), coords_.height ()));
                drawable_.push_back (GLUT::GL::Instance()->init_canvas_background_changer (coords_.strt (), coords_.width (), coords_.height (), GLUT::Color::Red,
                                    Abstract_Button::texture_path ()));
            }

            ~Tool_Button () {
                Logger::Instance () -> log (__PF);
                delete tool_;
            }

            void action () override {
                if (!active_) {
                Logger::Instance () -> log (__PF);
                    active_ = true;

                    Set_Current cmd (this, tool_);
                    Manager *man = dynamic_cast <Manager *> (parent_);
                    if (man == nullptr) {
                        std::terminate ();
                    }
                    man -> controller (cmd);

                    // NEW_CMD (ACTIONS::SET_CURRENT, TOOL_PTR, this, tool_, Tool*);
                    // parent_ -> controller (cmd);
                    // END_CMD;
                }
                else {
                    active_ = false;

                    // NEW_CMD (ACTIONS::REMOVE_CURRENT, NULLPTR, this, nullptr, nullptr_t);
                    Remove_Current cmd (this);
                    Manager *man = dynamic_cast <Manager *> (parent_);
                    if (man == nullptr) {
                        std::terminate ();
                    }
                    man -> controller (cmd);
                    // END_CMD;
                }
            }
        protected:
            Abstract_Tool *tool_ = nullptr;
    };

#endif