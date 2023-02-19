#include "graph_lib/lib.hpp"
#include "class_factory/factory.hpp"
#include "class_tool/tool.hpp"

Logger logger {};


int main (void) {

    Factory fac {};

/////////////////////////////////////////////////MANAGERS
//static_cast read
                                        //WIDGET* -> MANAGER*
    Widget *desktop = fac.make_manager (nullptr);
    Widget *palette = fac.make_palette (desktop);

/////////////////////////////////////////////////CANVAS
    Coords canvas_coord (Point {gl.width () / 4, gl.height () / 4}, gl.width () / 2, gl.height () / 2);
    Widget *canvas = fac.make_canvas (canvas_coord, palette);

/////////////////////////////////////////////////BUTTONS
    Coords button_coords (canvas_coord.strt () + Point {canvas_coord.width (), 0},
                          canvas_coord.height () / 3, canvas_coord.height () / 3);
    Widget *button_red = fac.make_color_changer (button_coords, palette, GLUT::RED);

    button_coords = button_coords + Coords {{0, button_coords.height ()}, 0, 0}; 
    Widget *button_green = fac.make_color_changer (button_coords, palette, GLUT::GREEN);
    
    button_coords = button_coords + Coords {{0, button_coords.height ()}, 0, 0};     
    Widget *button_blue = fac.make_color_changer (button_coords, palette, GLUT::BLUE);

/////////////////////////////////////////////////TOOLS

    Coords pencil_coords (Point {gl.line_width (), gl.width () / 10}, gl.width ()  / 10, gl.width () / 10);
    Widget *pencil = fac.make_palette_caller (pencil_coords, palette, GLUT::TOOLS::PENCIL);

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
        desktop->draw ();
        gl.refresh ();
    }

    delete desktop;
}