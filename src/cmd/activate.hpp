#ifndef ACTIVATE_BUTTON_HPP
#define ACTIVATE_BUTTON_HPP

#include "cmd.hpp"
#include "../button/tool.hpp"
#include "../manager/tool.hpp"


class Activate : public Abstract_Cmd {

    public:
        Activate (void *parent) :
            Abstract_Cmd (parent, ACTIONS::ACTIVATE, nullptr)
        {
            Logger::Instance()->log (__PF);

        }

        void execute (Widget *argument) override {
            Logger::Instance()->log (__PF);

            Manager *man = dynamic_cast <Manager *> (argument);
            if (man) {
                
            }else {
                Logger::Instance () -> log (__PF, 2, "unable to convert to manager");
                std::terminate ();
            }            
            man->activate ();
        }

    private:
};


class Deactivate : public Abstract_Cmd {

    public:
        Deactivate (void *parent) :
            Abstract_Cmd (parent, ACTIONS::DEACTIVATE, nullptr)
        {
            Logger::Instance()->log (__PF);

        }
        void execute (Widget *argument) override {
            Logger::Instance()->log (__PF);

            Manager *man = dynamic_cast <Manager *> (argument);
            if (man) {
                
            }else {
                Logger::Instance () -> log (__PF, 2, "unable to convert to manager");
                std::terminate ();
            }
            man -> deactivate ();
        }
};
#endif