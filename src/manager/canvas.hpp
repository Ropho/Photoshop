#include "manager.hpp"
#include "../widget/canvas.hpp"

class Canvas_Man : public Manager {

    public:

        Canvas_Man (Widget *parent) :
            Manager (parent)
        {
            Logger::Instance()->log(__PF);
        }

        ~Canvas_Man () {
            Logger::Instance()->log(__PF);
        }

        void controller (Abstract_Cmd &cmd) {
            switch (cmd.action ()) {
                case ACTIONS::CHANGE_BACKGROUND:
                    cmd.execute (canvas_);
                break;

                case ACTIONS::START_USE_CURRENT_TOOL:
                    send_cmd_up (cmd);
                break;

                case ACTIONS::USE_CURRENT_TOOL:
                    send_cmd_up (cmd);
                break;

                case ACTIONS::END_USE_CURRENT_TOOL:
                    send_cmd_up (cmd);
                break;

                default:
                break;
            }
        }

        void add (Widget *entity) override {
            if (canvas_ == nullptr) {
                canvas_ = dynamic_cast <Canvas *> (entity);
            }
            arr.push_back (entity);
        }

        private:
            Canvas *canvas_ = nullptr;
};
