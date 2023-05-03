#ifndef WIDGET_HPP
#define WIDGET_HPP


// #include "../../lib/point/point.hpp"
// #include "../cmd/cmd.hpp"
// #include "../../lib/graphics/lib.hpp"
// #include <vector>

class Widget {

    protected:
        Coords coords_ {{0, 0}, 0, 0};

        Widget *parent_ = nullptr;

        bool active_ = false;

        std::vector <GLUT::Entity> entities_ {};

    public:
        std::vector <GLUT::Entity> &get_entities () {return entities_;}

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
            entities_.clear ();
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
            for (size_t i = 0; i < entities_.size (); i++)
                GLUT::GL::Instance()->draw (entities_[i].drawable);
        }

        // virtual void close () = 0;
        // virtual void move  () = 0;
        virtual bool on_mouse_release   (int x, int y) {return false;}
        virtual bool on_mouse_press     (int x, int y) {return false;}
        virtual bool on_mouse_move      (int x, int y) {return false;}
        virtual bool on_text_entered (uint32_t unicode) {return false;}
        
        bool check_bound (int x, int y) {
            
            if (x <= coords_.strt ().get_x () + coords_.width () && x >= coords_.strt ().get_x ()) {
                if (y <= coords_.strt ().get_y () + coords_.height () && y >= coords_.strt ().get_y ()) 
                    return true;
            }
            return false;
        }
};


#endif