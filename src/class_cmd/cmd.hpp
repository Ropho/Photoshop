#ifndef CMD_HPP
#define CMD_HPP
#include <typeinfo>

    enum ACTIONS {
        NO_ACTION               = 0,
        CHANGE_BACKGROUND       = 1,
        SET_CURRENT             = 2,
        REMOVE_CURRENT          = 3,
        USE_TOOL                = 4,
        ADD_ENTITY              = 5,
        REMOVE_ENTITY           = 6,
        GET_ENTITY_CANVAS       = 7,
        DRAW_CANVAS             = 8,

    };

    enum TYPES {
        NO_TYPE         = 0,
        INT             = 1,
        POINT           = 2,
        ENTITY_PTR      = 3,
        ENTITY_PTR_PTR  = 4,
        NULLPTR         = 5,
    };

    // template <typename T>    
    #define NEW_CMD(action, type, from, param, type_build)                   \
            auto tmp = static_cast <void *> (new type_build (param));         \
            Cmd cmd (action, type, from, tmp)

    #define END_CMD cmd.erase ()

    class Cmd {

        public:
            Cmd (ACTIONS action, TYPES type, void *from, void *param) :
                action_ (action), 
                type_ (type),
                from_ (from),
                param_ (param)
            {
                std::cerr << "PARAM\t TYPE" << param_ << "\n"; 
                // auto tmp = new typeid(*param).name();
            }
            
            Cmd (Cmd &cmd) {
                std::cerr << "COPY CTOR\n";
                // cmd.param_ =
                from_ = cmd.from_;
                param_ = cmd.param_;
                type_ = cmd.type_;
                action_ = cmd.action_;
            }

            Cmd (Cmd &&cmd) {
                std::cerr << "MOVE CTOR\n";
                // cmd.param_ = 
            }
            
            Cmd & operator = (Cmd & cmd) {
                std::cerr << "COPY =\n";
            }

            Cmd & operator = (Cmd && cmd) {
                std::cerr << "MOVE =\n";
            }

            // ~Cmd () {
                // delete param_;
            // }
            void erase () {
                // if (type_ != NULLPTR)
                std::cerr << "CMD DELETED\n";
                delete param_;
            }

            int action () const {
                return action_;
            }
                
            // void *param () const {
                // return param_;
            // }

            void *from () {
                return from_;
            }

            void set_from (void *from) {
                from_ = from;
            }

            TYPES type () {
                return type_;
            }

            void param (void *store) {
                
                    // store = param_;
                switch (type_) {
                case ENTITY_PTR:
                    *(static_cast <GLUT::Entity **> (store)) =  *(static_cast <GLUT::Entity **> (param_));
                    break;

                case INT:
                    *(static_cast <int *> (store)) =  *(static_cast <int *> (param_));
                    break;

                case ENTITY_PTR_PTR:
                    *(static_cast <GLUT::Entity ***> (store)) =  *(static_cast <GLUT::Entity ***> (param_));
                    break;
                
                case POINT:
                    *(static_cast <Point *> (store)) =  *(static_cast <Point *> (param_));
                    break;

                default:
                    std::cerr << "UNKNOWN CMD TYPE: " << type_ << std::endl;
                    std::terminate ();
                    break;
                }

                // std::cerr << *store;
            }

            void info () {
                std::cerr << "POINTER TO PARAM: " << param_ << "\n";
                // std::terminate ();
            }

        private:
            ACTIONS action_ = NO_ACTION;
            TYPES type_     = NO_TYPE;
            void *from_     = nullptr;
            void *param_    = nullptr;
    };


#endif