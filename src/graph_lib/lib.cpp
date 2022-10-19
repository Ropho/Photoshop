#include "lib.hpp"

    const size_t WIDTH  = 800;
    const size_t HEIGHT = 600;
    
    GLUT::GL gl (WIDTH, HEIGHT);

namespace GLUT {
    
    // const size_t WIDTH  = 800;
    // const size_t HEIGHT = 600;

    // GL gl (WIDTH, HEIGHT);


    void GL::draw_canvas () {

    /////////////////////////////////////////////////
        sf::Texture texture {};
        texture.create (WIDTH_, HEIGHT_);

        sf::Sprite sprite (texture);


    /////////////////////////////////////////////////MAIN

        size_t cnt = 0;

        for (int y = HEIGHT_ / 2; y > -HEIGHT_ / 2; --y) {
            
            for (int x = -WIDTH_ / 2; x < WIDTH_ / 2; ++x) {

                pixels[cnt++] = 0;
                pixels[cnt++] = 255;
                pixels[cnt++] = 0;
                pixels[cnt++] = 255;


            }
        }
    /////////////////////////////////////////////////
        texture.update (pixels);
        
        window.draw (sprite);

        window.display ();
    }
}