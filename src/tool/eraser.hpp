#ifndef ERASER_HPP
#define ERASER_HPP

#include "tool.hpp"
#include "../widget/canvas.hpp"

class Eraser : public Abstract_Tool {

    public:
        Eraser (Widget *parent, Widget *use_instance) :
            Abstract_Tool (parent, TOOLS::PENCIL, use_instance)
        {
            Logger::Instance() -> log (__PF);
            
            if (dynamic_cast <Canvas *> (use_instance_) == nullptr) {
                std::terminate ();
            }
        }

        ~Eraser () {
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
        void action (void *param) override {

            if (mouse_button_pressed ()) {
                set_param (param);
                
                Canvas *canvas = dynamic_cast <Canvas *> (use_instance_);

                if (canvas == nullptr) {
                    Logger::Instance() -> log (__PF, 2, "cant convert to canvas type");  
                    std::terminate ();
                } 

                std::vector <GLUT::Entity> &entities = canvas -> get_entities ();
                
                for (int i = entities.size () - 1; i >= 0; i--) {            
                    if (entities[i].info.bounds.contains (pnt_.get_x (), pnt_.get_y ())) {
                        entities.erase (entities.begin () + i);
                        break;
                    }                
                }
                
            }
        }
        void end_action (void *param) override {}
 
    private:
        Point pnt_;
};

#endif