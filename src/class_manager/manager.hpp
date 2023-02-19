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

        ~Manager () {
            logger.log (__PF);

            //MAYBE NO USE OF FACTORY
            //CLEARS ON HIS OWN all the stored elements =)
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

    protected:
        vector <Widget *> arr {};
        // std::vector <Widget *> arr {};
        // Widget *kek [100];
};


class Palette : public Manager {

    public:

        Palette (Widget *parent) :
            Manager (parent)
        {
            get_all_tools (tools);

            for (size_t i = 0; i < tools.size (); ++i) {
                map.insert ({tools[i]->name (), tools[i]});
            }

            logger.log (__PF);
        }

        ~Palette () noexcept {

            tools.clear ();

            logger.log (__PF);
        }


        void controller (const Cmd <int> & cmd) {
        
            switch (cmd.action ()) {

                case ACTIONS::SET_CURRENT: {
                    current_action = map.find (cmd.param ()) -> second;
                    logger.log (__PF);
                }break;

                case ACTIONS::REMOVE_CURRENT: {
                    current_action = nullptr;
                    logger.log (__PF);
                }break;

               case ACTIONS::SET_COLOR: {
                    canvas_->set_color (cmd.param ());
                    logger.log (__PF);
                }break;
            
                default: {
                }break;
            }

        }

        void controller (const Cmd <Point> & cmd) {

            switch (cmd.action ()) {

                case ACTIONS::USE_TOOL: {
                    if (current_action != nullptr)
                        current_action->action (cmd.param ());

                    logger.log (__PF);
                }break;

                default: {
                }break;
            }
        }


        void add (Widget *button) {
            arr.push_back (button);
        }

        void add_canvas (Widget *canvas) {
            canvas_ = (Canvas *)canvas;
        }


        private:
            Canvas *canvas_ = nullptr;

            vector <Tool *> tools {};
            std::unordered_map <int, Tool *> map {};
            Tool *current_action = nullptr;
};

#endif