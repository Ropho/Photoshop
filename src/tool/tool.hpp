#ifndef TOOL_HPP
#define TOOL_HPP

#include "../../lib/logger/logger.hpp"
#include "../../lib/vector/vector.hpp"
#include "../../lib/graphics/lib.hpp"
// #include "../class_widget/widget.hpp"
#include <queue>
//TODO: add includes like in processor
namespace TL {

    // enum TOOLS {

    //     PENCIL = 1,
    // };
}


class Tool {

    public:

        Tool ()
        {
            logger.log (__PF);
        }

        virtual ~Tool () {
            logger.log (__PF);
        }

        virtual void action (void *param) = 0;        
        virtual void add_entity (GLUT::Entity* entity) = 0;
        
        void set_color (GLUT::Color color) {
            color_ = color;
        }

        GLUT::TOOLS name () {
            return name_;
        }

        std::queue<GLUT::Entity *>& get_entities () {
            return entities_;
        }

     protected:
        GLUT::Color color_ = GLUT::WHITE;
        GLUT::TOOLS name_ = GLUT::NO_TOOL;
        std::queue <GLUT::Entity*> entities_ {};
};


class Pencil : public Tool {

    public:
        Pencil () :
            Tool ()
        {
            name_ = GLUT::PENCIL;
            logger.log (__PF);
        }

        ~Pencil () {
            logger.log (__PF);
        }

        void action (void *param) {
            logger.log (__PF);

            Point *pnt = (static_cast <Point *> (param));
            
            // GLUT::Color tmp_color = param.color;   
            GLUT::Entity *entity = gl.draw_dot (*pnt, color_);

            add_entity (entity);

            // fprintf (stderr, "\n\nI AM PENCIL\n\n");
        }

        void add_entity (GLUT::Entity* entity) {
            logger.log (__PF);
            entities_.push (entity);       
        }

};


#endif