#ifndef LIB_HPP
#define LIB_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../log/log.hpp"
#include "../class_point/point.hpp"
// #include "../class_tool/tool.hpp"


namespace GLUT {

    typedef sf::Drawable Entity;

    const int WIDTH  = 1200;
    const int HEIGHT = 800;
    
enum EVENTS {

    NO_EVENT = 0,
    CLOSE    = 1,
    CLICK    = 2,

};


enum TOOLS {
    NO_TOOL = 0,
    PENCIL  = 1,

};


enum COLORS {

    BLACK   = 0,
    RED     = 1,
    GREEN   = 2,
    BLUE    = 3,
    WHITE   = 255,
};


//SFML GRAPHIC LIBRARY USAGE IN A PROGRAM
class GL {



    public:

         GL () = delete;
        
        ~GL () {
            logger.log (__PF);
            
            delete[] pixels;
            
            for (size_t i = 0; i < canvas_textures.size (); ++i)
                delete canvas_textures[i];

            // for (size_t i = 0; i < canvas_entities.size (); ++i)
                // delete canvas_entities[i];

            for (size_t i = 0; i < other_textures.size (); ++i)
                delete other_textures[i];
        }


        GL (size_t WIDTH, size_t HEIGHT) :
                window(sf::VideoMode(WIDTH, HEIGHT), "MAIN WINDOW"),
                WIDTH_  (WIDTH),
                HEIGHT_ (HEIGHT)
            {
                pixels = new sf::Uint8 [WIDTH_ * HEIGHT_ * 4];

                logger.log (__PF);
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
                    return CLOSE;
                break;

                case sf::Event::MouseButtonPressed:
                    return CLICK;
                break;

                default:
                    return NO_EVENT;
                break;
            }
        }

        int width () const {
            return WIDTH_;
        }

        int height () const {
            return HEIGHT_;
        }
        
        int line_width () const {
            return line_width_;
        }
/////////////////////////////////////////////////DRAW
        // void draw_canvas ();
        GLUT::Entity* init_canvas (const Coords &coords);
        void change_background (GLUT::Entity *entity, int color);
        void draw_color_changer (const Point &start, int width, int height, int color);
        void draw_border (const Point &start, int width, int height);
        void draw_palette_caller (const Point &start, int width, int height, int tool_name);
        GLUT::Entity* draw_dot (const Point &pnt);

        void draw_button (Point start, int width, int height, const std::string &texture_path);

        void clear () {window.clear(sf::Color::Black);}
        void display () {window.display();}
        void refresh () {texture_counter = 0;}
        void draw (GLUT::Entity *entity) {window.draw (*entity);}
    private:
        sf::RenderWindow  window {};
        int WIDTH_  = 0;
        int HEIGHT_ = 0;
        sf::Event   event  {};
        sf::Uint8 *pixels = nullptr;
        
        // sf::Texture texture_ {};
        // sf::Sprite *sprite_ = nullptr;
        Coords canvas_;

        int line_width_ = 1;

        // std::vector <sf::Drawable *> canvas_entities {};
        std::vector <sf::Texture *> canvas_textures {};

        std::vector <sf::Texture *> other_textures {};

        const size_t sprite_index = 0;
        size_t texture_counter = 0;

};


}


    extern GLUT::GL gl;

#endif