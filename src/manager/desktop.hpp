#include "manager.hpp"


class Desktop_Manager : public Manager {

    public:

        Desktop_Manager (Widget *parent) :
            Manager (parent)
        {
            Logger::Instance()->log (__PF);
        }

        ~Desktop_Manager () {
            Logger::Instance()->log (__PF);
        }

        void controller (Abstract_Cmd &cmd) override {
            Logger::Instance()->log (__PF);

            switch (cmd.action ()) {

                case ACTIONS::RETRIEVE_FROM_FILE:
                    send_cmd_down (cmd);
                break;

                case ACTIONS::SAVE_TO_FILE:
                    send_cmd_down (cmd);
                break;
                
                default:
                break;
            }
        }
};
