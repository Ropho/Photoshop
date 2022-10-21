#include "general.hpp"
#include "graph_lib/lib.hpp"
#include "class_manager/manager.hpp"

int main (void) {

    // GLUT::GL gl (WIDTH, HEIGHT);
    Manager manager {};


    Widget *canvas = new Canvas ({100, 100}, 100, 100);

    manager.add (canvas);



/////////////////////////////////////////////////
    while (gl.still_open ()) {

        
        while (gl.check_events ()) {

            switch (gl.get_event ()) {
                
                
                case GLUT::CLOSE:
                    gl.close ();
                break;

                default:
                break;


            }
        }

        // gl.refresh ();
        manager.draw_all ();
        // ptr->draw ();
    }

    delete canvas;
}




void log (const char *func_name, const char *str) {
    fprintf (stderr, "FUNC: %s \t MESSAGE: %s\n", func_name, str);
}
