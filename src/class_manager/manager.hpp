#ifndef MANAGER_HPP
#define MANAGER_HPP


#include "../class_widget/widget.hpp"
#include "../log/log.hpp"
#include "../class_canvas/canvas.hpp"
#include "../class_button/button.hpp"
#include "../class_tool/tool.hpp"
#include "../class_cmd/cmd.hpp"
#include <unordered_map>


class Manager : public Widget {

    public:

        Manager (Widget * parent) :
            Widget (parent)
            {}

        virtual ~Manager () {
            logger.log (__PF);

            arr.clear ();
        }

        virtual void add (Widget *widget) {
            arr.push_back (widget);
        }



/////////////////////////////////////////////////VIRTUAL
//TO GET VIRTUAL POLYMORPHISM NEED VISITOR PATTERN
//https://stackoverflow.com/questions/45849394/virtual-template-function-in-c

        // virtual void controller (const Cmd <int>  & cmd) {};
        // virtual void controller (const Cmd <int*> & cmd) = 0;


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

        void send_cmd_down (Cmd cmd) {
            
            for (size_t i = 0; i < arr.size (); ++i) {
                
                if (cmd.from () != static_cast <void *> (arr[i])) {

                    Manager *man = dynamic_cast <Manager *> (arr[i]);
                    if (man != nullptr) {
                        auto new_cmd = cmd;
                        new_cmd.set_from (this);
                        man->controller (new_cmd);
                    }
                }
            }
        }

        // template <typename T>
        void send_cmd_up (Cmd cmd) {
                Manager *man = dynamic_cast <Manager *> (parent_);
                    if (man != nullptr) {
                        auto new_cmd = cmd;
                        new_cmd.set_from (this);
                        man->controller (new_cmd);
                    }
                else {
                    logger.log (__PF);
                    std::terminate ();
                }

        }

    protected:
        std::vector <Widget *> arr {};
        // std::vector <Widget *> arr {};
        // Widget *kek [100];
};


class Palette : public Manager {

    public:

        Palette (Widget *parent) :
            Manager (parent)
        {
            logger.log (__PF);

            get_all_tools (tools, this);

            for (size_t i = 0; i < tools.size (); ++i) {
                map.insert ({tools[i]->name (), tools[i]});
            }

        }

        ~Palette () noexcept {
            logger.log (__PF);

            tools.clear ();
        }

        void controller (Cmd cmd) override {
            // cmd.info ();
            // std::terminate ();

            switch (cmd.type ()) {

                case INT: {

                    switch (cmd.action ()) {

                        case ACTIONS::SET_CURRENT: {
                            logger.log (__PF);
                            int param;
                            cmd.param (&param);
                            current_action = map.find (param) -> second;
                        }break;

                        case ACTIONS::REMOVE_CURRENT: {
                            logger.log (__PF);
                            current_action = nullptr;
                        }break;

                    case ACTIONS::CHANGE_BACKGROUND: {
                            logger.log (__PF);
                            send_cmd_down (cmd);
                            // canvas_->set_color (cmd.param ());
                        }break;
                    
                        default: {
                        }break;
                    }
                }break;


                case POINT: {
                    switch (cmd.action ()) {

                        case ACTIONS::USE_TOOL: {
                            logger.log (__PF);

                            if (current_action != nullptr) {
                                Point param;
                                cmd.param (&param);
                                current_action->action (param);
                            }
                        }break;

                        default: {
                        }break;
                    }

                }break;

                case ENTITY_PTR: {
                    switch (cmd.action ()) {

                        case ACTIONS::ADD_ENTITY: {
                            logger.log (__PF);
                            fprintf (stderr, "AFTER \n");
                            // std::terminate ();
                            send_cmd_down (cmd);
                        }break;

                        default: {
                        }break;
                    }

                }break;

                case ENTITY_PTR_PTR: {
                    switch (cmd.action ()) {

                        case ACTIONS::GET_ENTITY_CANVAS: {
                            
                            send_cmd_down (cmd);
                            logger.log (__PF);
                        }break;

                        default: {
                        }break;
                    }
            
                }break;

                case NULLPTR: {
                    switch (cmd.action ()) {

                        case ACTIONS::DRAW_CANVAS: {
                            // logger.log (__PF);

                            send_cmd_down (cmd);
                            // parent_ -> controller (cmd);
                        }break;

                        default: {
                        }break;
                    }

                }break;

                default: {

                }break;
            }
        }

        // void controller (Cmd <int> cmd) {
        
        //     switch (cmd.action ()) {

        //         case ACTIONS::SET_CURRENT: {
        //             logger.log (__PF);
        //             current_action = map.find (cmd.param ()) -> second;
        //         }break;

        //         case ACTIONS::REMOVE_CURRENT: {
        //             logger.log (__PF);
        //             current_action = nullptr;
        //         }break;

        //        case ACTIONS::CHANGE_BACKGROUND: {
        //             logger.log (__PF);
        //             send_cmd_down <int> (cmd);
        //             // canvas_->set_color (cmd.param ());
        //         }break;
            
        //         default: {
        //         }break;
        //     }
        // }

        // void controller (Cmd <Point> cmd) {

        //     switch (cmd.action ()) {

        //         case ACTIONS::USE_TOOL: {
        //             logger.log (__PF);

        //             if (current_action != nullptr)
        //                 current_action->action (cmd.param ());

        //         }break;

        //         default: {
        //         }break;
        //     }
        // }

