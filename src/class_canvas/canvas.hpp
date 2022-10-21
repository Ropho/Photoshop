#ifndef CANVAS_HPP
#define CANVAS_HPP


#include "../class_point/point.hpp"
#include "../class_widget/widget.hpp"
#include "../general.hpp"
#include "../graph_lib/lib.hpp"

class Canvas : public Widget {

    public:

        ~Canvas () {
            LOG ("~CANVAS");
        }

        Canvas (Point start, double width, double height) :
            Widget (start, width, height)
        {
            LOG ("CANVAS ()");
        }

        void draw  () {
            
            gl.draw_canvas ();
        }
        
        // void close ();
        // void move  ();
        // void on_click ();
        // void on_press ();

};

#endif