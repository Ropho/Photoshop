#ifndef WIDGET_HPP
#define WIDGET_HPP


#include "../../lib/point/point.hpp"
#include "../../lib/logger/logger.hpp"
// #include "../cmd/cmd.hpp"
#include "vector"

class Widget {

    protected:
        Coords coords_ {{0, 0}, 0, 0};

        Widget *parent_ = nullptr;
            
        bool active_ = false;

        std::vector <GLUT::Entity *> drawable_ {};

    public:
        void deactivate () {
            active_ = false;
        }
        void activate () {
            active_ = true;
        }

//////////////////////////////////////CTOR + DTOR
        virtual ~Widget () {
            Logger::Instance()->log (__PF);
            clear ();
        }
        
        virtual void init () {}
        virtual void clear () {
            for (size_t i = 0; i < drawable_.size (); i++)
                delete drawable_[i];
            drawable_.clear ();
        }

        Widget () = default;
        Widget (Widget *parent) :
            parent_ (parent)
        {
            Logger::Instance()->log (__PF);
        }

        Widget (Coords coords, Widget *parent) :
            coords_ (coords), parent_ (parent)
        {
            Logger::Instance()->log (__PF);
        }

///////////////////////////////////////
        virtual void draw () {
            for (size_t i = 0; i < drawable_.size (); i++)
                GLUT::GL::Instance()->draw (drawable_[i]);
        }

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
};


#endif