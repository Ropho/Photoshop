#ifndef LIB_HPP
#define LIB_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../general.hpp"

namespace GLUT {

enum EVENTS {

    NO_EVENT = 0,
    CLOSE    = 1,

};

//SFML GRAPHIC LIBRARY USAGE IN A PROGRAM
class GL {



    public:
        
         GL () = delete;
        
        ~GL () {
            LOG ("~GL");
            delete pixels;
        }


        GL (size_t WIDTH, size_t HEIGHT) :
                window(sf::VideoMode(WIDTH, HEIGHT), "MAIN WINDOW"),
                WIDTH_ (WIDTH),
                HEIGHT_ (HEIGHT)
            {
                LOG ("GL ()");
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

        void refresh () {

            window.clear (sf::Color::Black);
   
            window.display ();
        }


        EVENTS get_event () {

            switch (event.type) {
                
                case sf::Event::Closed:
                    return CLOSE;
                break;

                default:
                    return NO_EVENT;
                break;
            }
        }


/////////////////////////////////////////////////DRAW

        void draw_canvas ();

    private:
        sf::RenderWindow  window {};
        int WIDTH_  = 0;
        int HEIGHT_ = 0;
        sf::Event   event  {};
        sf::Uint8* pixels = new sf::Uint8 [WIDTH_ * HEIGHT_ * 4];

};


}


    extern GLUT::GL gl;

#endif