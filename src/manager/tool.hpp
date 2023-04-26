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

                case ACTIONS::USE_CURRENT_TOOL:
                    cmd.execute (this);
                break;

                case ACTIONS::SET_TOOL_COLOR:
                    cmd.execute (this);
                break;

                default:
                break;
            }
        }

        void use_current (void *param) {
            if (tool_) {
                switch (tool_->tool ()) {
                    case TOOLS::PENCIL:
                        tool_ -> set_color (color_);
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

        void set_current (Abstract_Tool *tool) {
            tool_ = tool;
        }

        void remove_current () {
            tool_ = nullptr;
        }

        void set_color (const GLUT::Color& color) {
            color_ = color;
        }
        // void controller (Cmd cmd) override {
        //     switch (cmd.type ()) {
           
        //         case POINT: {
        //             switch (cmd.action ()) {

        //                 case ACTIONS::USE_TOOL: {

        //                     if (current_action != nullptr) {

        //                         GLUT::Color color;
        //                         {
        //                             // NEW_CMD (ACTIONS::GET_TOOL_COLOR, COLOR_PTR, this, &color, GLUT::Color *);
        //                             // send_cmd_down (cmd);
        //                             // END_CMD;
        //                         }
        //                         current_action->set_color (color);
                                
        //                         current_action->action (cmd.raw ());
        //                         add_entities ();
        //                     }

        //                 }break;

        //                 default: {
        //                 }break;
        //             }

        //         }break;
           
        //         case NULLPTR: {
        //             switch (cmd.action ()) {

        //                 case ACTIONS::REMOVE_CURRENT: {
        //                     // logger.log (__PF);
        //                     current_action = nullptr;
        //                 }break;
                    
        //                 default: {
        //                 }break;
        //             }
        //         }break;
            
        //         case TOOL_PTR: {
        //             switch (cmd.action ()) {

        //                 case ACTIONS::SET_CURRENT: {
        //                     logger.log (__PF);
        //                     Tool* param;
        //                     cmd.param (static_cast <void *> (&param));
        //                     current_action = param;
        //                 }break;
                    
        //                 default: {
        //                 }break;
        //             }
        //         }break;
                
        //         default: {
        //         }break;
        //     }
        // }

        // void add_entities () {
        //     std::queue <GLUT::Entity *>& entities = current_action->get_entities ();
        //     while (entities.size () > 0) {
        //         std::cerr << entities.front () << '\n';
        //         // NEW_CMD (ACTIONS::ADD_ENTITY, ENTITY_PTR, this, entities.front (), GLUT::Entity *);
        //         // parent_ -> controller (cmd);
        //         // entities.pop ();
        //         // END_CMD;     
        //     }
        // }

        private:
            Abstract_Tool *tool_ = nullptr; 
            GLUT::Color color_ = GLUT::Color::Black;
            // vector <Tool *> tools {};
            // std::unordered_map <int, Tool *> map {};
            // Tool *current_action = nullptr;
};



#endif