#include "lib.hpp"

namespace GLUT {
    
    void GL::draw (Drawable *entity) {
        window.draw (*entity);
    }
/////////////////////////////////////////////////BACKGROUND
    Entity GL::init_background (const Color& color) {
        sf::RectangleShape *rect = new sf::RectangleShape {};
        rect -> setSize (sf::Vector2f (WIDTH_, HEIGHT_));
        rect -> setFillColor (color);

        Entity entity = {
            rect,
            Info {
                rect->getGlobalBounds (),
                rect->getFillColor (),
            },
            Type::RECT
        };

        return entity;
    }
/////////////////////////////////////////////////CANVAS

    Entity GL::init_canvas (const Coords &coords, GLUT::Color color) {

        sf::RectangleShape *rect = new sf::RectangleShape {};
        rect->move (coords.strt().get_x(), coords.strt().get_y ());
        rect -> setSize (sf::Vector2f (coords.width(), coords.height()));
        rect -> setFillColor (color);

        Entity entity = {
            rect,
            Info {
                rect->getGlobalBounds (),
                color,
            },
            Type::RECT
        };

        return entity;
    }

/////////////////////////////////////////////////BUTTONS
    GLUT::Entity GL::init_dot (const Point &pnt, const GLUT::Color& color) {

        sf::RectangleShape *dot = new sf::RectangleShape (sf::Vector2f (10, 10));
        dot->move (pnt.get_x (), pnt.get_y());
        dot->setFillColor (color);

        Entity entity {
            dot,
            Info {
                dot->getGlobalBounds (),
                dot->getFillColor ()
            },
            Type::DOT,
        };

        return entity;
    }

    Entity GL::init_button (Point start, int width, int height, const std::string &texture_path) {

        sf::RectangleShape *button = new sf::RectangleShape (sf::Vector2f (width, height));
        button->move (start.get_x (), 
                     start.get_y ());


        sf::Texture *texture = nullptr;
        
        texture = new sf::Texture {};

        if (!texture->loadFromFile (texture_path)) {
            Logger::Instance () -> log (__PF, LOG_LVL::FATAL, "unable to load a texture in a button");
            std::terminate ();
        }

        button->setTexture (texture);
        
        Entity entity {
            button,
            Info {
                button->getGlobalBounds (),
                button->getFillColor (),
            },
            Type::RECT
        };
        
        return entity;
    }

    Entity GL::init_button_color (Point start, int width, int height, const GLUT::Color& color) {

        sf::RectangleShape *button = new sf::RectangleShape (sf::Vector2f (width, height));
        button->move (start.get_x (), 
                     start.get_y ());


        button->setFillColor (color);
        
        Entity entity {
            button,
            Info {
                button->getGlobalBounds (),
                button->getFillColor (),
            },
            Type::RECT
        };
        
        return entity;
    }

    Entity GL::init_text_button (Point start, int width, int height, const GLUT::Color &color, const std::string &message) {

        sf::Font *font = new sf::Font;
        if (!font->loadFromFile("./data/fonts/ARIAL.TTF")) {
            Logger::Instance () -> log (__PF, LOG_LVL::FATAL, "unable to load font from file");
            std::terminate ();
        }

        sf::Text *text = new sf::Text;

        text -> setFont(*font);
        text -> setString(message);

        // set the character size
        text -> setCharacterSize(width / message.length ()); // in pixels, not points!

        // set the color
        text -> setFillColor(sf::Color::White);
        text -> setStyle(sf::Text::Bold);
        
        text -> move (start.get_x () + (width - text -> getGlobalBounds ().width) / 2, start.get_y () + (height - text -> getGlobalBounds().height) / 2);
        Entity entity {
            text,
            Info {
                text->getGlobalBounds (),
                text->getFillColor (),
            },
            Type::RECT
        };

        return entity;
    }

    Entity GL::init_canvas_background_changer (const Point &start, int width, int height, GLUT::Color color, const std::string& texture_path) {
        return init_button (start, width, height, texture_path);
    }

    Entity GL::init_border (const Point &start, int width, int height) {

        sf::RectangleShape *border  = new sf::RectangleShape (sf::Vector2f (width, height));
        border->move (start.get_x (), start.get_y ());

        border->setFillColor (sf::Color::Black);
        border->setOutlineThickness(1);
        border->setOutlineColor(sf::Color::Yellow);
        
        Entity entity {
            border,
            Info {
                border->getGlobalBounds (),
                border->getFillColor (),
            },
            Type::RECT
        };
        
        return entity;
    }


/////////////////////////////////////////////////TEXT_FORM
    Entity GL::init_text_form (const Coords &coords, const std::string &message) {

        Text_Field *text_form = new Text_Field (coords.strt() .get_x (), coords.strt ().get_y(), coords.width(), coords.height (), message);


        Entity entity {
            text_form,
            Info {
                text_form->getGlobalBounds (),
                sf::Color::Black,
                // text_form->getFillColor (),
            },
            Type::RECT
        };

        return entity;
    }
    void GL::draw_text_form (Entity entity, const std::string &message) {
        Text_Field *text_field = dynamic_cast <Text_Field*> (entity.drawable);
        if (text_field) {
            text_field->set_message (message);
        }else {
            Logger::Instance () -> log (__PF, LOG_LVL::FATAL, "unable to convert ot Text_Field");
            std::terminate ();
        }
        
        draw (entity.drawable);
    }
}