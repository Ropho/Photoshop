#include "manager.hpp"
#include "../canvas/canvas.hpp"

class Canvas_Man : public Manager {

    public:

        Canvas_Man (Widget *parent) :
            Manager (parent)
        {
            Logger::Instance()->log(__PF);
        }

        ~Canvas_Man () {
            Logger::Instance()->log(__PF);
        }

        void controller (const Abstract_Cmd &cmd) {
            switch (cmd.action ()) {
                case ACTIONS::CHANGE_BACKGROUND:
                    cmd.execute (canvas_);
                break;

                default:
                break;
            }
        }
        // void controller (Cmd cmd) override {

        //     switch (cmd.type ()) {

        //         case COLOR: {
        //             switch (cmd.action ()) {

        //             case ACTIONS::CHANGE_BACKGROUND: {

        //                     GLUT::Color param;
        //                     cmd.param (static_cast <void *> (&param));
        //                     canvas_->change_background (param);
        //                 }break;

        //                 default: {
        //                 }break;
        //             }
        //         }break;

        //         case POINT: {
        //             switch (cmd.action ()) {

        //                 case ACTIONS::USE_TOOL: {
        //                     // logger.log (__PF);
        //                         send_cmd_up (cmd);
                            
        //                     // parent_ -> controller (cmd);
        //                 }break;

        //                 default: {
        //                 }break;
        //             }
        //         }break;

        //         case NULLPTR: {
        //             switch (cmd.action ()) {

        //                 case ACTIONS::DRAW_CANVAS: {
        //                     // logger.log (__PF);

        //                     send_cmd_up (cmd);
        //                     // parent_ -> controller (cmd);
        //                 }break;

        //                 default: {
        //                 }break;
        //             }

        //         }break;

        //         case ENTITY_PTR: {
        //             switch (cmd.action ()) {

        //                 case ACTIONS::ADD_ENTITY: {
        //                     // if (cmd.from () != parent_)
        //                         send_cmd_up (cmd);
        //                     // fprintf (stderr, "CANVAS MAN: %x FROM %x\n", this, cmd.from ());
        //                     // logger.log (__PF);
        //                 }break;

        //                 default: {
        //                 }break;
        //             }
        //         }break;

        //         case ENTITY_PTR_PTR: {
        //             switch (cmd.action ()) {
        //                 case ACTIONS::GET_ENTITY_CANVAS: {
                            
        //                     // logger.log (__PF);
        //                     send_cmd_up (cmd);
        //                 }break;

        //                 default: {
        //                 }break;
        //             }

        //         }break;

        //         default:
        //         break;
        //     }
        // }

        void add (Widget *entity) override {
            if (canvas_ == nullptr) {
                canvas_ = dynamic_cast <Canvas *> (entity);
            }
            arr.push_back (entity);
        }

        // Widget* canvas () {
            // return canvas_;
        // }

        private:
            Canvas *canvas_ = nullptr;
};
