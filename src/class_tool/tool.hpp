#ifndef TOOL_HPP
#define TOOL_HPP

#include "../log/log.hpp"
#include "../class_vector/vector.hpp"
#include "../graph_lib/lib.hpp"
#include "../class_widget/widget.hpp"


//TODO: add includes like in processor
namespace TL {

    // enum TOOLS {

    //     PENCIL = 1,
    // };
}


class Tool : public Widget {

    public:

        void draw () {}
        bool on_click (int x, int y) {return false;};


        Tool (GLUT::TOOLS name, Widget *parent) :
            Widget (parent),
            name_ (name)
        {
            logger.log (__PF);
        }

        virtual ~Tool () {
            logger.log (__PF);
        }

        // virtual void action () = 0;
        virtual void action (Point pnt) = 0;
        
        virtual void add_entity (GLUT::Entity* entity) = 0;
        
        GLUT::TOOLS name () {
            return name_;
        }

    protected:
        // Widget *parent_ = nullptr;
        GLUT::TOOLS name_ = GLUT::NO_TOOL;
};


class Pencil : public Tool {

    public:
        
        Pencil (GLUT::TOOLS name, Widget *parent) :
            Tool (name, parent)
        {
            logger.log (__PF);
        }

        ~Pencil () {
            logger.log (__PF);
        }

        void action (Point pnt) {
            logger.log (__PF);

            GLUT::Entity *entity = gl.draw_dot (pnt);

            add_entity (entity);

            fprintf (stderr, "\n\nI AM PENCIL\n\n");
        }

        void add_entity (GLUT::Entity* entity) {
            logger.log (__PF);

            NEW_CMD (ACTIONS::ADD_ENTITY, ENTITY_PTR, this, entity, GLUT::Entity *);
            // Cmd <GLUT::Entity *> cmd (ACTIONS::ADD_ENTITY, static_cast <void *> (this), entity);
            // logger.log (__PF);
            fprintf (stderr, "BEFORE \n");
            if (parent_ == nullptr)
                std::terminate();
            parent_ -> controller (cmd);
            END_CMD;            
        }
        

};

void get_all_tools (vector <Tool *> &tools, Widget *parent);

#endif