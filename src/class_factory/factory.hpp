#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "../class_canvas/canvas.hpp"
#include "../class_button/button.hpp"
#include "../class_vector/vector.hpp"
#include "../class_manager/manager.hpp"
#include "../store/store.hpp"

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

            // widgets.push_back (manager);

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

/////////////////////////////////////////////////WIDGETS
        Widget *make_canvas (Coords coords, Widget *parent) {

            Widget *canvas = new Canvas (coords, parent);
            
            add_in_parent (parent, canvas);
            return canvas;
        }

        Widget * make_color_changer (Coords coords, Widget *parent, GLUT::COLORS color) {

            Widget *button   = new Color_Changer (coords, parent, color);

            add_in_parent (parent, button);

            // widgets.push_back (button);

            return button;
        }

        Widget * make_palette_caller (Coords coords, Widget *parent, int name) {

            Widget *button   = new Palette_Caller (coords, parent, name);

            add_in_parent (parent, button);

            return button;
        }
    };

#endif