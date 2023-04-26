#include "lib.hpp"

namespace GLUT {
    
    void GL::draw (Entity *entity) {
        window.draw (*entity);
    }
/////////////////////////////////////////////////BACKGROUND
    Entity* GL::init_background (const Color& color) {
        sf::RectangleShape *rect = new sf::RectangleShape {};
        rect -> setSize (sf::Vector2f (WIDTH_, HEIGHT_));
        rect -> setFillColor (color);

        window.draw (*rect);
        return rect;
    }    
/////////////////////////////////////////////////CANVAS

    GLUT::Entity* GL::init_canvas (const Coords &coords, GLUT::Color color) {

        sf::RectangleShape *rect = new sf::RectangleShape {};
        rect->move (coords.strt().get_x(), coords.strt().get_y ());
        rect -> setSize (sf::Vector2f (coords.width(), coords.height()));
        rect -> setFillColor (color);

        return rect;
    }

/////////////////////////////////////////////////BUTTONS
    GLUT::Entity* GL::init_dot (const Point &pnt, const GLUT::Color& color) {

        sf::RectangleShape *dot = new sf::RectangleShape (sf::Vector2f (10, 10));
        dot->move (pnt.get_x (), pnt.get_y());
        dot->setFillColor (color);

        return dot;
    }

    Entity* GL::init_button (Point start, int width, int height, const std::string &texture_path) {

        sf::CircleShape *circle = new sf::CircleShape (width / 2);
        circle->move (start.get_x (), 
                     start.get_y ());


        sf::Texture *texture = nullptr;
        
            texture = new sf::Texture {};
            textures.push_back (texture);

        if (!texture->loadFromFile (texture_path)) {
            std::terminate ();
        }

        circle->setTexture (texture);
        
        return circle;
    }

    Entity* GL::init_canvas_background_changer (const Point &start, int width, int height, GLUT::Color color) {

        if (color == Color::Red) {
            const std::string path = "./data/textures/buttons/red.png";
            return init_button (start, width, height, path);
        }
        else if (color == Color::Green) {
            const std::string path = "./data/textures/buttons/green.png";
            return init_button (start, width, height, path);
        }
        else if (color == Color::Blue) {
            const std::string path = "./data/textures/buttons/blue.png";
            return init_button (start, width, height, path);
        }
        else {
            Logger::Instance()->log (__PF, 2);
            std::terminate ();
        }
    }

    Entity* GL::init_border (const Point &start, int width, int height) {

        sf::RectangleShape *border  = new sf::RectangleShape (sf::Vector2f (width, height));
        border->move (start.get_x (), start.get_y ());

        border->setFillColor (sf::Color::Black);
        border->setOutlineThickness(1);
        border->setOutlineColor(sf::Color::Yellow);
        
        return border;
    }

    // void GL::draw_palette_caller (const Point &start, int width, int height, int tool_name) {

    //     switch (tool_name) {
    //         case PENCIL: {
    //                 const char *path = "./data/textures/tools/pencil.png";
    //                 draw_button (start, width, height, path);
    //         }break;

    //         default:
    //             abort ();
    //         break;
    //     }
    // }

}