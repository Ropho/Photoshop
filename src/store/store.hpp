#ifndef STORE_HPP
#define STORE_HPP


#include "../class_manager/manager.hpp"
#include "../log/log.hpp"
#include "../graph_lib/lib.hpp"


class Store : public Manager {

    public:

        ~Store () {
            for (size_t i = 0; i < entities.size (); ++i)
                delete (entities[i]);
            
            logger.log (__PF);
        }

        Store (Widget *parent) :
            Manager (parent)
        {
            logger.log (__PF);
        }
        
        // void close ();
        // void move  ();

        void controller (Cmd cmd) override {

            logger.log (__PF);

            switch (cmd.type ()) {

                case ENTITY_PTR: {
                    switch (cmd.action ()) {

                        case ACTIONS::ADD_ENTITY: {
                            
                            logger.log (__PF);

                            GLUT::Entity* param;
                            cmd.param (&param);

                            // std::cerr << param;
                            // std::terminate ();
                            add (param);
                        }break;

                        default: {
                        }break;
                    }

                }break;

                case ENTITY_PTR_PTR: {
                    switch (cmd.action ()) {

                        case ACTIONS::GET_ENTITY_CANVAS: {
                            
                            // add (cmd.param ());
                            GLUT::Entity ** param;
                            cmd.param (&param);
                            *param = canvas_;
                            logger.log (__PF);
                        }break;

                        default: {
                        }break;
                    }
                }break;

                case NULLPTR: {
                    switch (cmd.action ()) {

                        case ACTIONS::DRAW_CANVAS: {
                            
                            std::cerr << canvas_ << " \t CANVAS SPRITE\n";
                            gl.draw (canvas_);
                            for (size_t i = 0; i < entities.size (); ++i) {
                                gl.draw (entities[i]);
                            }
                        }break;

                        default: {
                        }break;
                    }

                }break;

                default:
                break;
            }
        }
        // void controller (Cmd <GLUT::Entity *> cmd) {

        //     switch (cmd.action ()) {

        //         case ACTIONS::ADD_ENTITY: {
                    
        //             logger.log (__PF);
        //             add (cmd.param ());
        //         }break;

        //         default: {
        //         }break;
        //     }
        // }

        // void controller (Cmd <GLUT::Entity **> cmd) {

        //     switch (cmd.action ()) {

        //         case ACTIONS::GET_ENTITY_CANVAS: {
                    
        //             // add (cmd.param ());
        //             *cmd.param () = canvas_;
        //             logger.log (__PF);
        //         }break;

        //         default: {
        //         }break;
        //     }
        // }

        // void controller (Cmd <nullptr_t> cmd) {

        //     switch (cmd.action ()) {

        //         case ACTIONS::DRAW_CANVAS: {
                    
        //             gl.draw (canvas_);
        //             for (size_t i = 0; i < entities.size (); ++i) {
        //                 gl.draw (entities[i]);
        //             }
        //             // logger.log (__PF);
        //         }break;

        //         default: {
        //         }break;
        //     }
        // }

        void add (GLUT::Entity *entity) {
            
            logger.log (__PF);

            if (canvas_ == nullptr)
                canvas_ = entity;
            else {
                entities.push_back (entity);
            }
            // std::cerr << entity << "\n";
            // std::cerr << canvas_;
            // std::terminate ();
        }

        void remove () {
            // entities.find ()
            // entites.erase ()
        }

        private:
            std::vector <GLUT::Entity *> entities {};
            GLUT::Entity *canvas_ = nullptr;
};

#endif