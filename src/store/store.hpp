#ifndef STORE_HPP
#define STORE_HPP


#include "../manager/manager.hpp"
// #include "../log/log.hpp"
// #include "../graph_lib/lib.hpp"
#include <unordered_map>

class Store : public Manager {

    public:

        ~Store () {

            Logger::Instance()->log(__PF);
            // for (auto it = entities.begin (); it != entities.end (); ++it)
                // delete (it->second);
            Logger::Instance()->log(__PF);
        }

        Store (Widget *parent) :
            Manager (parent)
        {
            Logger::Instance()->log(__PF);
        }
        
        // void close ();
        // void move  ();

        // void controller (Cmd cmd) override {
        //     switch (cmd.action ()) {

        //         case ACTIONS::ADD_ENTITY: {
        //             logger.log (__PF);

        //             cmd.execute (this);
        //             // GLUT::Entity* param;
        //             // cmd.param (&param);

        //             // std::cerr << param;
        //             // std::terminate ();
        //             // add (param);
        //         }break;

        //         case ACTIONS::GET_ENTITY_CANVAS: {
                    
        //             // add (cmd.param ());

        //             GLUT::Entity ** param;
        //             cmd.param (&param);
        //             *param = canvas_;
        //             logger.log (__PF);
        //         }break;

        //         case ACTIONS::DRAW_CANVAS: {
                    
        //             // std::cerr << canvas_ << " \t CANVAS SPRITE\n";
        //             gl.draw (canvas_);
        //             for (size_t i = 0; i < entities.size (); ++i) {
        //                 gl.draw (entities[i]);
        //             }
        //         }break;

        //         default:
        //         break;
        //     }
        // }

        void add (GLUT::Entity *entity) {
            
            Logger::Instance()->log(__PF);

            // entities.insert ()
            // if (canvas_ == nullptr)
                // canvas_ = entity;
            // else {
                // entities.push_back (entity);
            // }
        }

        void remove () {
            // entities.find ()
            // entites.erase ()
        }

        private:
            std::unordered_map <std::string, GLUT::Entity *> entities {};

            // std::unordered_map <GLUT::Entity *> entities {};
            GLUT::Entity *canvas_       = nullptr;
            // GLUT::Entity *background    = nullptr;
};

#endif