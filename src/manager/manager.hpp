#ifndef MANAGER_HPP
#define MANAGER_HPP


#include "../widget/widget.hpp"
#include "../../lib/log/log.hpp"
#include "../canvas/canvas.hpp"
#include "../button/button.hpp"
#include "../tool/tool.hpp"
// #include "../../libclass_cmd/cmd.hpp"


class Manager : public Widget {
    public:

        Manager (Widget * parent) :
            Widget (parent)
            {}

        virtual ~Manager () {
            logger.log (__PF);
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

        void send_cmd_up (Cmd cmd) {
                if (cmd.from () != parent_) {
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
        }

    protected:
        std::vector <Widget *> arr {};
};


class Palette : public Manager {

    public:

        Palette (Widget *parent) :
            Manager (parent)
        {
            logger.log (__PF);
        }

        ~Palette () noexcept {
            logger.log (__PF);
        }

        void controller (Cmd cmd) override {
            switch (cmd.type ()) {
                
                case POINT: {
                    switch (cmd.action ()) {

                        case ACTIONS::USE_TOOL: {
                                send_cmd_down (cmd);
                        }break;

                        default: {
                        }break;
                    }

                }break;

                case COLOR: {

                    switch (cmd.action ()) {
                        case ACTIONS::CHANGE_BACKGROUND: {
                                // logger.log (__PF);
                                send_cmd_down (cmd);
                            }break;
                        
                            default: {
                            }break;
                        }
                    }break;

                case ENTITY_PTR: {
                    switch (cmd.action ()) {

                        case ACTIONS::ADD_ENTITY: {
                            // logger.log (__PF);
                            // fprintf (stderr, "AFTER \n");
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
                            // logger.log (__PF);
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
                        }break;

                        default: {
                        }break;
                    }
                }break;

                default: {
                }break;
            }
        }
};


class Tool_Man : public Manager {

    public:

        Tool_Man (Widget *parent) :
            Manager (parent)
        {
            logger.log (__PF);
        }

        ~Tool_Man () noexcept {
            logger.log (__PF);
        }

        void controller (Cmd cmd) override {
            switch (cmd.type ()) {
           
                case POINT: {
                    switch (cmd.action ()) {

                        case ACTIONS::USE_TOOL: {
                            // logger.log (__PF);
                            // set_color () {

                            if (current_action != nullptr) {

                                GLUT::Color color;
                                {
                                    NEW_CMD (ACTIONS::GET_TOOL_COLOR, COLOR_PTR, this, &color, GLUT::Color *);
                                    send_cmd_down (cmd);
                                    END_CMD;
                                }
                                current_action->set_color (color);
                                
                                current_action->action (cmd.raw ());
                                add_entities ();
                            }

                        }break;

                        default: {
                        }break;
                    }

                }break;
           
                case NULLPTR: {
                    switch (cmd.action ()) {

                        case ACTIONS::REMOVE_CURRENT: {
                            // logger.log (__PF);
                            current_action = nullptr;
                        }break;
                    
                        default: {
                        }break;
                    }
                }break;
            
                case TOOL_PTR: {
                    switch (cmd.action ()) {

                        case ACTIONS::SET_CURRENT: {
                            logger.log (__PF);
                            Tool* param;
                            cmd.param (static_cast <void *> (&param));
                            current_action = param;
                        }break;
                    
                        default: {
                        }break;
                    }
                }break;
                
                default: {
                }break;
            }
        }

        void add_entities () {
            std::queue <GLUT::Entity *>& entities = current_action->get_entities ();
            while (entities.size () > 0) {
                std::cerr << entities.front () << '\n';
                NEW_CMD (ACTIONS::ADD_ENTITY, ENTITY_PTR, this, entities.front (), GLUT::Entity *);
                parent_ -> controller (cmd);
                entities.pop ();
                END_CMD;     
            }
        }

        private:
            // vector <Tool *> tools {};
            // std::unordered_map <int, Tool *> map {};
            Tool *current_action = nullptr;
            GLUT::Color color_ {};
};


class Color_Man : public Manager {

    public:
        Color_Man (Widget *parent) :
            Manager (parent)
            {
                logger.log (__PF);
            }

        ~Color_Man () {
            logger.log (__PF);
        }

        void controller (Cmd cmd) override {
            switch (cmd.action ()) {

                case ACTIONS::ACTIVATE: {
                    for (size_t i = 0; i < arr.size (); ++i) {
                        arr[i] -> activate ();
                    }
                }break;

                case ACTIONS::DEACTIVATE: {
                    for (size_t i = 0; i < arr.size (); ++i) {
                        arr[i] -> deactivate ();
                    }
                }break;

                case ACTIONS::CHANGE_TOOL_COLOR: {
                        GLUT::Color param;
                        cmd.param (&param);
                        color_ = param;
                }break;

                case ACTIONS::GET_TOOL_COLOR: {
                        GLUT::Color *param;
                        cmd.param (&param);
                        *param = color_;
                }break;

                default:
                break;
            }
        }

        // void add (Widget *entity) {
        //     if (color_ == nullptr)
        //         color_ = dynamic_cast <GLUT::Color *> (entity);
        //     arr.push_back (entity);
        // }

    private:
        GLUT::Color color_ = GLUT::RED; 
};



class Canvas_Man : public Manager {

    public:

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

                case COLOR: {
                    switch (cmd.action ()) {

                    case ACTIONS::CHANGE_BACKGROUND: {
                            // logger.log (__PF);
                            
                            // send_cmd_up <int> (cmd);
                            GLUT::Color param;
                            cmd.param (static_cast <void *> (&param));
                            canvas_->change_background (param);
                        }break;

                        default: {
                        }break;
                    }
                }break;

                case POINT: {
                    switch (cmd.action ()) {

                        case ACTIONS::USE_TOOL: {
                            // logger.log (__PF);
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
                            // if (cmd.from () != parent_)
                                send_cmd_up (cmd);
                            // fprintf (stderr, "CANVAS MAN: %x FROM %x\n", this, cmd.from ());
                            // logger.log (__PF);
                        }break;

                        default: {
                        }break;
                    }
                }break;

                case ENTITY_PTR_PTR: {
                    switch (cmd.action ()) {
                        case ACTIONS::GET_ENTITY_CANVAS: {
                            
                            // logger.log (__PF);
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