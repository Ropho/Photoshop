#include "general.hpp"
#include "graph_lib/lib.hpp"
#include "class_manager/manager.hpp"


void log (const char *func_name) {
    fprintf (stderr, "FUNC: %s\n", func_name);
}


int main (void) {

    Widget *desktop = new Manager {};
    Widget *painter = new Manager {};

    desktop->add (painter);

    Widget *canvas = new Canvas ({200, 100}, 200, 200);
    
    Button::Abstract_Button *button_red   = new Button::Color_Changer ({450, 100}, 67, 67, &((Canvas *)canvas)->color_, GLUT::RED);
    Button::Abstract_Button *button_green = new Button::Color_Changer ({450, 180}, 67, 67, &((Canvas *)canvas)->color_, GLUT::GREEN);
    Button::Abstract_Button *button_blue  = new Button::Color_Changer ({450, 250}, 67, 67, &((Canvas *)canvas)->color_, GLUT::BLUE);

    // button_red->action ();

    // delete button_red;
    // return 0;

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
                    // gl.click (&x, &y);

                } break;

            }
        }

        // gl.refresh ();
        desktop->draw ();
        // ptr->draw ();
    }

    delete button_blue;
    delete button_green;
    delete button_red;
    delete canvas;
    delete painter;
    delete desktop;

}