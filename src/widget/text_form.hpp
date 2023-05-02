#ifndef TEXT_FORM_HPP
#define TEXT_FORM_HPP

#include "widget.hpp"

    class Text_Form : public Widget {

    public:
        Text_Form (const Coords &coords, Widget *parent) :
            Widget (coords, parent)
            {
                Logger::Instance()->log (__PF);

                init ();
            }

        void init () override {
            text_form_ = GLUT::GL::Instance () -> init_text_form (coords_, message_);
        }

        bool on_mouse_release (int x, int y) override {return false;}
        bool on_mouse_press (int x, int y) override {return false;}
        bool on_mouse_move  (int x, int y) override {return false;}
        
        bool on_text_entered (uint32_t unicode) override {
            Logger::Instance () -> log (__PF, 2, "ON TEXT ENTERED");
            if (active_) {

                if (unicode == 8) {   // Delete key
                    message_ = message_.substr(0, message_.size() - 1);
                }
                else if (message_.size() < size_) {
                    message_ += unicode;
                }
                std::cerr<<message_<<"\n";
                return true;
            }
            return false;
        }

       void draw () override {
            if (active_) {
                GLUT::GL::Instance () -> draw_text_form (text_form_, message_);
            }
        }

        const std::string& get_message () const {return message_;}
    private:
        GLUT::Entity text_form_;
        const size_t size_ = 9;
        std::string message_;
    };



#endif