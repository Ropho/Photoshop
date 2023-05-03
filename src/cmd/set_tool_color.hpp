#ifndef SET_TOOL_COLOR_HPP
#define SET_TOOL_COLOR_HPP

#include "cmd.hpp"

class Set_Tool_Color : public Abstract_Cmd {

    public:
        Set_Tool_Color (void *parent, GLUT::Color color) :
            Abstract_Cmd (parent, ACTIONS::SET_TOOL_COLOR, nullptr), color_ (color)
        {
            Logger::Instance()->log (__PF);
        }

        void execute (Widget *argument) override {
            Logger::Instance()->log (__PF);

            Tool_Man *man = dynamic_cast <Tool_Man *> (argument);
            if (man)
                man->set_color (color_);
            else {
                Logger::Instance () -> log (__PF, LOG_LVL::FATAL, "unable to convert to manager");
                std::terminate ();
            }

        }

    private:
        GLUT::Color color_;


};



#endif