#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "../general.hpp"
#include "../class_widget/widget.hpp"
#include "../class_cmd/cmd.hpp"

namespace Button {


    class Abstract_Button : public Widget {

        public:

            Abstract_Button (Coords coords, Widget *parent) :
                Widget (coords, parent)
            {
                LOG;
            }

            virtual ~Abstract_Button () {
                LOG;
            }

            virtual void action () = 0;

        private:

    };


    template <typename T>
    class Changer : public Abstract_Button {

        public:
            Changer (Coords coords, Widget *parent) :
                Abstract_Button (coords, parent)
            {
                LOG;
            }

            ~Changer () {
                LOG;
            }
    };


    class Color_Changer : public Changer <Widget> {

        public:
            Color_Changer (Coords coords, Widget* ptr, int color) :
                Changer (coords, ptr),
                color_  (color)
            {
                LOG;
            }

            ~Color_Changer () {
                LOG;
            }

            void action () {
                Cmd <int> cmd (ACTIONS::SET_COLOR, color_);
                parent_ -> controller (cmd);
            }

            void draw () {
                gl.draw_color_changer (coords_.strt (), coords_.width (), coords_.height (), color_);
            }
            
            bool on_click (int x, int y) {

                if (check_bound (x, y)) {
                    action ();
                    return true;
                }

                return false;
            }

        private:
            int color_ = GLUT::WHITE;
    };

}


#endif