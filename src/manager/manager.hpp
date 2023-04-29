#ifndef MANAGER_HPP
#define MANAGER_HPP


// #include "../widget/widget.hpp"
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

        void send_cmd_down (Abstract_Cmd &cmd) {
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

        void send_cmd_up (Abstract_Cmd &cmd) {
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

       virtual void controller (Abstract_Cmd &cmd) {
            std::cerr << "NOT SUPPOSED TO BE CALLED\n";
            std::terminate ();
        };

        void activate () {
            for (size_t i = 0; i < arr.size (); i++)
                arr[i]->activate ();
        }
        void deactivate () {
            for (size_t i = 0; i < arr.size (); i++)
                arr[i] -> deactivate ();
        }


    protected:
        std::vector <Widget *> arr {};
};

#endif