        // void controller (Cmd <GLUT::Entity *> cmd) {

        //     switch (cmd.action ()) {

        //         case ACTIONS::ADD_ENTITY: {
        //             logger.log (__PF);
        //             fprintf (stderr, "AFTER \n");
        //             // std::terminate ();
        //             send_cmd_down (cmd);
        //         }break;

        //         default: {
        //         }break;
        //     }
        // }

        // void controller (Cmd <nullptr_t> cmd) {

        //     switch (cmd.action ()) {

        //         case ACTIONS::DRAW_CANVAS: {
        //             // logger.log (__PF);

        //             send_cmd_down <nullptr_t> (cmd);
        //             // parent_ -> controller (cmd);
        //         }break;

        //         default: {
        //         }break;
        //     }
        // }

        // void controller (Cmd <GLUT::Entity **> cmd) {

        //     switch (cmd.action ()) {

        //         case ACTIONS::GET_ENTITY_CANVAS: {
                    
        //             send_cmd_down (cmd);
        //             logger.log (__PF);
        //         }break;

        //         default: {
        //         }break;
        //     }
        // }

        // template <typename T>

        private:

            vector <Tool *> tools {};
            std::unordered_map <int, Tool *> map {};
            Tool *current_action = nullptr;

};

class Canvas_Man : public Manager {

    public:

        // template <typename T>

        Canvas_Man (Widget *parent) :
            Manager (parent)
        {

            logger.log (__PF);
        }

        ~Canvas_Man () noexcept {

            logger.log (__PF);
        }

        void controller (Cmd cmd) override {
            // cmd.info ();
            // std::terminate ();
            switch (cmd.type ()) {

                case INT: {
                    switch (cmd.action ()) {

                    case ACTIONS::CHANGE_BACKGROUND: {
                            logger.log (__PF);
                            
                            // send_cmd_up <int> (cmd);
                            int param;
                            cmd.param (&param);
                            canvas_->change_background (param);
                        }break;

                        default: {
                        }break;
                    }
                }break;

                case POINT: {
                    switch (cmd.action ()) {

                        case ACTIONS::USE_TOOL: {
                            logger.log (__PF);
                            
                            send_cmd_up (cmd);
                            
                            // parent_ -> controller (cmd);
                        }break;

                        default: {
                        }break;
                    }
                }break;

                case NULLPTR: {
                    switch (cmd.action ()) {

                        case ACTIONS::DRAW_CANVAS: {
                            // logger.log (__PF);

                            send_cmd_up (cmd);
                            // parent_ -> controller (cmd);
                        }break;

                        default: {
                        }break;
                    }

                }break;

                case ENTITY_PTR: {
                    switch (cmd.action ()) {

                        case ACTIONS::ADD_ENTITY: {
                            // fprintf (stderr, "CANVAS MAN: %x FROM %x\n", this, cmd.from ());
                            logger.log (__PF);
                            send_cmd_up (cmd);
                        }break;

                        default: {
                        }break;
                    }
                }break;

                case ENTITY_PTR_PTR: {
                    switch (cmd.action ()) {
                        case ACTIONS::GET_ENTITY_CANVAS: {
                            
                            logger.log (__PF);
                            send_cmd_up (cmd);
                        }break;

                        default: {
                        }break;
                    }

                }break;

                default:
                break;
            }
        }
        // void controller (Cmd <int> cmd) {
        
        //     switch (cmd.action ()) {

        //        case ACTIONS::CHANGE_BACKGROUND: {
        //             logger.log (__PF);
                    
        //             // send_cmd_up <int> (cmd);
        //             canvas_->change_background (cmd.param ());
        //         }break;

        //         default: {
        //         }break;
        //     }

        // }

        // void controller (Cmd <nullptr_t> cmd) {

        //     switch (cmd.action ()) {

        //         case ACTIONS::DRAW_CANVAS: {
        //             // logger.log (__PF);

        //             send_cmd_up <nullptr_t> (cmd);
        //             // parent_ -> controller (cmd);
        //         }break;

        //         default: {
        //         }break;
        //     }
        // }

        // void controller (Cmd <Point> cmd) {

        //     switch (cmd.action ()) {

        //         case ACTIONS::USE_TOOL: {
        //             logger.log (__PF);
                    
        //             send_cmd_up (cmd);
                    
        //             // parent_ -> controller (cmd);
        //         }break;

        //         default: {
        //         }break;
        //     }
        // }

        // void controller (Cmd <GLUT::Entity *> cmd) {

        //     switch (cmd.action ()) {

        //         case ACTIONS::ADD_ENTITY: {
        //             // fprintf (stderr, "CANVAS MAN: %x FROM %x\n", this, cmd.from ());
        //             logger.log (__PF);
        //             send_cmd_up (cmd);
        //         }break;

        //         default: {
        //         }break;
        //     }
        // }

        // void controller (Cmd <GLUT::Entity **> cmd) {

        //     switch (cmd.action ()) {

        //         case ACTIONS::GET_ENTITY_CANVAS: {
                    
        //             logger.log (__PF);
        //             send_cmd_up (cmd);
        //         }break;

        //         default: {
        //         }break;
        //     }
        // }


        void add (Widget *entity) {
            if (canvas_ == nullptr)
                canvas_ = dynamic_cast <Canvas *> (entity);
            arr.push_back (entity);
        }

        Widget* canvas () {
            return canvas_;
        }


        private:
            Canvas *canvas_ = nullptr;

};

#endif