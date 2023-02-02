#ifndef CMD_HPP
#define CMD_HPP


    enum ACTIONS {

        SET_COLOR   = 1,
        SET_CURRENT = 2,
        
        USE_TOOL    = 3,
        
    };


    template <typename T>    
    class Cmd {

        public:
            Cmd (int action, T param) :
                action_ (action), param_ (param)
            {}
            
            int action () const {
                return action_;
            }
                
            T param () const {
                return param_;
            }

        private:
            int action_ = 0;
            T param_  {};
    };


#endif