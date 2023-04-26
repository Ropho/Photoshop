#ifndef PENCIL_HPP
#define PENCIL_HPP

#include "tool.hpp"
#include "../canvas/canvas.hpp"

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

        void action (void *param) override {
            Logger::Instance() -> log (__PF);
            
            set_param (param);
            
            Canvas *canvas = dynamic_cast <Canvas *> (use_instance_);

            if (canvas == nullptr) {
                Logger::Instance() -> log (__PF, 2, "cant convert to canvas type");  
                std::terminate ();
            } 

            canvas -> init_dot (pnt_, color_);
        }

    private:
        Point pnt_;
};

#endif