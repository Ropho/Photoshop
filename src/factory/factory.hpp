#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "../canvas/canvas.hpp"
#include "../button/button.hpp"
#include "../../lib/vector/vector.hpp"
#include "../manager/manager.hpp"
#include "../store/store.hpp"
#include "../widget/background.hpp"

class Factory {

    public:
        Factory () {
            logger.log (__PF);
        }
        ~Factory () {
            logger.log (__PF);
            // for (size_t i = 0; i < widgets.size (); ++i)
                // delete widgets[i];
        }
        void add_in_parent (Widget *parent, Widget *obj) {

            if (parent != nullptr) {
                auto manager = dynamic_cast <Manager *> (parent);
                if (manager != nullptr)
                    manager->add (obj);
                else {
                    logger.log (__PF, CRITICAL, "UNABLE TO CONVERT TO MANAGER");
                    std::terminate ();
                }
            }
        }
/////////////////////////////////////////////////MANAGERS
        Widget* make_desktop (Widget *parent) {
            
            Widget *manager = new Manager (parent);            
            add_in_parent (parent, manager);

            return manager;
        }

        Widget *make_palette (Widget *parent) {

            Widget *palette = new Palette (parent);
            add_in_parent (parent, palette);

            return palette;
        }

        Widget *make_store (Widget *parent) {
            Widget *store = new Store (parent);
            add_in_parent (parent, store);
            return store;
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
/////////////////////////////////////////////////WIDGETS
        Widget *make_canvas (Coords coords, Widget *parent) {

            Widget *canvas = new Canvas (coords, parent);
            
            add_in_parent (parent, canvas);
            return canvas;
        }

        Widget * make_color_changer (Coords coords, Widget *parent, GLUT::Color color) {

            Widget *button   = new Color_Changer (coords, parent, color);
            add_in_parent (parent, button);

            return button;
        }
        Widget * make_tool_color_changer (Coords coords, Widget *parent, GLUT::Color color) {

            Widget *button   = new Tool_Color_Changer (coords, parent, color);
            add_in_parent (parent, button);

            return button;
        }

        Widget * make_color_changer_activator (Coords coords, Widget *parent) {

            Widget *button   = new Color_Changer_Activator (coords, parent);
            add_in_parent (parent, button);

            return button;
        }

        Widget *make_pencil (Coords coords, Widget *parent) {

            Tool   *tool   = new Pencil;
            Widget *button = new Tool_Button (coords, parent, tool);

            add_in_parent (parent, button);

            return button;
        }
        Widget *make_background (Widget *parent, const GLUT::Color& color) {

            Widget *back = new background::Background (parent, color);
            add_in_parent (parent, back);
            return back;
        }
    };

#endif