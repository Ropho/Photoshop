#ifndef MANAGER_HPP
#define MANAGER_HPP


// #include "../class_widget/widget.hpp"
#include "../general.hpp"
#include "../class_vector/vector.hpp"
#include "../class_canvas/canvas.hpp"


class Manager {

    public:
        // Manager (size_t cap) :
        //     arr (cap)
        //     {}

        ~Manager () {
            LOG ("MANAGER ()");
            clear ();
        }

        void add (Widget *widget) {

            arr.push_back (widget);
            // Canvas canvas ({100, 100}, 100, 100);
            // Widget *ptr = &canvas;
            // int keke = 1;
            // arr.push_back (&canvas);
            // kek[0] = widget;
            // kek[0]->draw ();
            // widget->draw ();
        }
        
        
        void clear () {
            arr.clear ();
        }


        void draw_all () {
            for (size_t i = 0; i < arr.size (); ++i)
                arr[i]->draw ();
        }


    private:
        // vector <Widget *> arr {};
        std::vector <Widget *> arr {};
        Widget *kek [100];


};


#endif