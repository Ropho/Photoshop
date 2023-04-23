#ifndef MANAGER_HPP
#define MANAGER_HPP


#include "../widget/widget.hpp"
#include "../cmd/cmd.hpp"
// #include "../canvas/canvas.hpp"
// #include "../button/button.hpp"
// #include "../tool/tool.hpp"


class Manager : public Widget {
    public:

        Manager (Widget * parent) :
            Widget (parent)
            {
                Logger::Instance()->log (__PF);
            }

        virtual ~Manager () {
            Logger::Instance()->log (__PF);
            for (size_t i = 0; i < arr.size (); ++i)
                delete arr[i];
        }

        virtual void add (Widget *widget) {
            arr.push_back (widget);
        }

        bool on_click (int x, int y) {
            for (int i = (int) arr.size () - 1; i >= 0; --i)
                if (arr[i]->on_click (x, y))
                    return true;

            return false;
        }

        void draw () {
            for (size_t i = 0; i < arr.size (); ++i)
                arr[i]->draw ();
        }

        void send_cmd_down (const Abstract_Cmd &cmd) {
            for (size_t i = 0; i < arr.size (); ++i) {
            
                if (cmd.from () != static_cast <void *> (arr[i])) {
                    Manager *man = dynamic_cast <Manager *> (arr[i]);
                    if (man != nullptr) {
                        // auto new_cmd = cmd;
                        // new_cmd.set_from (this);
                        cmd.set_parent (this);
                        man -> controller (cmd);
                    }
                }
            }
        }

        void send_cmd_up (const Abstract_Cmd &cmd) {
            if (cmd.from () != parent_) {
                Manager *man = dynamic_cast <Manager *> (parent_);
                if (man != nullptr) {
                        // auto new_cmd = cmd;
                        // new_cmd.set_from (this);
                        cmd.set_parent (this);
                        man->controller (cmd);
                }
                else {
                    Logger::Instance () -> log (__PF);
                    std::terminate ();
                }
            }
        }

       virtual void controller (const Abstract_Cmd &cmd) {
            std::cerr << "NOT SUPPOSED TO BE CALLED\n";
            std::terminate ();
        };

    protected:
        std::vector <Widget *> arr {};
};



// class Tool_Man : public Manager {

//     public:

//         Tool_Man (Widget *parent) :
//             Manager (parent)
//         {
//             logger.log (__PF);
//         }

//         ~Tool_Man () noexcept {
//             logger.log (__PF);
//         }

//         void controller (Cmd cmd) override {
//             switch (cmd.type ()) {
           
//                 case POINT: {
//                     switch (cmd.action ()) {

//                         case ACTIONS::USE_TOOL: {

//                             if (current_action != nullptr) {

//                                 GLUT::Color color;
//                                 {
//                                     // NEW_CMD (ACTIONS::GET_TOOL_COLOR, COLOR_PTR, this, &color, GLUT::Color *);
//                                     // send_cmd_down (cmd);
//                                     // END_CMD;
//                                 }
//                                 current_action->set_color (color);
                                
//                                 current_action->action (cmd.raw ());
//                                 add_entities ();
//                             }

//                         }break;

//                         default: {
//                         }break;
//                     }

//                 }break;
           
//                 case NULLPTR: {
//                     switch (cmd.action ()) {

//                         case ACTIONS::REMOVE_CURRENT: {
//                             // logger.log (__PF);
//                             current_action = nullptr;
//                         }break;
                    
//                         default: {
//                         }break;
//                     }
//                 }break;
            
//                 case TOOL_PTR: {
//                     switch (cmd.action ()) {

//                         case ACTIONS::SET_CURRENT: {
//                             logger.log (__PF);
//                             Tool* param;
//                             cmd.param (static_cast <void *> (&param));
//                             current_action = param;
//                         }break;
                    
//                         default: {
//                         }break;
//                     }
//                 }break;
                
//                 default: {
//                 }break;
//             }
//         }

//         void add_entities () {
//             std::queue <GLUT::Entity *>& entities = current_action->get_entities ();
//             while (entities.size () > 0) {
//                 std::cerr << entities.front () << '\n';
//                 // NEW_CMD (ACTIONS::ADD_ENTITY, ENTITY_PTR, this, entities.front (), GLUT::Entity *);
//                 // parent_ -> controller (cmd);
//                 // entities.pop ();
//                 // END_CMD;     
//             }
//         }

//         private:
//             // vector <Tool *> tools {};
//             // std::unordered_map <int, Tool *> map {};
//             Tool *current_action = nullptr;
//             GLUT::Color color_ {};
// };


// class Color_Man : public Manager {

//     public:
//         Color_Man (Widget *parent) :
//             Manager (parent)
//             {
//                 logger.log (__PF);
//             }

//         ~Color_Man () {
//             logger.log (__PF);
//         }

//         void controller (Cmd cmd) override {
//             switch (cmd.action ()) {

//                 case ACTIONS::ACTIVATE: {
//                     for (size_t i = 0; i < arr.size (); ++i) {
//                         arr[i] -> activate ();
//                     }
//                 }break;

//                 case ACTIONS::DEACTIVATE: {
//                     for (size_t i = 0; i < arr.size (); ++i) {
//                         arr[i] -> deactivate ();
//                     }
//                 }break;

//                 case ACTIONS::CHANGE_TOOL_COLOR: {
//                         GLUT::Color param;
//                         cmd.param (&param);
//                         color_ = param;
//                 }break;

//                 case ACTIONS::GET_TOOL_COLOR: {
//                         GLUT::Color *param;
//                         cmd.param (&param);
//                         *param = color_;
//                 }break;

//                 default:
//                 break;
//             }
//         }

//     private:
//         GLUT::Color color_ = GLUT::RED; 
// };

#endif