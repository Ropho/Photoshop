#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "../class_canvas/canvas.hpp"
#include "../class_button/button.hpp"
#include "../class_vector/vector.hpp"
#include "../class_manager/manager.hpp"


class Factory {

    public:
        
        Factory () {
            LOG;
        }

        ~Factory () {
            for (size_t i = 0; i < widgets.size (); ++i)
                delete widgets[i];
        }

        void add_in_parent (Widget *parent, Widget *obj) {

            if (parent != nullptr) {
                parent->add (obj);
            }
        }

        Widget * make_manager (Widget *parent) {
            
            Widget *manager = new Manager (parent);
            
            add_in_parent (parent, manager);

            widgets.push_back (manager);

            return manager;
        }

        Widget * make_painter (Widget *parent) {
            
            Widget *painter = new Painter (parent);
            
            add_in_parent (parent, painter);

            widgets.push_back (painter);

            return painter;
        }

        Widget * make_canvas (Coords coords, Widget *parent) {
            
            Widget *canvas = new Canvas (coords, parent);
            
            add_in_parent (parent, canvas);
            ((Painter *)parent) -> add_canvas (canvas);
            // add_in_parent (parent, manager);

            widgets.push_back (canvas);

            return canvas;
        }

        Widget * make_color_changer (Coords coords, Widget *parent, GLUT::COLORS color) {

            Widget *button   = new Button::Color_Changer (coords, parent, color);

            add_in_parent (parent, button);

            widgets.push_back (button);

            return button;
        }


    private:

        vector <Widget*> widgets {};
};

#endif