#ifndef CMD_HPP
#define CMD_HPP

// #include "../../src/tool/tool.hpp"
// #include "../store/store.hpp"
#include "../widget/widget.hpp"
// #include "string"
// namespace cmd {

    enum class ACTIONS {
        NO_ACTION               = 0,
        CHANGE_BACKGROUND       = 1,
        SET_CURRENT             = 2,
        REMOVE_CURRENT          = 3,
        USE_TOOL                = 4,
        ADD_ENTITY              = 5,
        REMOVE_ENTITY           = 6,
        GET_ENTITY_CANVAS       = 7,
        DRAW_CANVAS             = 8,
        CHANGE_TOOL_COLOR       = 9,
        GET_TOOL_COLOR          = 10,
        ACTIVATE                = 11,
        DEACTIVATE              = 12,
    };

    enum class TYPES {
        NO_TYPE         = 0,
        INT             = 1,
        POINT           = 2,
        ENTITY_PTR      = 3,
        ENTITY_PTR_PTR  = 4,
        NULLPTR         = 5,
        TOOL_PTR        = 6,
        COLOR_PTR       = 7,
        COLOR           = 8,
    };


    class Abstract_Cmd {
        public:
        
            Abstract_Cmd (void *parent, ACTIONS action) :
            parent_ (parent), action_ (action)
             {
                Logger::Instance () ->log (__PF);
             }
            virtual ~Abstract_Cmd () {
                Logger::Instance () ->log (__PF);
            }
        
            virtual void execute (Widget *argument) = 0;

            ACTIONS action () {
                return action_;
            }

            void set_parent (void *parent){
                parent_ = parent;
            }
            void *from () {
                return parent_;
            }

        protected:
            mutable void *parent_ = nullptr;
            ACTIONS action_ = ACTIONS::NO_ACTION;
    };


    // class Add_entity : public Cmd {

    //     Add_entity (GLUT::Entity *entity, const std::string &key, void *parent) :
    //     Cmd (parent), entity_ (entity), key_ (key)
    //     {
    //         Logger::Instance()->log (__PF);
    //     }

    //     // void execute (Store *argument) override {
    //     //     // Store *store = static_cast <Store *> (argument)

    //     //     store->add (entity_);
    //     // };
    //     // void execute (int *argument) override {
    //     //     // Store *store = static_cast <Store *> (argument)

    //     //     store->add (entity_);
    //     // };
    //     private:
    //         GLUT::Entity *entity_ = nullptr;
    //         std::string key_ {};
    // };



//     class Cmd {
//         public:
//             Cmd (ACTIONS action, TYPES type, void *from) :
//                 action_ (action), 
//                 type_ (type),
//                 from_ (from),
//             {
//                 // std::cerr << "PARAM\t TYPE" << param_ << "\n"; 
//             }
            
//             Cmd (Cmd &cmd) {
//                 // std::cerr << "COPY CTOR\n";
//                 from_   = cmd.from_;
//                 param_  = cmd.param_;
//                 type_   = cmd.type_;
//                 action_ = cmd.action_;
//             }

//             Cmd (Cmd &&cmd) = delete;
//             // {
//             //     std::cerr << "MOVE CTOR\n";
//             //     // cmd.param_ = 
//             // }
            
//             Cmd & operator = (Cmd & cmd) = delete; 
//             // {
//             //     std::cerr << "COPY =\n";
//             //     //IMPLEMENT OPERATOR = !!!
//             //     return cmd;
//             // }

//             Cmd & operator = (Cmd && cmd) = delete; 
//             // {
//             //     std::cerr << "MOVE =\n";
//             // }

//             // ~Cmd () {
//                 // delete param_;
//             // }

//             void erase () {
//                 // std::cerr << "CMD DELETED\n";

//                 switch (type_) {

//                 case COLOR: {
//                         delete  (static_cast <GLUT::Color *> (param_));
//                     }break;

//                 case COLOR_PTR:
//                     delete (static_cast <GLUT::Color **> (param_));
//                     break;

//                 case TOOL_PTR:
//                     delete (static_cast <Tool **> (param_));
//                     break;

//                 case ENTITY_PTR:
//                     delete (static_cast <GLUT::Entity **> (param_));
//                     break;

//                 case INT:
//                     delete (static_cast <int *> (param_));
//                     break;

//                 case ENTITY_PTR_PTR:
//                     delete (static_cast <GLUT::Entity ***> (param_));
//                     break;
                
//                 case POINT:
//                     delete (static_cast <Point *> (param_));
//                     break;
                
//                 case NULLPTR:
//                 break;

//                 default:
//                     std::cerr << "UNKNOWN CMD TYPE: " << type_ << std::endl;
//                     std::terminate ();
//                     break;
//                 }
//             }

//             int action () const {
//                 return action_;
//             }

//             void *from () {
//                 return from_;
//             }

//             void set_from (void *from) {
//                 from_ = from;
//             }

//             TYPES type () {
//                 return type_;
//             }

//             void *raw () {
//                 return param_;
//             }

//             void param (void *store) {
                
//                 switch (type_) {

//                     case COLOR: {
//                         *(static_cast <GLUT::Color *> (store)) =  *(static_cast <GLUT::Color *> (param_));
//                     }break;

//                     case COLOR_PTR: {
//                         *(static_cast <GLUT::Color **> (store)) =  *(static_cast <GLUT::Color **> (param_));
//                     }break;

//                     case TOOL_PTR: {
//                         *(static_cast <Tool **> (store)) =  *(static_cast <Tool **> (param_));
//                     }break;

//                     case ENTITY_PTR: {
//                         *(static_cast <GLUT::Entity **> (store)) =  *(static_cast <GLUT::Entity **> (param_));
//                     }break;

//                     case INT: {
//                         *(static_cast <int *> (store)) =  *(static_cast <int *> (param_));
//                     }break;

//                     case ENTITY_PTR_PTR: {
//                         *(static_cast <GLUT::Entity ***> (store)) =  *(static_cast <GLUT::Entity ***> (param_));
//                     }break;
                    
//                     case POINT: {
//                         *(static_cast <Point *> (store)) =  *(static_cast <Point *> (param_));
//                     }break;

//                     default: {
//                         std::cerr << "UNKNOWN CMD TYPE: " << type_ << std::endl;
//                         std::terminate ();
//                     }break;
//                 }
//             }

//         private:
//             ACTIONS action_ = NO_ACTION;
//             TYPES type_     = NO_TYPE;
//             void *from_     = nullptr;
//             void *param_    = nullptr;
//     };

// // }

#endif