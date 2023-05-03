#ifndef PENCIL_HPP
#define PENCIL_HPP

#include "tool.hpp"
#include "../widget/canvas.hpp"

class Pencil : public Abstract_Tool {

    public:
        Pencil (Widget *parent, Widget *use_instance) :
            Abstract_Tool (parent, TOOLS::PENCIL, use_instance)
        {
            Logger::Instance() -> log (__PF);
            
            if (dynamic_cast <Canvas *> (use_instance_) == nullptr) {
                std::terminate ();
            }
        }

        ~Pencil () {
            Logger::Instance() -> log (__PF);
        }

        void set_param (void *param) override {
            Canvas_Param *params = static_cast <Canvas_Param *> (param);
            pnt_ = params->pnt;
        }

        void start_action (void *param) override {
            Logger::Instance() -> log (__PF);
            
            mouse_button_press ();

            action (param);
        }

        void action (void *param) {
            
            if (mouse_button_pressed ()) {

                set_param (param);
                
                Canvas *canvas = dynamic_cast <Canvas *> (use_instance_);

                if (canvas == nullptr) {
                    Logger::Instance() -> log (__PF, LOG_LVL::FATAL, "cant convert to canvas type");  
                    std::terminate ();
                } 

                canvas -> init_dot (pnt_, color_);
                
            }
        }
        void end_action (void *param) override {
            mouse_button_release ();
        }

    private:
        Point pnt_;
};

#endif