#include "general.hpp"
#include "graph_lib/lib.hpp"
#include "class_factory/factory.hpp"

//TODO:

//1) add tools
//2) refactor

//3) vector fix
//4) add textures to buttons
//5) add configuration file


void log (const char *func_name) {
    fprintf (stderr, "FUNC: %s\n", func_name);
}


int main (void) {

    Factory fac {};

/////////////////////////////////////////////////MANAGERS
    Widget *desktop = fac.make_manager (nullptr);
    Widget *painter = fac.make_painter (desktop);

/////////////////////////////////////////////////CANVAS
    Coords canvas_coord (Point {gl.width () / 10, gl.height () / 4}, gl.width () / 2, gl.height () / 2);
    Widget *canvas = fac.make_canvas (canvas_coord, painter);

/////////////////////////////////////////////////BUTTONS
    Coords button_coords (canvas_coord.strt () + Point {canvas_coord.width (), 0},
                          canvas_coord.height () / 3, canvas_coord.height () / 3);
    Widget *button_red = fac.make_color_changer (button_coords, painter, GLUT::RED);

    button_coords = button_coords + Coords {{0, button_coords.height ()}, 0, 0}; 
    Widget *button_green = fac.make_color_changer (button_coords, painter, GLUT::GREEN);
    
    button_coords = button_coords + Coords {{0, button_coords.height ()}, 0, 0};     
    Widget *button_blue = fac.make_color_changer (button_coords, painter, GLUT::BLUE);


/////////////////////////////////////////////////EVENT LOOP
    while (gl.still_open ()) {

        
        while (gl.check_events ()) {

            switch (gl.get_event ()) {
                
                
                case GLUT::CLOSE: {
                    gl.close ();
                } break;

                case GLUT::CLICK: {
        
                    int x = 0;
                    int y = 0;

                    gl.click (&x, &y);
        
                    desktop->on_click (x, y);
                } break;

                default: {
                } break;

            }
        }

        // gl.refresh ();
        desktop->draw ();
    }

}