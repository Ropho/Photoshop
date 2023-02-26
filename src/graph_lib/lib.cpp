#include "lib.hpp"

    GLUT::GL gl (GLUT::WIDTH, GLUT::HEIGHT);

namespace GLUT {
    
    GLUT::Entity* GL::init_canvas (const Coords &coords) {
        
        sf::Texture *texture = new sf::Texture {};
        texture->create (WIDTH_, HEIGHT_);
        canvas_textures.push_back (texture);

        sf::Sprite *sprite = new sf::Sprite {};
        // canvas_entities.push_back (sprite);

        canvas_ = coords;
        return sprite;
    }

    GLUT::Entity* GL::draw_dot (const Point &pnt) {

        sf::RectangleShape *dot = new sf::RectangleShape (sf::Vector2f (10, 10));

        dot->move (pnt.get_x (), pnt.get_y());
        dot->setFillColor (sf::Color::Red);

        return dot;
        // canvas_entities.push_back (dot);
    }

    void GL::draw_border (const Point &start, int width, int height) {

        sf::RectangleShape border (sf::Vector2f (width, height));
        // sf::RectangleShape *border  = new sf::RectangleShape (sf::Vector2f (width, height));
        border.move (start.get_x (), start.get_y ());

        border.setFillColor (sf::Color::Black);
        border.setOutlineThickness(1);
        border.setOutlineColor(sf::Color::Yellow);
        
        // entities.push_back (border);
        window.draw (border);
    }

    // void GL::draw_canvas () {
        
        // for (size_t i = 0; i < canvas_entities.size (); ++i)
            // window.draw (*canvas_entities[i]);
                // 
    // }


    void GL::change_background (GLUT::Entity *entity, int color) {

    /////////////////////////////////////////////////MAIN
        size_t cnt = 0;
        size_t num_line = canvas_.strt ().get_y ();

        for (int y = canvas_.height () / 2; y > - canvas_.height () / 2; --y) {
            cnt = 4 * (num_line++ * WIDTH_ + canvas_.strt ().get_x ());
            
            for (int x = -canvas_.width () / 2; x < canvas_.width () / 2; ++x) {

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
        canvas_textures[sprite_index]->update (pixels);
        dynamic_cast <sf::Sprite *> (entity) -> setTexture (*canvas_textures[sprite_index]);
        // dynamic_cast <sf::Sprite *> (canvas_entities[sprite_index])->setTexture (*canvas_textures[sprite_index]);
    }


    void GL::draw_button (Point start, int width, int height, const std::string &texture_path) {

        // sf::CircleShape *circle = new sf::CircleShape (width / 2);
        sf::CircleShape circle (width / 2);
        circle.move (start.get_x (), 
                     start.get_y ());


        sf::Texture *texture = nullptr;
        
        if (texture_counter >= other_textures.size ()) {
            texture = new sf::Texture {};
            other_textures.push_back (texture);
            texture_counter++;
        }
        else {
            texture = other_textures[texture_counter++];
        }

        if (!texture->loadFromFile (texture_path)) {
            abort ();
        }

        circle.setTexture (texture);
        
        // canvas_textures.push_back (texture);
        // canvas_entities.push_back (circle);
        window.draw (circle);
      }


    void GL::draw_palette_caller (const Point &start, int width, int height, int tool_name) {

        switch (tool_name) {
            case PENCIL: {
                    const char *path = "./textures/tools/pencil.png";
                    draw_button (start, width, height, path);
            }break;

            default:
                abort ();
            break;
        }
    }

    void GL::draw_color_changer (const Point &start, int width, int height, int color) {

        switch (color) {

            case RED: {
                const std::string path = "./textures/buttons/red.png";
                draw_button (start, width, height, path);
            }break;

            case GREEN: {
                const std::string path = "./textures/buttons/green.png";
                draw_button (start, width, height, path);
            }break;

            case BLUE: {
                const std::string path = "./textures/buttons/blue.png";
                draw_button (start, width, height, path);
            }break;

            default:
                abort ();
            break;
        }

        return;
    }

}