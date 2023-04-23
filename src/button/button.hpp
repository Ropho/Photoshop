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


    // class Tool_Button : public Abstract_Button {

    //     public:
    //         Tool_Button (Coords coords, Widget* ptr, Tool* tool) :
    //             Abstract_Button (coords, ptr), 
    //             tool_ (tool)
    //         {
    //             logger.log (__PF);
    //         }

    //         ~Tool_Button () {
    //             logger.log (__PF);
    //             delete tool_;
    //         }

    //         void action () override {
    //             if (!active_) {
    //                 logger.log (__PF);
    //                 active_ = true;
    //                 NEW_CMD (ACTIONS::SET_CURRENT, TOOL_PTR, this, tool_, Tool*);
    //                 parent_ -> controller (cmd);
    //                 END_CMD;
    //             }
    //             else {
    //                 active_ = false;
    //                 NEW_CMD (ACTIONS::REMOVE_CURRENT, NULLPTR, this, nullptr, nullptr_t);
    //                 parent_ -> controller (cmd);
    //                 END_CMD;
    //             }
    //         }

    //         void draw () {
    //             draw_border ();
    //             gl.draw_palette_caller (coords_.strt (), coords_.width (), coords_.height (), tool_->name ());
    //         }

    //     protected:
    //         Tool *tool_ = nullptr;
    // };

    // class Color_Changer_Activator : public Abstract_Button {

    //     public:
    //         Color_Changer_Activator (Coords coords, Widget* ptr) :
    //             Abstract_Button (coords, ptr)
    //         {
    //             logger.log (__PF);
    //         }

    //         ~Color_Changer_Activator () {
    //             logger.log (__PF);
    //         }

    //         void action () {
    //             logger.log (__PF);

    //             if (!active_) {
    //                 NEW_CMD (ACTIONS::ACTIVATE, NULLPTR, this, nullptr, nullptr_t);
    //                 parent_ -> controller (cmd);
    //                 END_CMD;
    //             }
    //             else {
    //                 NEW_CMD (ACTIONS::DEACTIVATE, NULLPTR, this, nullptr, nullptr_t);
    //                 parent_ -> controller (cmd);
    //                 END_CMD;
    //             }
    //         }

    //         void draw () {
    //                 if (active_)
    //                     draw_border ();
    //                 gl.draw_color_changer (coords_.strt (), coords_.width (), coords_.height (), GLUT::BLUE);
    //         }
    // };

    // class Tool_Color_Changer : public Abstract_Button {
    //     public:
    //         Tool_Color_Changer (Coords coords, Widget* ptr, GLUT::Color color) :
    //             Abstract_Button (coords, ptr),
    //             color_  (color)
    //         {
    //             logger.log (__PF);
    //         }

    //         ~Tool_Color_Changer () {
    //             logger.log (__PF);
    //         }

    //         void action () {
    //             logger.log (__PF);
                
    //             NEW_CMD (ACTIONS::CHANGE_TOOL_COLOR, COLOR, this, color_, GLUT::Color);
    //             parent_ -> controller (cmd);
    //             END_CMD;
    //         }

    //         void draw () override {
    //             if (active_) {
    //                 draw_border ();
    //                 gl.draw_color_changer (coords_.strt (), coords_.width (), coords_.height (), color_);
    //             }
    //         }

    //     private:
    //         GLUT::Color color_ = GLUT::WHITE;
    // };
 
#endif