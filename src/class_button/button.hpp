#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "../log/log.hpp"
#include "../class_widget/widget.hpp"

    class Abstract_Button : public Widget {

        public:

            Abstract_Button (Coords coords, Widget *parent) :
                Widget (coords, parent)
            {
                logger.log (__PF);
            }

            virtual ~Abstract_Button () {
                logger.log (__PF);
            }

            virtual void action () = 0;
            
            void draw_border () {
                gl.draw_border (coords_.strt (), coords_.width (), coords_.height ());
            }

            bool on_click (int x, int y) {

                if (check_bound (x, y)) {
                    action ();
                    return true;
                }

                return false;
            }

        private:

    };


    // // template <typename T>
    // class Caller : public Abstract_Button {

    //     public:
    //         Changer (Coords coords, Widget *parent) :
    //             Abstract_Button (coords, parent)
    //         {
    //             LOG;
    //         }

    //         ~Changer () {
    //             LOG;
    //         }
    // };


    class Color_Changer : public Abstract_Button {

        public:
            Color_Changer (Coords coords, Widget* ptr, int color) :
                Abstract_Button (coords, ptr),
                color_  (color)
            {
                logger.log (__PF);
            }

            ~Color_Changer () {
                logger.log (__PF);
            }

            void action () {
                NEW_CMD (ACTIONS::CHANGE_BACKGROUND, INT, this, color_, int);
                // std::cout << *(static_cast <int *> (cmd.param ()));
                // Cmd <int> cmd (ACTIONS::CHANGE_BACKGROUND, this, color_);
                parent_ -> controller (cmd);
                END_CMD;
            }

            void draw () {
                draw_border ();
                gl.draw_color_changer (coords_.strt (), coords_.width (), coords_.height (), color_);
            }
            

        private:
            int color_ = GLUT::WHITE;
    };


    class Palette_Caller : public Abstract_Button {

        public:
            Palette_Caller (Coords coords, Widget* ptr, int tool_name) :
                Abstract_Button (coords, ptr), tool_name_ (tool_name)
            {
                logger.log (__PF);
            }

            ~Palette_Caller () {
                logger.log (__PF);
            }

            void action () {
                
                if (!active_) {
                    active_ = true;
                    NEW_CMD (ACTIONS::SET_CURRENT, INT, this, tool_name_, int);
                    // Cmd <int> cmd (ACTIONS::SET_CURRENT, static_cast <void *> (this), tool_name_);
                    parent_ -> controller (cmd);
                    END_CMD;
                }
                else {
                    active_ = false;
                    NEW_CMD (ACTIONS::REMOVE_CURRENT, INT, this, tool_name_, int);

                    // Cmd <int> cmd (ACTIONS::REMOVE_CURRENT, static_cast <void *> (this), tool_name_);
                    parent_ -> controller (cmd);
                    END_CMD;
                }
            }

            void draw () {
                draw_border ();
                gl.draw_palette_caller (coords_.strt (), coords_.width (), coords_.height (), tool_name_);
            }


        private:
            bool active_ = false;
            int tool_name_ = 0;
    };


#endif