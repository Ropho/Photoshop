#ifndef LIB_HPP
#define LIB_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../log/log.hpp"
#include "../class_point/point.hpp"


namespace GLUT {


    const int WIDTH  = 1200;
    const int HEIGHT = 800;
    
enum EVENTS {

    NO_EVENT = 0,
    CLOSE    = 1,
    CLICK    = 2,

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
            delete pixels;
        }


        GL (size_t WIDTH, size_t HEIGHT) :
                window(sf::VideoMode(WIDTH, HEIGHT), "MAIN WINDOW"),
                WIDTH_  (WIDTH),
                HEIGHT_ (HEIGHT)
            {
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
            // fprintf (stderr, "CURRENT POS \t X: %d \t Y: %d\n", *x, *y);

        }


        void refresh () {

            // window.clear (sf::Color::Black);
            window.display ();
   
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

        void draw_canvas (Point start, int width, int height, int color);
        void draw_color_changer (Point start, int width, int height, int color);
        void draw_border (Point start, int width, int height);

    private:
        sf::RenderWindow  window {};
        int WIDTH_  = 0;
        int HEIGHT_ = 0;
        sf::Event   event  {};
        sf::Uint8* pixels = new sf::Uint8 [WIDTH_ * HEIGHT_ * 4];

        int line_width_ = 1;
};


}


    extern GLUT::GL gl;

#endif