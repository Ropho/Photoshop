#ifndef COLOR_MAN_HPP
#define COLOR_MAN_HPP

#include "manager.hpp"

class Color_Man : public Manager {

    public:
        Color_Man (Widget *parent) :
            Manager (parent)
            {
                Logger::Instance () -> log (__PF);
            }

        ~Color_Man () {
                Logger::Instance () -> log (__PF);
        }

        void controller (Abstract_Cmd &cmd) override {
            Logger::Instance()->log (__PF);

            switch (cmd.action ()) {

                case ACTIONS::ACTIVATE :
                    cmd.execute (this);
                break;

                case ACTIONS::DEACTIVATE:
                    cmd.execute (this);
                break;

                case ACTIONS::SET_TOOL_COLOR:
                    send_cmd_up (cmd);
                break;

                default:
                break;
            }
        }


    private:
        GLUT::Color color_ = GLUT::Color::Black; 
};


#endif