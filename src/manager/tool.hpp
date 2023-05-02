#ifndef TOOL_HPP
#define TOOL_HPP

#include "manager.hpp"
#include "../tool/tool.hpp"

class Tool_Man : public Manager {

    public:

        Tool_Man (Widget *parent) :
            Manager (parent)
        {
            Logger::Instance ()-> log (__PF);
        }

        ~Tool_Man () noexcept {
            Logger::Instance ()-> log (__PF);
        }

        void controller (Abstract_Cmd &cmd) override {
            Logger::Instance()->log (__PF);

            switch (cmd.action ()) {
                case ACTIONS::SET_CURRENT:
                    cmd.execute (this);
                break;

                case ACTIONS::REMOVE_CURRENT:
                    cmd.execute (this);
                break;

                case ACTIONS::START_USE_CURRENT_TOOL:
                    cmd.execute (this);
                break;

                case ACTIONS::USE_CURRENT_TOOL:
                    cmd.execute (this);
                break;

                case ACTIONS::END_USE_CURRENT_TOOL:
                    cmd.execute (this);
                break;

                case ACTIONS::SET_TOOL_COLOR:
                    cmd.execute (this);
                break;

                default:
                break;
            }
        }

        void start_use_current_tool (void *param) {
            if (tool_) {
                switch (tool_->tool ()) {
                    case TOOLS::PENCIL:
                        tool_ -> set_color (color_);
                    break;

                    case TOOLS::ERASER:
                    break;

                    default:
                        Logger::Instance () -> log (__PF, 2, "UNKNOWN TOOL");
                        std::terminate ();
                    break;
                }

                tool_ -> start_action (param);
            
            } else {
                Logger::Instance () -> log (__PF, 2, "NO TOOL SELECTED");
            }
        }

        void use_current_tool (void *param) {
            if (tool_) {
                switch (tool_->tool ()) {
                    case TOOLS::PENCIL:
                    break;

                    case TOOLS::ERASER:
                    break;

                    default:
                        Logger::Instance () -> log (__PF, 2, "UNKNOWN TOOL");
                        std::terminate ();
                    break;
                }

                tool_ -> action (param);
            
            } else {
                Logger::Instance () -> log (__PF, 2, "NO TOOL SELECTED");
            }
        }

        void end_use_current_tool (void *param) {
            if (tool_) {
                switch (tool_->tool ()) {
                    case TOOLS::PENCIL:
                    break;

                    case TOOLS::ERASER:
                    break;

                    default:
                        Logger::Instance () -> log (__PF, 2, "UNKNOWN TOOL");
                        std::terminate ();
                    break;
                }

                tool_ -> end_action (param);
            
            } else {
                Logger::Instance () -> log (__PF, 2, "NO TOOL SELECTED");
            }
        }

        void set_current (Abstract_Tool *tool) {
            tool_ = tool;
        }

        void remove_current () {
            tool_ = nullptr;
        }

        void set_color (const GLUT::Color& color) {
            color_ = color;
        }

        private:
            Abstract_Tool *tool_ = nullptr; 
            GLUT::Color color_ = GLUT::Color::Black;
            // vector <Tool *> tools {};
            // std::unordered_map <int, Tool *> map {};
            // Tool *current_action = nullptr;
};



#endif