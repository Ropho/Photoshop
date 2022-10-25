#ifndef MANAGER_HPP
#define MANAGER_HPP


#include "../class_widget/widget.hpp"
#include "../general.hpp"
#include "../class_vector/vector.hpp"
#include "../class_canvas/canvas.hpp"
#include "../class_button/button.hpp"


class Manager : public Widget {

    public:

        Manager (Widget * parent) :
            Widget (parent)
            {}

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

    protected:
        vector <Widget *> arr {};
        // std::vector <Widget *> arr {};
        // Widget *kek [100];


};



class Painter : public Manager {

    public:

        Painter (Widget *parent) :
            Manager (parent) 
        {
            LOG;
        }

        ~Painter () {
            LOG;
        }

        void controller (const Cmd <int> & cmd) {

            switch (cmd.action ()) {

                case ACTIONS::SET_COLOR: {
                    canvas_->set_color (cmd.param ());
                }break;

                default: {
                }break;
            }
        }

        void add_canvas (Widget *canvas) {
            canvas_ = (Canvas *)canvas;
        }


        private:
            Canvas *canvas_ = nullptr;
};


#endif