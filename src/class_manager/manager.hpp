#ifndef MANAGER_HPP
#define MANAGER_HPP


#include "../class_widget/widget.hpp"
#include "../general.hpp"
#include "../class_vector/vector.hpp"
#include "../class_canvas/canvas.hpp"
#include "../class_button/button.hpp"


class Manager : public Widget {

    public:
        // Manager (size_t cap) :
        //     arr (cap)
        //     {}

        ~Manager () {
            LOG;
            clear ();
        }

        void add (Widget *widget) {
            arr.push_back (widget);
        }
        
        
        void clear () {
            arr.clear ();
        }


/////////////////////////////////////////////////VIRTUAL

        bool on_click (int x, int y) {
            for (int i = (int) arr.size () - 1; i >= 0; --i)
                if (arr[i]->on_click (x, y))
                    return true;
            
            return false;
        }

        void draw () {
            for (size_t i = 0; i < arr.size (); ++i)
                arr[i]->draw ();
        }

    private:
        // vector <Widget *> arr {};
        std::vector <Widget *> arr {};
        // Widget *kek [100];


};


#endif