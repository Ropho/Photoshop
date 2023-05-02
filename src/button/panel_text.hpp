#ifndef PANEL_TEXT_BUTTON_HPP
#define PANEL_TEXT_BUTTON_HPP

#include "button.hpp"
#include "../cmd/activate.hpp"

    class Panel_Text : public Abstract_Button {

        public:
            Panel_Text (Coords coords, Widget* ptr, const GLUT::Color& color, const std::string &message) :
                Abstract_Button (coords, ptr, ""), message_ (message), color_ (color)
            {
                Logger::Instance () -> log (__PF);
                init ();
            }

            void init () override {
                entities_.push_back (GLUT::GL::Instance()->init_border (coords_.strt (), coords_.width (), coords_.height ()));
                entities_.push_back (GLUT::GL::Instance()->init_button_color (coords_.strt (), coords_.width (), coords_.height (),color_ ));
                entities_.push_back (GLUT::GL::Instance()->init_text_button (coords_.strt (), coords_.width (), coords_.height (), 
                                    color_, message_));
            }

            ~Panel_Text () {
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
                        Logger::Instance ()-> log (__PF, 2, "unable to convert to manager\n");
                    }
                }
                else {
                    Deactivate cmd (this);
                    Manager * man = dynamic_cast <Manager *> (parent_);
                    if (man)
                        man -> controller (cmd);
                    else {
                        Logger::Instance ()-> log (__PF, 2, "unable to convert to manager\n");
                    }
                }
            }

            void action_on_mouse_release () override {}


        protected:
            std::string message_;
            GLUT::Color color_;
    };

#endif