#ifndef CHANGE_CANVAS_BACKGROUND_HPP
#define CHANGE_CANVAS_BACKGROUND_HPP

#include "cmd.hpp"
#include "../canvas/canvas.hpp"

class Change_Canvas_Background : public Abstract_Cmd {

    public:
        Change_Canvas_Background (void *parent, GLUT::Color color) :
            Abstract_Cmd (parent, ACTIONS::CHANGE_BACKGROUND, nullptr), color_ (color)
        {
            Logger::Instance()->log (__PF);

        }
// virtual void execute (Widget *argument) = 0;

        void execute (Widget *argument) override {
            Logger::Instance()->log (__PF);
            Canvas *canvas = dynamic_cast <Canvas *> (argument);
            if (canvas == nullptr) {
                Logger::Instance()->log (__PF, 2, "not canvas given =(");                
                std::terminate ();
            }
            canvas -> clear ();
            canvas->set_color (color_);
            canvas->init ();
        }

    private:
        GLUT::Color color_;
};


#endif