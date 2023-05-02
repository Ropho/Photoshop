#ifndef FILE_PANEL_TEXT_BUTTON_HPP
#define FILE_PANEL_TEXT_BUTTON_HPP

#include "panel_text.hpp"
#include "../cmd/file_info_canvas.hpp"

    class Open_File_Button : public Panel_Text {

        public:
            Open_File_Button (Coords coords, Widget* ptr, const GLUT::Color& color, const std::string &message) :
                Panel_Text (coords, ptr, color, message)
            {
                Logger::Instance () -> log (__PF);
                init ();
            }

            ~Open_File_Button () {
                Logger::Instance () -> log (__PF);
            }
            
            void draw () override {
                if (active_) {
                    Panel_Text::draw ();
                }
            }

            void action_on_mouse_press () override {
                Logger::Instance () -> log (__PF);

                if (!active_) {
                }
                else {


                    Get_File_Input cmd_get (this, &file_name_);
                    Manager * man = dynamic_cast <Manager *> (parent_);
                    if (man)
                        man -> controller (cmd_get);
                    else {
                        Logger::Instance ()-> log (__PF, 2, "unable to convert to manager\n");
                        std::terminate ();
                    }

                    Retrieve_From_File cmd_save (this, file_name_);
                    man -> controller (cmd_save);

                    Deactivate cmd_deactivate (this);
                    man -> controller (cmd_deactivate);

                }
            }

            void action_on_mouse_release () override {}

        private:
            std::string file_name_;
    };

    class Save_File_Button : public Panel_Text {

        public:
            Save_File_Button (Coords coords, Widget* ptr, const GLUT::Color& color, const std::string &message) :
                Panel_Text (coords, ptr, color, message)
            {
                Logger::Instance () -> log (__PF);
                init ();
            }

            ~Save_File_Button () {
                Logger::Instance () -> log (__PF);
            }
            
            void draw () override {
                if (active_) {
                    Panel_Text::draw ();
                }
            }

            void action_on_mouse_press () override {
                Logger::Instance () -> log (__PF);

                if (!active_) {
                }
                else {
                    Get_File_Input cmd_get (this, &file_name_);


                    Manager * man = dynamic_cast <Manager *> (parent_);
                    if (man)
                        man -> controller (cmd_get);
                    else {
                        Logger::Instance ()-> log (__PF, 2, "unable to convert to manager\n");
                        std::terminate ();
                    }

                    Save_To_File cmd_retrieve (this, file_name_);
                    man -> controller (cmd_retrieve);

                    Deactivate cmd_deactivate (this);
                    man -> controller (cmd_deactivate);

                }
            }

            void action_on_mouse_release () override {}

        private:
            std::string file_name_;
    };

#endif