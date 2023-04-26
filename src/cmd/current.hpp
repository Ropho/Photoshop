#ifndef CURRENT_HPP
#define CURRENT_HPP

#include "cmd.hpp"
#include "../tool/tool.hpp"
#include "../button/tool.hpp"
#include "../manager/tool.hpp"


class Set_Current : public Abstract_Cmd {

    public:
        Set_Current (void *parent, Abstract_Tool *tool) :
            Abstract_Cmd (parent, ACTIONS::SET_CURRENT, nullptr), tool_ (tool)
        {
            Logger::Instance()->log (__PF);

        }

        void execute (Widget *argument) override {
            Logger::Instance()->log (__PF);

            Tool_Man *man = dynamic_cast <Tool_Man *> (argument);
            if (man)
                man->set_current (tool_);
            else {
                Logger::Instance ()-> log (__PF, 2, "unable to conver to manager\n");
            }
        }

    private:
        Abstract_Tool *tool_ = nullptr;
};


class Remove_Current : public Abstract_Cmd {

    public:
        Remove_Current (void *parent) :
            Abstract_Cmd (parent, ACTIONS::REMOVE_CURRENT, nullptr)
        {
            Logger::Instance()->log (__PF);

        }
        void execute (Widget *argument) override {
            Logger::Instance()->log (__PF);


            Tool_Man *man = dynamic_cast <Tool_Man *> (argument);
            if (man)
                man->remove_current ();
            else {
                Logger::Instance ()-> log (__PF, 2, "unable to conver to manager\n");
            }
        }
};
#endif