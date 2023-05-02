#ifndef CANVAS_FILE_INFO_HPP
#define CAVNAS_FILE_INFO_HPP

#include "../widget/canvas.hpp"

class Save_To_File : public Abstract_Cmd {

    public:
        Save_To_File (void *parent, const std::string &file_name) :
            Abstract_Cmd (parent, ACTIONS::SAVE_TO_FILE, nullptr), file_name_ (file_name)
        {
            Logger::Instance()->log (__PF);

        }

        void execute (Widget *argument) override {
            Logger::Instance()->log (__PF);

            Canvas *canvas = dynamic_cast <Canvas *> (argument);
            if (canvas) {
                
            }else {
                Logger::Instance () -> log (__PF, 2, "unable to convert to canvas");
                std::terminate ();
            }            
            canvas -> save_to_file (file_name_);
        }

    private:
        std::string file_name_;
};

class Retrieve_From_File : public Abstract_Cmd {

    public:
        Retrieve_From_File (void *parent, const std::string &file_name) :
            Abstract_Cmd (parent, ACTIONS::RETRIEVE_FROM_FILE, nullptr), file_name_ (file_name)
        {
            Logger::Instance()->log (__PF);

        }

        void execute (Widget *argument) override {
            Logger::Instance()->log (__PF);

            Canvas *canvas = dynamic_cast <Canvas *> (argument);
            if (canvas) {
                
            }else {
                Logger::Instance () -> log (__PF, 2, "unable to convert to canvas");
                std::terminate ();
            }            
            canvas -> retrieve_from_file (file_name_);
        }

    private:
        std::string file_name_;
};


#endif