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

            virtual void action () = 0;
            
            bool on_click (int x, int y) {
                if (check_bound (x, y)) {
                    action ();
                    return true;
                }

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