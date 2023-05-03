#ifndef ABSTRACT_TOOL_HPP
#define ABSTRACT_TOOL_HPP

#include "../widget/widget.hpp"


enum class TOOLS {
    NO_TOOL = 0,
    PENCIL  = 1,
    ERASER  = 2,
};

class Abstract_Tool {

    public:

        Abstract_Tool (Widget *parent, TOOLS tool, Widget *use_instance) :
            parent_ (parent), tool_ (tool), use_instance_ (use_instance)
        {
            Logger::Instance() -> log (__PF);
        }

        virtual ~Abstract_Tool () {
            Logger::Instance() -> log (__PF);
        }

        virtual void start_action (void *param) = 0;        
        virtual void end_action   (void *param) = 0;        
        virtual void action (void *param)  = 0;
        void set_color (const GLUT::Color& color) {
            color_ = color;
        }

        bool mouse_button_pressed () {return mouse_button_pressed_;}
        void mouse_button_press () {mouse_button_pressed_ = true;}
        void mouse_button_release () {mouse_button_pressed_ = false;}

        virtual void set_param (void *) = 0;

        TOOLS tool () {
            return tool_;
        }

        void set_parent (Widget *parent){
            parent_ = parent;
        }
        
        Widget *from () {
            return parent_;
        }

        protected:
            bool mouse_button_pressed_ = false;

            Widget *parent_ = nullptr;
            TOOLS tool_ = TOOLS::NO_TOOL;
            Widget *use_instance_ = nullptr;

            GLUT::Color color_ = GLUT::Color::Black;

};


#endif