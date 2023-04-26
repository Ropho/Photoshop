#ifndef ABSTRACT_TOOL_HPP
#define ABSTRACT_TOOL_HPP

// #include "../../lib/logger/logger.hpp"
// #include "../../lib/vector/vector.hpp"
// #include "../../lib/graphics/lib.hpp"
#include "../widget/widget.hpp"
// #include <queue>


enum class TOOLS {
    NO_TOOL = 0,
    PENCIL  = 1,
};

class Abstract_Tool {

    public:

        Abstract_Tool (Widget *parent, TOOLS tool, Widget *use_instance) :
            parent_ (parent), tool_ (tool), use_instance_ (use_instance)
        {
            Logger::Instance() -> log (__PF);
        }

        virtual ~Abstract_Tool () {
            Logger::Instance() -> log (__PF);
        }

        virtual void action (void *param) = 0;        
        // virtual void add_entity (GLUT::Entity* entity) = 0;
        
        void set_color (const GLUT::Color& color) {
            color_ = color;
        }
        // void set_size ()

    //     GLUT::TOOLS name () {
    //         return name_;
    //     }

    //     std::queue<GLUT::Entity *>& get_entities () {
    //         return entities_;
    //     }

    //  protected:
    //     GLUT::Color color_ = GLUT::WHITE;
    //     GLUT::TOOLS name_ = GLUT::NO_TOOL;
    //     std::queue <GLUT::Entity*> entities_ {};
        virtual void set_param (void *) = 0;

        TOOLS tool () {
            return tool_;
        }

        void set_parent (Widget *parent){
            parent_ = parent;
        }
        
        Widget *from () {
            return parent_;
        }

        protected:
            Widget *parent_ = nullptr;
            TOOLS tool_ = TOOLS::NO_TOOL;
            Widget *use_instance_ = nullptr;

            GLUT::Color color_ = GLUT::Color::Black;

};


#endif