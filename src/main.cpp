#include "graph_lib/lib.hpp"
#include "general.hpp"
#include "class_manager/manager.hpp"

// const size_t WIDTH  = 800;
// const size_t HEIGHT = 600;
    // using GLUT::gl;

    // extern GLUT::gl;

int main (void) {

    // GLUT::GL gl (WIDTH, HEIGHT);
    Manager manager (10);

    Canvas canvas ({100, 100}, 100, 100);
    // return 0;
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

    }

}