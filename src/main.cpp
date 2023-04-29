#include "../lib/graphics/lib.hpp"
#include "factory/factory.hpp"


int main (void) {
    
/////////////////////////////////////////////////MANAGERS
    Widget *desktop = Factory::Instance()->make_desktop (nullptr);
    Widget *palette = Factory::Instance()->make_palette (desktop);

    Widget *background  = Factory::Instance()->make_background (palette, GLUT::Color::Yellow);
    // Widget *store   = Factory::Instance()->make_store   (palette);

/////////////////////////////////////////////////CANVAS
    Widget *canvas_man = Factory::Instance()->make_canvas_man (palette); 
    Coords canvas_coord (Point {GLUT::GL::Instance()->width () / 4, GLUT::GL::Instance()->height () / 4}, GLUT::GL::Instance()->width () / 2, GLUT::GL::Instance()->height () / 2);
    Widget *canvas = Factory::Instance()->make_canvas (canvas_coord, GLUT::Color::White, canvas_man);

// // /////////////////////////////////////////////////BUTTONS
    Coords button_coords (canvas_coord.strt () + Point {canvas_coord.width (), 0},
                          canvas_coord.height () / 3, canvas_coord.height () / 3);
    Widget *button_red = Factory::Instance()->make_canvas_background_changer (button_coords, palette, GLUT::Color::Red, "./data/textures/buttons/red.png");

    button_coords = button_coords + Coords {{0, button_coords.height ()}, 0, 0}; 
    Widget *button_green = Factory::Instance()->make_canvas_background_changer (button_coords, palette, GLUT::Color::Green, "./data/textures/buttons/green.png");
    
    button_coords = button_coords + Coords {{0, button_coords.height ()}, 0, 0};     
    Widget *button_blue = Factory::Instance()->make_canvas_background_changer (button_coords, palette, GLUT::Color::Blue, "./data/textures/buttons/blue.png");

// // /////////////////////////////////////////////////TOOLS
    Widget *tool_man = Factory::Instance()->make_tool_man (palette);
    Coords  pencil_coords (Point {0, GLUT::GL::Instance()->width () / 10}, GLUT::GL::Instance()->width ()  / 10, GLUT::GL::Instance()->width () / 10);
    Widget *pencil_button = Factory::Instance() -> make_pencil (pencil_coords, tool_man, canvas, "./data/textures/tools/pencil.png");

    Coords  eraser_coords (Point {0, GLUT::GL::Instance()->width () / 10 * 2}, GLUT::GL::Instance()->width ()  / 10, GLUT::GL::Instance()->width () / 10);
    Widget *eraser_button = Factory::Instance() -> make_eraser (eraser_coords, tool_man, canvas, "./data/textures/tools/eraser.png");

/////////////////////////////////////////////////
    Widget *color_man = Factory::Instance() -> make_color_man (tool_man);
    Coords  color_coords (Point {0, GLUT::GL::Instance()->width () / 10 * 3}, GLUT::GL::Instance()->width ()  / 10, GLUT::GL::Instance()->width () / 10);
    Widget *color_button = Factory::Instance() -> make_color_changer_activator (color_coords, color_man, "./data/textures/tools/colors.png");
//             /////////////////////////////////////
    Coords  color_coords_1 (Point {GLUT::GL::Instance()->width () / 10, GLUT::GL::Instance()->width () / 10 * 2}, GLUT::GL::Instance()->width ()  / 10, GLUT::GL::Instance()->width () / 10);
    Widget *color_button_1 = Factory::Instance ()->make_tool_color_changer (color_coords_1, color_man, GLUT::Color::Red, "./data/textures/buttons/red.png");

    Coords  color_coords_2 (Point {GLUT::GL::Instance()->width () / 10, GLUT::GL::Instance()->width () / 10 * 3}, GLUT::GL::Instance()->width ()  / 10, GLUT::GL::Instance()->width () / 10);
    Widget *color_button_2 = Factory::Instance ()->make_tool_color_changer (color_coords_2, color_man, GLUT::Color::Green, "./data/textures/buttons/green.png");

    Coords  color_coords_3 (Point {GLUT::GL::Instance()->width () / 10, GLUT::GL::Instance()->width () / 10 * 4}, GLUT::GL::Instance()->width ()  / 10, GLUT::GL::Instance()->width () / 10);
    Widget *color_button_3 = Factory::Instance ()->make_tool_color_changer (color_coords_3, color_man, GLUT::Color::Blue, "./data/textures/buttons/blue.png");

/////////////////////////////////////////////////EVENT LOOP
    while (GLUT::GL::Instance()->still_open ()) {

        while (GLUT::GL::Instance()->check_events ()) {

            switch (GLUT::GL::Instance()->get_event ()) {
    
                case GLUT::EVENTS::CLOSE: {
                    GLUT::GL::Instance()->close ();
                } break;

                case GLUT::EVENTS::MOUSE_PRESS: {
                    int x = 0;
                    int y = 0;

                    GLUT::GL::Instance()-> mouse_press (&x, &y);
        
                    desktop->on_mouse_press (x, y);
                } break;

                case GLUT::EVENTS::MOUSE_RELEASE: {
                    int x = 0;
                    int y = 0;

                    GLUT::GL::Instance()-> mouse_release (&x, &y);
        
                    desktop->on_mouse_release (x, y);
                } break;

                case GLUT::EVENTS::MOUSE_MOVE: {
                    int x = 0;
                    int y = 0;

                    GLUT::GL::Instance()-> mouse_move (&x, &y);
        
                    desktop->on_mouse_move (x, y);
                } break;

                default: {

                } break;

            }
        }
        
        GLUT::GL::Instance()->clear ();
        desktop->draw ();
        GLUT::GL::Instance()->display ();
        // GLUT::GL::Instance()->refresh ();

        // std::terminate ();
    }

    delete desktop;
}