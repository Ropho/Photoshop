#include "graph_lib/lib.hpp"
#include "general.hpp"
#include "class_manager/manager.hpp"


const size_t WIDTH  = 800;
const size_t HEIGHT = 600;


int main (void) {

    GLUT::GL gl (WIDTH, HEIGHT);
    Manager manager (10);

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

        gl.refresh ();
    }

}