#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "../class_widget/widget.hpp"
#include "../general.hpp"

namespace Button {
        

    class Abstract_Button : public Widget {

        public:

            Abstract_Button (Point start, int width, int height) :
                Widget (start, width, height)
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
    class Shower : public Abstract_Button {

        public:
            Shower (Point start, int width, int height, T val) :
                Abstract_Button (start, width, height),
                val_ (val)
            {
                LOG;
            }


            ~Shower () {
                LOG;
            }

            void action () {
                // gl.show ();
            }

            void draw () {

            }

            void on_click () {

                action ();
            }

        private:

            T val_ = NULL;
    };


    template <typename T>
    class Changer : public Abstract_Button {

        public:
            Changer (Point start, int width, int height, T* ptr) :
                Abstract_Button (start, width, height),
                ptr_ (ptr)
            {
                LOG;
            }

            enum ACTIONS {

                SET = 1,
                ADD = 2,
                MUL = 3,
                DEL = 4,
                ERASE = 5,
                
            };


            ~Changer () {
                LOG;
            }

            // void action (ACTIONS act) {
            //     *ptr_ = 100;
            // }

            // void draw () {
            //     gl.draw_ ();
            // }

            // void on_click () {

            //     action ();
            // }

        protected:
            T* ptr_ = nullptr;
    };


    class Color_Changer : public Changer <int> {

        public:
            Color_Changer (Point start, int width, int height, int* ptr, int color) :
                Changer (start, width, height, ptr),
                color_ (color)
            {
                LOG;
            }

            ~Color_Changer () {
                LOG;
            }

            void action () {
                *ptr_ = color_;
            }

            void draw () {
                gl.draw_color_changer (start_, width_, height_, color_);
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