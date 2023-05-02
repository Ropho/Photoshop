#ifndef FILE_BUTTON_MANAGER_HPP
#define FILE_BUTTON_MANAGER_HPP

#include "../manager/manager.hpp"
#include "../widget/text_form.hpp"

class File_Button_Manager : public Manager {

    public:

        File_Button_Manager (Widget *parent) :
            Manager (parent)
        {
            Logger::Instance()->log (__PF);
        }

        ~File_Button_Manager () {
            Logger::Instance()->log (__PF);
        }

        void controller (Abstract_Cmd &cmd) override {
            Logger::Instance()->log (__PF);

            switch (cmd.action ()) {
                case ACTIONS::ACTIVATE:
                    cmd.execute (this);
                break;

                case ACTIONS::DEACTIVATE:
                    cmd.execute (this);
                break;

                case ACTIONS::RETRIEVE_FROM_FILE:
                    send_cmd_up (cmd);
                break;

                case ACTIONS::SAVE_TO_FILE:
                    send_cmd_up (cmd);
                break;

                case ACTIONS::GET_FILE_INPUT:
                    cmd.execute (text_form_);
                break;
                
                default:
                break;
            }
        }
        
        void add (Widget *entity) override {
            if (text_form_ == nullptr) {
                text_form_ = dynamic_cast <Text_Form *> (entity);
            }

            Manager::add (entity);
        }

    private:
        Text_Form *text_form_ = nullptr;
};


#endif