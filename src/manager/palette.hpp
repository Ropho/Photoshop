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

                case ACTIONS::SAVE_TO_FILE:
                    send_cmd_down (cmd);
                break;

                case ACTIONS::RETRIEVE_FROM_FILE:
                    send_cmd_down (cmd);
                break;
            
                default:
                break;
            }
        }
};
