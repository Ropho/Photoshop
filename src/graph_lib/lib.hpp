#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace GLUT {

enum EVENTS {

    NO_EVENT = 0,
    CLOSE    = 1,

};

//SFML GRAPHIC LIBRARY USAGE IN A PROGRAM
class GL {

    public:
        
        GL () = delete;
        
        GL (size_t WIDTH, size_t HEIGHT) :
                window(sf::VideoMode(WIDTH, HEIGHT), "MAIN WINDOW")
            {}


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

    private:
        sf::RenderWindow  window {};
        sf::Event   event  {};
};


};