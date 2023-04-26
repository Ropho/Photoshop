#ifndef LIB_HPP
#define LIB_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../logger/logger.hpp"
#include "../point/point.hpp"
// #include "../class_tool/tool.hpp"


namespace GLUT {

    typedef sf::Drawable Entity;
    typedef sf::Color    Color;

    const int WIDTH  = 1200;
    const int HEIGHT = 800;
    

    
enum class EVENTS {

    NO_EVENT = 0,
    CLOSE    = 1,
    CLICK    = 2,

};


enum class TOOLS {
    NO_TOOL = 0,
    PENCIL  = 1,

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

        void click (int *x, int *y) {
            *x = event.mouseButton.x;
            *y = event.mouseButton.y;
        }

        EVENTS get_event () {

            switch (event.type) {
                
                case sf::Event::Closed:
                    return EVENTS::CLOSE;
                break;

                case sf::Event::MouseButtonPressed:
                    return EVENTS::CLICK;
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
        Entity* init_background (const Color& color);
        Entity* init_canvas (const Coords &coords, GLUT::Color color);
        Entity* init_border (const Point &start, int width, int height);
        Entity* init_button (Point start, int width, int height, const std::string &texture_path);
        Entity* init_canvas_background_changer (const Point &start, int width, int height, GLUT::Color color);
        GLUT::Entity* init_dot (const Point &pnt, const GLUT::Color& color);
        // void change_background (GLUT::Entity *entity, GLUT::Color color);
        // void draw_palette_caller (const Point &start, int width, int height, int tool_name);


/////////////////////////////////////////////////
        void clear () {window.clear(sf::Color::Black);}
        void display () {window.display();}
        // void refresh () {texture_counter = 0;}
        void draw (GLUT::Entity *entity);
    private:
        sf::RenderWindow window = sf::RenderWindow (sf::VideoMode (WIDTH, HEIGHT), "MAIN WINDOW");
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
        std::vector <sf::Texture *> textures {};

        // static const size_t sprite_index = 0;
        // size_t texture_counter = 0;

        inline static GL* instance_ = nullptr;
};
}



#endif