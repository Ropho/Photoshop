#include "../lib/graphics/lib.hpp"
#include "factory/factory.hpp"
#include "tool/tool.hpp"

Logger logger {};


int main (void) {

    Factory fac {};

/////////////////////////////////////////////////MANAGERS
    Widget *desktop     = fac.make_desktop (nullptr);
    Widget *background  = fac.make_background (desktop, GLUT::RED);

    Widget *palette = fac.make_palette (desktop);
    Widget *store   = fac.make_store   (palette);

/////////////////////////////////////////////////CANVAS
    Widget *canvas_man = fac.make_canvas_man (palette); 
    Coords canvas_coord (Point {gl.width () / 4, gl.height () / 4}, gl.width () / 2, gl.height () / 2);
    Widget *canvas = fac.make_canvas (canvas_coord, canvas_man);

// /////////////////////////////////////////////////BUTTONS
    Coords button_coords (canvas_coord.strt () + Point {canvas_coord.width (), 0},
                          canvas_coord.height () / 3, canvas_coord.height () / 3);
    Widget *button_red = fac.make_color_changer (button_coords, palette, GLUT::RED);

    button_coords = button_coords + Coords {{0, button_coords.height ()}, 0, 0}; 
    Widget *button_green = fac.make_color_changer (button_coords, palette, GLUT::GREEN);
    
    button_coords = button_coords + Coords {{0, button_coords.height ()}, 0, 0};     
    Widget *button_blue = fac.make_color_changer (button_coords, palette, GLUT::BLUE);

// /////////////////////////////////////////////////TOOLS
    Widget *tool_man = fac.make_tool_man (palette);
    Coords  pencil_coords (Point {0, gl.width () / 10}, gl.width ()  / 10, gl.width () / 10);
    Widget *pencil_button = fac.make_pencil (pencil_coords, tool_man);

    Widget *color_man = fac.make_color_man (tool_man);
    Coords  color_coords (Point {0, gl.width () / 10 * 3}, gl.width ()  / 10, gl.width () / 10);
    Widget *color_button = fac.make_color_changer_activator (color_coords, color_man);
            /////////////////////////////////////
    Coords  color_coords_1 (Point {gl.width () / 10, gl.width () / 10 * 2}, gl.width ()  / 10, gl.width () / 10);
    Widget *color_button_1 = fac.make_tool_color_changer (color_coords_1, color_man, GLUT::RED);

    Coords  color_coords_2 (Point {gl.width () / 10, gl.width () / 10 * 3}, gl.width ()  / 10, gl.width () / 10);
    Widget *color_button_2 = fac.make_tool_color_changer (color_coords_2, color_man, GLUT::GREEN);

    Coords  color_coords_3 (Point {gl.width () / 10, gl.width () / 10 * 4}, gl.width ()  / 10, gl.width () / 10);
    Widget *color_button_3 = fac.make_tool_color_changer (color_coords_3, color_man, GLUT::BLUE);

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
        
        gl.clear ();
        desktop->draw ();
        gl.display ();
        gl.refresh ();

        // std::terminate ();
    }

    delete desktop;
}