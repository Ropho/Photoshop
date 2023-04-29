#ifndef USE_CURRENT_TOOL_HPP
#define USE_CURRENT_TOOL_HPP

#include "cmd.hpp"
#include "../tool/tool.hpp"
#include "../manager/tool.hpp"


class Start_Use_Current_Tool : public Abstract_Cmd {

    public:
        Start_Use_Current_Tool (void *parent, void *param) :
            Abstract_Cmd (parent, ACTIONS::START_USE_CURRENT_TOOL, param)
        {
            Logger::Instance()->log (__PF);

        }

        void execute (Widget *argument) override {
            Logger::Instance()->log (__PF);

            Tool_Man *man = dynamic_cast <Tool_Man *> (argument);
            if (man == nullptr) {
                std::terminate ();
            }
            man->start_use_current_tool (param_);
        }

    private:
        Abstract_Tool *tool_ = nullptr;
};

class Use_Current_Tool : public Abstract_Cmd {

    public:
        Use_Current_Tool (void *parent, void *param) :
            Abstract_Cmd (parent, ACTIONS::USE_CURRENT_TOOL, param)
        {
            Logger::Instance()->log (__PF);

        }

        void execute (Widget *argument) override {
            Logger::Instance()->log (__PF);

            Tool_Man *man = dynamic_cast <Tool_Man *> (argument);
            if (man == nullptr) {
                std::terminate ();
            }
            man->use_current_tool (param_);
        }

    private:
        Abstract_Tool *tool_ = nullptr;
};
class End_Use_Current_Tool : public Abstract_Cmd {

    public:
        End_Use_Current_Tool (void *parent, void *param) :
            Abstract_Cmd (parent, ACTIONS::END_USE_CURRENT_TOOL, param)
        {
            Logger::Instance()->log (__PF);

        }

        void execute (Widget *argument) override {
            Logger::Instance()->log (__PF);

            Tool_Man *man = dynamic_cast <Tool_Man *> (argument);
            if (man == nullptr) {
                std::terminate ();
            }
            man->end_use_current_tool (param_);
        }

    private:
        Abstract_Tool *tool_ = nullptr;
};

#endif