#ifndef WIDGET_HPP
#define WIDGET_HPP


#include "../class_point/point.hpp"
#include "../class_cmd/cmd.hpp"

class Widget {

    protected:
        Coords coords_ {{0, 0}, 0, 0};

        Widget *parent_ = nullptr;

    public:

        virtual ~Widget () {
            logger.log (__PF);
        }

        Widget () = default;

        Widget (Widget *parent) :
            parent_ (parent)
        {
            logger.log (__PF);
        }


        Widget (Coords coords, Widget *parent) :
            coords_ (coords), parent_ (parent)
        {
            logger.log (__PF);
        }

        virtual void draw  () = 0;

        // virtual void close () = 0;
        // virtual void move  () = 0;
        virtual bool on_click (int x, int y) = 0;
        // virtual void on_press () = 0;
        
        
        bool check_bound (int x, int y) {
            
            if (x <= coords_.strt ().get_x () + coords_.width () && x >= coords_.strt ().get_x ()) {
                if (y <= coords_.strt ().get_y () + coords_.height () && y >= coords_.strt ().get_y ()) 
                    return true;
            }
            return false;
        }

/////////////////////////////////////////////////FOR MANAGER CLASS
        // virtual void add (Widget *widget) {};
        // virtual void clear () {};

        virtual void controller (const Cmd <int> & cmd) {
            std::cout <<"FUCKING HELL\n";
        };
        virtual void controller (const Cmd <Point> & cmd) {
            std::cout <<"FUCKING HELL\n";
        };

};


#endif