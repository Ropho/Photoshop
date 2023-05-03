#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "../../lib/vector/vector.hpp"

#include "../manager/manager.hpp"
#include "../manager/palette.hpp"
#include "../manager/tool.hpp"
#include "../manager/canvas.hpp"
#include "../manager/color.hpp"
#include "../manager/file_button.hpp"
#include "../manager/desktop.hpp"

#include "../button/canvas_background_changer.hpp"
#include "../button/color_changer_activator.hpp"
#include "../button/tool_color_changer.hpp"
#include "../button/tool.hpp"
#include "../button/panel_text.hpp"
#include "../button/file_panel_text.hpp"

#include "../tool/pencil.hpp"
#include "../tool/eraser.hpp"

#include "../widget/background.hpp"
#include "../widget/text_form.hpp"


class Factory {

    public:
        static Factory *Instance () {
            if (!instance_) {
                instance_ = new Factory {};
            }
            return instance_;
        }

    protected:
        
        Factory () {
            Logger::Instance()->log (__PF);
        }
        ~Factory () {
            Logger::Instance()->log (__PF);
        }
    
    public:
        
        void add_in_parent (Widget *parent, Widget *obj) {

            if (parent != nullptr) {
                auto manager = dynamic_cast <Manager *> (parent);
                if (manager != nullptr)
                    manager->add (obj);
                else {
                    Logger::Instance()->log (__PF, LOG_LVL::FATAL, "UNABLE TO CONVERT TO MANAGER");
                    std::terminate ();
                }
            }
        }
/////////////////////////////////////////////////MANAGERS
        Widget* make_desktop (Widget *parent) {
            
            Widget *manager = new Desktop_Manager (parent);            
            add_in_parent (parent, manager);

            return manager;
        }

        Widget *make_palette (Widget *parent) {

            Widget *palette = new Palette (parent);
            add_in_parent (parent, palette);

            return palette;
        }

        Widget *make_canvas_man (Widget *parent) {

            Widget *canvas_man = new Canvas_Man (parent);
            add_in_parent (parent, canvas_man);

            return canvas_man;
        }

        Widget *make_tool_man (Widget *parent) {

            Widget *man = new Tool_Man (parent);
            add_in_parent (parent, man);

            return man;
        }

        Widget *make_color_man (Widget *parent) {

            Widget *man = new Color_Man (parent);
            add_in_parent (parent, man);

            return man;
        }

        Widget *make_panel_man (Widget *parent) {

            Widget *man = new File_Button_Manager (parent);
            add_in_parent (parent, man);

            return man;
        }
// /////////////////////////////////////////////////WIDGETS
        Widget *make_canvas (Coords coords, GLUT::Color color, Widget *parent) {

            Widget *canvas = new Canvas (coords, color, parent);
            
            add_in_parent (parent, canvas);
            return canvas;
        }

        Widget * make_canvas_background_changer (Coords coords, Widget *parent, GLUT::Color color, const std::string& texture_path) {

            Widget *button   = new Canvas_Background_Changer (coords, parent, color, texture_path);
            add_in_parent (parent, button);

            return button;
        }

        Widget * make_tool_color_changer (Coords coords, Widget *parent, GLUT::Color color, const std::string& texture_path) {

            Widget *button   = new Tool_Color_Changer (coords, parent, color, texture_path);
            add_in_parent (parent, button);

            return button;
        }

        Widget * make_color_changer_activator (Coords coords, Widget *parent, const std::string& texture_path) {

            Widget *button   = new Color_Changer_Activator (coords, parent, texture_path);
            add_in_parent (parent, button);

            return button;
        }

        Widget *make_pencil (Coords coords, Widget *parent, Widget* canvas, const std::string& texture_path) {

            
            if (dynamic_cast <Canvas *> (canvas) == nullptr) {
                std::terminate ();
            }

            Abstract_Tool *tool  = new Pencil (nullptr, canvas);
            Widget *button = new Tool_Button (coords, parent, tool, texture_path);

            add_in_parent (parent, button);
            tool->set_parent (button);
            
            return button;
        }

        Widget *make_eraser (Coords coords, Widget *parent, Widget* canvas, const std::string& texture_path) {

            
            if (dynamic_cast <Canvas *> (canvas) == nullptr) {
                std::terminate ();
            }

            Abstract_Tool *tool  = new Eraser (nullptr, canvas);
            Widget *button = new Tool_Button (coords, parent, tool, texture_path);

            add_in_parent (parent, button);
            tool->set_parent (button);
            
            return button;
        }

        Widget *make_background (Widget *parent, const GLUT::Color& color) {

            Widget *back = new Background (parent, color);
            add_in_parent (parent, back);
            return back;
        }

        Widget *make_text_button (const Coords &coords, Widget *parent, const GLUT::Color &color, const std::string &message) {

            Widget *button = new Panel_Text (coords, parent, color, message);
            add_in_parent (parent, button);
            
            return button;
        }

        Widget *make_open_file_button (const Coords &coords, Widget *parent, const GLUT::Color &color, const std::string &message) {

            Widget *button = new Open_File_Button (coords, parent, color, message);
            add_in_parent (parent, button);
            
            return button;
        }

        Widget *make_save_file_button (const Coords &coords, Widget *parent, const GLUT::Color &color, const std::string &message) {

            Widget *button = new Save_File_Button (coords, parent, color, message);
            add_in_parent (parent, button);
            
            return button;
        }

        Widget *make_text_form (const Coords &coords, Widget *parent) {

            Widget *text_form = new Text_Form (coords, parent);
            add_in_parent (parent, text_form);
            
            return text_form;
        }

        private:
            inline static Factory *instance_ = nullptr;
    };

#endif