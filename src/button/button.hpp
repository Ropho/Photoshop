#ifndef BUTTON_HPP
#define BUTTON_HPP

// #include "../../lib/logger/logger.hpp"
#include "../widget/widget.hpp"

    class Abstract_Button : public Widget {

        public:

            Abstract_Button (Coords coords, Widget *parent, const std::string &texture_path) :
                Widget (coords, parent), texture_path_ (texture_path)
            {
                Logger::Instance ()->log (__PF);
            }

            virtual ~Abstract_Button () {
                Logger::Instance ()->log (__PF);
            }

            virtual void action_on_mouse_release () = 0;
            virtual void action_on_mouse_press () = 0;
            
            virtual bool on_mouse_release (int x, int y) {
                if (check_bound (x, y)) {
                    action_on_mouse_release ();
                    return true;
                }

                return false;
            }

            virtual bool on_mouse_press (int x, int y) {
                if (check_bound (x, y)) {
                    action_on_mouse_press ();
                    return true;
                }

                return false;
            }

            virtual bool on_mouse_move (int x, int y) {
                return false;
            }

            std::string& texture_path () {
                return texture_path_;
            }
            void set_texture_path (const std::string &texture_path) {
                texture_path_ = texture_path;
            }

        protected:
            std::string texture_path_;
    };
#endif