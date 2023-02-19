#ifndef TOOL_HPP
#define TOOL_HPP

#include "../log/log.hpp"
#include "../class_vector/vector.hpp"
#include "../graph_lib/lib.hpp"


//TODO: add includes like in processor
namespace TL {

    // enum TOOLS {

    //     PENCIL = 1,
    // };
}


class Tool {

    public:

        Tool (int name) :
            name_ (name)
        {
            logger.log (__PF);
        }

        virtual ~Tool () {
            logger.log (__PF);
        }

        // virtual void action () = 0;
        virtual void action (Point pnt) = 0;

        int name () {
            return name_;
        }

    private:
        int name_ = 0;
};


class Pencil : public Tool {

    public:
        
        Pencil (int name) :
            Tool (name)
        {
            logger.log (__PF);
        }

        ~Pencil () {
            logger.log (__PF);
        }

        void action (Point pnt) {
            gl.draw_dot (pnt);

            fprintf (stderr, "\n\nI AM PENCIL\n\n");
        }
};

void get_all_tools (vector <Tool *> &tools);

#endif