#ifndef COLOR_CHANGER_ACTIVATOR_HPP
#define COLOR_CHANGER_ACTIVATOR_HPP

#include "button.hpp"
#include "../cmd/activate.hpp"

    class Color_Changer_Activator : public Abstract_Button {

        public:
            Color_Changer_Activator (Coords coords, Widget* ptr, char *texture) :
                Abstract_Button (coords, ptr)
            {
                Logger::Instance () -> log (__PF);

                drawable_.push_back (GLUT::GL::Instance()->init_border (coords_.strt (), coords_.width (), coords_.height ()));
                drawable_.push_back (GLUT::GL::Instance()->init_button (coords_.strt (), coords_.width (), coords_.height (), texture));
            }

            ~Color_Changer_Activator () {
                Logger::Instance () -> log (__PF);
            }

            void action () {
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
    };

#endif