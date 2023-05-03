#ifndef COLOR_CHANGER_ACTIVATOR_HPP
#define COLOR_CHANGER_ACTIVATOR_HPP

#include "button.hpp"
#include "../cmd/activate.hpp"

    class Color_Changer_Activator : public Abstract_Button {

        public:
            Color_Changer_Activator (Coords coords, Widget* ptr, const std::string &texture_path) :
                Abstract_Button (coords, ptr, texture_path)
            {
                Logger::Instance () -> log (__PF);
                init ();
            }

            void init () override {
                entities_.push_back (GLUT::GL::Instance()->init_border (coords_.strt (), coords_.width (), coords_.height ()));
                entities_.push_back (GLUT::GL::Instance()->init_button (coords_.strt (), coords_.width (), coords_.height (), 
                                    Abstract_Button::texture_path ()));
            }
            
            ~Color_Changer_Activator () {
                Logger::Instance () -> log (__PF);
            }

            void action_on_mouse_press () override {
                Logger::Instance () -> log (__PF);

                if (!active_) {
                    Activate cmd (this);

                    Manager * man = dynamic_cast <Manager *> (parent_);
                    if (man)
                        man -> controller (cmd);
                    else {
                        Logger::Instance () -> log (__PF, LOG_LVL::FATAL, "unable to convert to manager");
                    }
                }
                else {
                    Deactivate cmd (this);
                    Manager * man = dynamic_cast <Manager *> (parent_);
                    if (man)
                        man -> controller (cmd);
                    else {
                        Logger::Instance () -> log (__PF, LOG_LVL::FATAL, "unable to convert to manager");
                    }
                }
            }
            void action_on_mouse_release () override {}
    };

#endif