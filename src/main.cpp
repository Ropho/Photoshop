#include "general.hpp"
#include "graph_lib/lib.hpp"
#include "class_manager/manager.hpp"


//TODO:
//1) interaction
//2) buttons have different types of pointers (maybe visitor pattern) (store ptr?)
//3) add some kind of a fabric and clear pattern


//4) vector fix
//5) add textures to buttons
//6) add tools
//7) add configuration file


void log (const char *func_name) {
    fprintf (stderr, "FUNC: %s\n", func_name);
}


int main (void) {

    Widget *desktop = new Manager (nullptr);
    Widget *painter = new Painter (desktop);
    desktop->add (painter);

    Coords canvas_coord (Point {gl.width () / 10, gl.height () / 4}, gl.width () / 2, gl.height () / 2);
    Widget *canvas = new Canvas (canvas_coord,  painter);
    ((Painter *)painter)->add_canvas (canvas);

    Coords button_coords (canvas_coord.strt () + Point {canvas_coord.width (), 0},
                          canvas_coord.height () / 3, canvas_coord.height () / 3);
    Button::Abstract_Button *button_red   = new Button::Color_Changer (button_coords, painter, GLUT::RED);
    
    button_coords = button_coords + Coords {{0, button_coords.height ()}, 0, 0}; 
    Button::Abstract_Button *button_green = new Button::Color_Changer (button_coords, painter, GLUT::GREEN);
    
    button_coords = button_coords + Coords {{0, button_coords.height ()}, 0, 0};     
    Button::Abstract_Button *button_blue  = new Button::Color_Changer (button_coords, painter, GLUT::BLUE);

    painter->add (canvas);
    painter->add (button_red);
    painter->add (button_green);
    painter->add (button_blue);


/////////////////////////////////////////////////
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


/////////////////////////////////////////////////DELETE
    delete button_blue;
    delete button_green;
    delete button_red;
    delete canvas;
    delete painter;
    delete desktop;
}