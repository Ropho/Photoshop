#ifndef LIB_HPP
#define LIB_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../logger/logger.hpp"
#include "../point/point.hpp"
#include "text_field.hpp"


namespace GLUT {

    typedef sf::Drawable Drawable;
    typedef sf::Color    Color;
    typedef sf::FloatRect Bounds;
    
    struct Info {
        Bounds bounds;
        Color color;
    };

    enum class Type {
        DOT         = 1,
        RECT        = 2,
    };

    typedef struct Entity {
        Drawable* drawable;
        Info info;
        //add std::vector <> дополнительные (sf::Font*, sf::Texture*)
        GLUT::Type type;
    } Entity;

    const int WIDTH  = 1200;
    const int HEIGHT = 800;
    

    
enum class EVENTS {

    NO_EVENT            = 0,
    CLOSE               = 1,
    MOUSE_PRESS         = 2,
    MOUSE_RELEASE       = 3,
    MOUSE_MOVE          = 4,
    TEXT_ENTERED        = 5,
};


//SFML GRAPHIC LIBRARY USAGE IN A PROGRAM
class GL {

    protected:

         GL () = delete;
        
        ~GL () {
            Logger::Instance()->log (__PF);
            
            // delete[] pixels;
            
            // for (size_t i = 0; i < canvas_textures.size (); ++i)
            //     delete canvas_textures[i];

            // // for (size_t i = 0; i < canvas_entities.size (); ++i)
            //     // delete canvas_entities[i];

            // for (size_t i = 0; i < other_textures.size (); ++i)
            //     delete other_textures[i];
        }


        GL (size_t WIDTH, size_t HEIGHT)
        {
            Logger::Instance()->log (__PF);
        }

        public:
        static GL *Instance () {
            if (!instance_) {
                instance_ = new GL (WIDTH, HEIGHT);
            }

            return instance_;
        }

        bool still_open () {
            return window.isOpen();
        }


        bool check_events () {
            return window.pollEvent(event);
        }


        void close () {
            window.close();
        }

        void mouse_press (int *x, int *y) {
            *x = event.mouseButton.x;
            *y = event.mouseButton.y;
        }
        void mouse_release (int *x, int *y) {
            *x = event.mouseButton.x;
            *y = event.mouseButton.y;
        }
        void mouse_move (int *x, int *y) {
            *x = event.mouseMove.x;
            *y = event.mouseMove.y;
        }

        void text_entered (uint32_t *unicode) {
            *unicode = event.text.unicode;
        }

        EVENTS get_event () {

            switch (event.type) {
                
                case sf::Event::Closed:
                    return EVENTS::CLOSE;
                break;

                case sf::Event::MouseButtonPressed:
                    return EVENTS::MOUSE_PRESS;
                break;

                case sf::Event::MouseButtonReleased:
                    return EVENTS::MOUSE_RELEASE;
                break;

                case sf::Event::MouseMoved:
                    return EVENTS::MOUSE_MOVE;
                break;

                case sf::Event::TextEntered:
                    return EVENTS::TEXT_ENTERED;
                break;

                default:
                    return EVENTS::NO_EVENT;
                break;
            }
        }

        int width () const {
            return WIDTH_;
        }

        int height () const {
            return HEIGHT_;
        }
        
        // int line_width () const {
        //     return line_width_;
        // }
/////////////////////////////////////////////////INIT
        Entity init_text_form (const Coords &coords, const std::string &message);
        Entity init_background (const Color& color);
        Entity init_canvas (const Coords &coords, GLUT::Color color);
        Entity init_border (const Point &start, int width, int height);
        Entity init_button (Point start, int width, int height, const std::string &texture_path);
        Entity init_button_color (Point start, int width, int height, const GLUT::Color& color);
        Entity init_text_button (Point start, int width, int height, const GLUT::Color &color, const std::string &message);
        Entity init_canvas_background_changer (const Point &start, int width, int height, GLUT::Color color, const std::string& texture_path);
        Entity init_dot (const Point &pnt, const GLUT::Color& color);
        // void change_background (GLUT::Entity *entity, GLUT::Color color);
        // void draw_palette_caller (const Point &start, int width, int height, int tool_name);
        void draw_text_form (Entity entity, const std::string &message);


/////////////////////////////////////////////////
        void clear () {window.clear(sf::Color::Black);}
        void display () {window.display();}
        void draw (GLUT::Drawable *entity);
    private:
        sf::RenderWindow window = sf::RenderWindow (sf::VideoMode (WIDTH, HEIGHT), "Photoshop", sf::Style::Default);
        const int WIDTH_ = WIDTH;
        const int HEIGHT_ = HEIGHT;
        sf::Event event {};
        // sf::Uint8 *pixels = new sf::Uint8 [WIDTH_ * HEIGHT_ * 4];
        // // sf::Texture texture_ {};
        // // sf::Sprite *sprite_ = nullptr;
        // static Coords canvas_;

        // static int line_width_ = 1;

        // // std::vector <sf::Drawable *> canvas_entities {};
        // std::vector <sf::Texture *> canvas_textures = std::vector <sf::Texture *> {};
        // std::vector <sf::Texture *> other_textures = std::vector <sf::Texture *> {};
        // std::vector <sf::Texture *> textures {};

        // static const size_t sprite_index = 0;
        // size_t texture_counter = 0;

        inline static GL* instance_ = nullptr;
};
}



#endif