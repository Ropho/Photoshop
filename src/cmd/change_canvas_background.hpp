#ifndef CHANGE_CANVAS_BACKGROUND_HPP
#define CHANGE_CANVAS_BACKGROUND_HPP

#include "cmd.hpp"
#include "../widget/canvas.hpp"

class Change_Canvas_Background : public Abstract_Cmd {

    public:
        Change_Canvas_Background (void *parent, GLUT::Color color) :
            Abstract_Cmd (parent, ACTIONS::CHANGE_BACKGROUND, nullptr), color_ (color)
        {
            Logger::Instance()->log (__PF);

        }

        void execute (Widget *argument) override {
            Logger::Instance()->log (__PF);
            Canvas *canvas = dynamic_cast <Canvas *> (argument);
            if (canvas == nullptr) {
                Logger::Instance()->log (__PF, LOG_LVL::FATAL, "not canvas given =(");                
                std::terminate ();
            }
            canvas -> update_background (color_);
        }

    private:
        GLUT::Color color_;
};


#endif