#ifndef WIDGET_HPP
#define WIDGET_HPP


#include "../../lib/point/point.hpp"
#include "../../lib/cmd/cmd.hpp"

class Widget {

    protected:
        Coords coords_ {{0, 0}, 0, 0};

        Widget *parent_ = nullptr;
            
        bool active_ = false;

    public:
        void deactivate () {
            active_ = false;
        }
        void activate () {
            active_ = true;
        }


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

        virtual void controller (Cmd cmd) {
            std::cout <<"FUCKING HELL\n";
        };
};


#endif