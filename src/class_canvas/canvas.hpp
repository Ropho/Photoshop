#ifndef CANVAS_HPP
#define CANVAS_HPP


#include "../class_widget/widget.hpp"
#include "../log/log.hpp"
#include "../graph_lib/lib.hpp"


class Canvas : public Widget {

    public:

        ~Canvas () {
            logger.log (__PF);
        }

        Canvas (Coords coords, Widget *parent) :
            Widget (coords, parent)
        {
            logger.log (__PF);

            GLUT::Entity* entity = gl.init_canvas (coords_);
            std::cerr << "ENTITY " << entity << "\n";
            // std::cerr << &entity;
            NEW_CMD (ACTIONS::ADD_ENTITY, ENTITY_PTR, this, entity, GLUT::Entity *);
            // cmd.info ();
            // Cmd <GLUT::Entity *> cmd (ACTIONS::ADD_ENTITY, static_cast <void *> (this), entity);
            // Cmd <GLUT::Entity *> cmd (ACTIONS::ADD_CANVAS, static_cast <void *> (this), entity);
            // cmd.info ();
            // std::terminate ();
            parent_ -> controller (cmd);
            END_CMD;
            // std::terminate ();

            gl.change_background (entity, color_);
            logger.log (__PF);
        }

        void draw  () {
            logger.log (__PF);

            NEW_CMD (ACTIONS::DRAW_CANVAS, NULLPTR, this, nullptr, nullptr_t);
            // Cmd <nullptr_t> cmd (ACTIONS::DRAW_CANVAS, static_cast <void *> (this));
            parent_ -> controller (cmd);
            logger.log (__PF);

            END_CMD;
        }
        
        // void close ();
        // void move  ();
        bool on_click (int x, int y) {
            if (check_bound (x, y)) {
                fprintf (stderr, "IN CANVAS!!!!\n");
                
                NEW_CMD (ACTIONS::USE_TOOL, POINT, this, Point (x, y), Point);
                // Cmd <Point> cmd (ACTIONS::USE_TOOL, static_cast <void *> (this), Point (x, y));
                parent_ -> controller (cmd);
                END_CMD;
                return true;
            }
            return false;
        }

        void change_background (int color) {
            color_ = color;

            GLUT::Entity *entity {};

            NEW_CMD (ACTIONS::GET_ENTITY_CANVAS, ENTITY_PTR_PTR, this, &entity, GLUT::Entity **);
            // Cmd <GLUT::Entity **> cmd (ACTIONS::GET_ENTITY_CANVAS, static_cast <void *> (this), &entity);
            parent_ -> controller (cmd);
            END_CMD;

            gl.change_background (entity, color_);
        }
        
        private:
            int color_ = GLUT::WHITE;
};

#endif