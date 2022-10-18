#ifndef MANAGER_HPP
#define MANAGER_HPP


#include "../class_widget/widget.hpp"
#include "../general.hpp"
#include "../class_vector/vector.hpp"

class Manager {

    public:
        Manager (size_t cap) :
            arr (cap)
            {}


        void add (Widget *widget) {
            arr.push_back (widget);
        }
        
        
        void clear () {
            arr.clear ();
        }


        void draw_all () {
            for (size_t i = 0; i < arr.size (); ++i)
                arr[i]->draw ();
        }


    private:
        vector <Widget *> arr {};


};


#endif