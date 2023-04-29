#ifndef CMD_HPP
#define CMD_HPP

#include "../widget/widget.hpp"

    enum class ACTIONS {
        NO_ACTION               = 0,
        CHANGE_BACKGROUND       = 1,
        SET_CURRENT             = 2,
        REMOVE_CURRENT          = 3,
        START_USE_CURRENT_TOOL      = 4,
        USE_CURRENT_TOOL            = 5,
        END_USE_CURRENT_TOOL        = 6,
        SET_TOOL_COLOR          = 7,
        ACTIVATE                = 8,
        DEACTIVATE              = 9,
        // ADD_ENTITY              = 5,
        // REMOVE_ENTITY           = 6,
        // GET_ENTITY_CANVAS       = 7,
        // DRAW_CANVAS             = 8,
        // CHANGE_TOOL_COLOR       = 9,
        // GET_TOOL_COLOR          = 10,
    };

    // enum class TYPES {
    //     NO_TYPE         = 0,
    //     INT             = 1,
    //     POINT           = 2,
    //     ENTITY_PTR      = 3,
    //     ENTITY_PTR_PTR  = 4,
    //     NULLPTR         = 5,
    //     TOOL_PTR        = 6,
    //     COLOR_PTR       = 7,
    //     COLOR           = 8,
    // };


    class Abstract_Cmd {
        public:
        
            Abstract_Cmd (void *parent, ACTIONS action, void *param) :
            parent_ (parent), action_ (action), param_ (param)
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

            virtual void set_param (void *param) {
                param_ = param;
            }
            void *param () {
                return param_;
            }
        protected:
            mutable void *parent_ = nullptr;
            ACTIONS action_ = ACTIONS::NO_ACTION;
            void *param_ = nullptr;
    };

#endif