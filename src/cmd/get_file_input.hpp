#ifndef GET_FILE_INPUT_HPP
#define GET_FILE_INPUT_HPP

#include "../widget/text_form.hpp"

class Get_File_Input : public Abstract_Cmd {

    public:
        Get_File_Input (void *parent, std::string *file_name) :
            Abstract_Cmd (parent, ACTIONS::GET_FILE_INPUT, nullptr), file_name_ (file_name)
        {
            Logger::Instance()->log (__PF);

        }

        void execute (Widget *argument) override {
            Logger::Instance()->log (__PF);

            Text_Form *text_form = dynamic_cast <Text_Form *> (argument);
            if (text_form) {
                
            }else {
                Logger::Instance () -> log (__PF, LOG_LVL::FATAL, "unable to convert to manager");
                std::terminate ();
            }            
            *file_name_ = text_form -> get_message ();
        }

    private:
        std::string *file_name_ = nullptr;
};

#endif