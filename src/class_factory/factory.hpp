#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "../class_canvas/canvas.hpp"
#include "../class_button/button.hpp"
#include "../class_vector/vector.hpp"


class Factory {

    public:
        
        Factory () {
            LOG;
        }

        ~Factory () {
            for (int i = 0; i < widgets.size (); ++i)
                delete widgets[i];
        }

        Widget * make_widget () {

        }


    private:

        vector <Widget*> widgets {};
};

#endif