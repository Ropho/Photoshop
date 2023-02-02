#include "lib.hpp"

    GLUT::GL gl (GLUT::WIDTH, GLUT::HEIGHT);

namespace GLUT {
    
    // const size_t WIDTH  = 800;
    // const size_t HEIGHT = 600;

    // GL gl (WIDTH, HEIGHT);

    void GL::draw_border (Point start, int width, int height) {

        sf::RectangleShape border (sf::Vector2f (width, height));
        border.move (start.get_x (), start.get_y ());

        border.setFillColor (sf::Color::Black);
        border.setOutlineThickness(1);
        border.setOutlineColor(sf::Color::Yellow);
        window.draw (border);
    }


    void GL::draw_canvas (Point start, int width, int height, int color) {

    /////////////////////////////////////////////////
        sf::Texture texture {};
        texture.create (WIDTH_, HEIGHT_);

        sf::Sprite sprite (texture);


    /////////////////////////////////////////////////MAIN
        size_t cnt = 0;
        size_t num_line = start.get_y ();

        for (int y = height / 2; y > -height / 2; --y) {
            cnt = 4 * (num_line++ * WIDTH_ + start.get_x ());
            
            for (int x = -width / 2; x < width / 2; ++x) {

                switch (color) {

                    case GLUT::RED:
                        pixels[cnt++] = 255;
                        pixels[cnt++] = 0;
                        pixels[cnt++] = 0;
                        pixels[cnt++] = 255;
                    break;

                    case GLUT::GREEN:
                        pixels[cnt++] = 0;
                        pixels[cnt++] = 255;
                        pixels[cnt++] = 0;
                        pixels[cnt++] = 255;
                    break;

                    case GLUT::BLUE:
                        pixels[cnt++] = 0;
                        pixels[cnt++] = 0;
                        pixels[cnt++] = 255;
                        pixels[cnt++] = 255;
                    break;

                    default:
                        pixels[cnt++] = 0;
                        pixels[cnt++] = 255;
                        pixels[cnt++] = 128;
                        pixels[cnt++] = 255;

                }

            }
        }
    /////////////////////////////////////////////////
        texture.update (pixels);
        
        window.draw (sprite);

        // window.display ();
    }



    void GL::draw_color_changer (Point start, int width, int height, int color) {

        sf::CircleShape circle (width / 2);
        circle.move (start.get_x (), 
                     start.get_y ());


        sf::Texture texture {};

        switch (color) {

            case RED:
                if (!texture.loadFromFile ("/home/ropho/plus/photoshop/textures/buttons/red.png")) {
                    abort ();
                }
            break;

            case GREEN:
                if (!texture.loadFromFile ("/home/ropho/plus/photoshop/textures/buttons/green.png")) {
                    abort ();
                }
            break;

            case BLUE:
                if (!texture.loadFromFile ("/home/ropho/plus/photoshop/textures/buttons/blue.png")) {
                    abort ();
                }
            break;

            default:
                abort ();
            break;
        }

        // texture.setSmooth (true);

        circle.setTexture (&texture);
        // circle.setTextureRect (sf::IntRect (0, 0, width, height));
        
        window.draw (circle);
        // window.display ();

        return;
    /////////////////////////////////////////////////
        // sf::Texture texture {};
        texture.create (WIDTH_, HEIGHT_);

        sf::Sprite sprite (texture);


    /////////////////////////////////////////////////MAIN
        size_t cnt = 0;
        size_t num_line = start.get_y ();

        for (int y = height / 2; y > -height / 2; --y) {
            cnt = 4 * (num_line++ * WIDTH_ + start.get_x ());
            
            for (int x = -width / 2; x < width / 2; ++x) {

                switch (color) {

                    case GLUT::RED:
                        pixels[cnt++] = 255;
                        pixels[cnt++] = 0;
                        pixels[cnt++] = 0;
                        pixels[cnt++] = 255;
                    break;

                    case GLUT::GREEN:
                        pixels[cnt++] = 0;
                        pixels[cnt++] = 255;
                        pixels[cnt++] = 0;
                        pixels[cnt++] = 255;
                    break;

                    case GLUT::BLUE:
                        pixels[cnt++] = 0;
                        pixels[cnt++] = 0;
                        pixels[cnt++] = 255;
                        pixels[cnt++] = 255;
                    break;

                    default:
                        pixels[cnt++] = 0;
                        pixels[cnt++] = 255;
                        pixels[cnt++] = 128;
                        pixels[cnt++] = 255;

                }

            }
        }
    /////////////////////////////////////////////////
        texture.update (pixels);
        
        window.draw (sprite);

        window.display ();
    }

}