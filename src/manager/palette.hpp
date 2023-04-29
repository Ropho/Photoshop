// #include "manager.hpp"


class Palette : public Manager {

    public:

        Palette (Widget *parent) :
            Manager (parent)
        {
            Logger::Instance()->log (__PF);
        }

        ~Palette () {
            Logger::Instance()->log (__PF);
        }

        void controller (Abstract_Cmd &cmd) override {
            Logger::Instance()->log (__PF);

            switch (cmd.action ()) {

                case ACTIONS::CHANGE_BACKGROUND :
                    send_cmd_down (cmd);
                break;

                case ACTIONS::START_USE_CURRENT_TOOL:
                    send_cmd_down (cmd);
                break;

                case ACTIONS::USE_CURRENT_TOOL:
                    send_cmd_down (cmd);
                break;

                case ACTIONS::END_USE_CURRENT_TOOL:
                    send_cmd_down (cmd);
                break;

                default:
                break;
            }
        }

        // void controller (Cmd cmd) override {
        //     switch (cmd.type ()) {
                
        //         case POINT: {
        //             switch (cmd.action ()) {

        //                 case ACTIONS::USE_TOOL: {
        //                         send_cmd_down (cmd);
        //                 }break;

        //                 default: {
        //                 }break;
        //             }

        //         }break;

        //         case COLOR: {

        //             switch (cmd.action ()) {
        //                 case ACTIONS::CHANGE_BACKGROUND: {
        //                         // logger.log (__PF);
        //                         send_cmd_down (cmd);
        //                     }break;
                        
        //                     default: {
        //                     }break;
        //                 }
        //             }break;

        //         case ENTITY_PTR: {
        //             switch (cmd.action ()) {

        //                 case ACTIONS::ADD_ENTITY: {
        //                     // logger.log (__PF);
        //                     // fprintf (stderr, "AFTER \n");
        //                     // std::terminate ();
        //                     send_cmd_down (cmd);
        //                 }break;

        //                 default: {
        //                 }break;
        //             }
        //         }break;

        //         case ENTITY_PTR_PTR: {
        //             switch (cmd.action ()) {

        //                 case ACTIONS::GET_ENTITY_CANVAS: {
                            
        //                     send_cmd_down (cmd);
        //                     // logger.log (__PF);
        //                 }break;

        //                 default: {
        //                 }break;
        //             }
        //         }break;

        //         case NULLPTR: {
        //             switch (cmd.action ()) {

        //                 case ACTIONS::DRAW_CANVAS: {
        //                     // logger.log (__PF);

        //                     send_cmd_down (cmd);
        //                 }break;

        //                 default: {
        //                 }break;
        //             }
        //         }break;

        //         default: {
        //         }break;
        //     }
        // }

};
