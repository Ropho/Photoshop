#ifndef BUTTON_HPP
#define BUTTON_HPP

// #include "../../lib/logger/logger.hpp"
#include "../widget/widget.hpp"

    class Abstract_Button : public Widget {

        public:

            Abstract_Button (Coords coords, Widget *parent) :
                Widget (coords, parent)
            {
                Logger::Instance ()->log (__PF);
            }

            virtual ~Abstract_Button () {
                Logger::Instance ()->log (__PF);
            }

            virtual void action () = 0;
            
            bool on_click (int x, int y) {
                if (check_bound (x, y)) {
                    action ();
                    return true;
                }

                return false;
            }
    };
#endif