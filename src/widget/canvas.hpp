#ifndef CANVAS_HPP
#define CANVAS_HPP


#include "../widget/widget.hpp"
#include "../cmd/use.hpp"
#include "../cmd/get_file_input.hpp"

#include <fstream>

struct Canvas_Param {
    Point pnt;
};

class Canvas : public Widget {

    public:        
        ~Canvas () {
            Logger::Instance()->log(__PF);
        }

        Canvas (Coords coords, GLUT::Color color, Widget *parent) :
            Widget (coords, parent), color_ (color), coords_ (coords)
        {
            Logger::Instance()->log(__PF);
            init ();
        }
        
        void save_to_file (const std::string &out) {
            
            std::fstream file_output;
            file_output.open (out, std::fstream::out);
            if (file_output.fail ()) {
                Logger::Instance () -> log (__PF, 2, "unable to create file with given name");
                std::terminate ();
            }
            
            write_all_to_file (file_output);

            file_output.close ();
            if (file_output.fail ()) {
                Logger::Instance () -> log (__PF, 2, "unable to gracefully close file with given name");
            }
                Logger::Instance () -> log (__PF, 2, "SUCCESS");
        
        }
        
        void retrieve_from_file (const std::string &in) {

            std::fstream file_input;
            file_input.open (in, std::fstream::in);
            if (file_input.fail ()) {
                Logger::Instance () -> log (__PF, 2, "unable to open file with given name");
                std::terminate ();
            }

            GLUT::Entity entity;
            
            uint32_t color;
            
            while (!file_input.eof ()) {
                file_input  >> entity.info.bounds.left >> entity.info.bounds.top 
                    >> color;

                // entity.info.color = new_color;
                GLUT::Color new_color (color);
            
                init_dot (Point {entity.info.bounds.left, entity.info.bounds.top}, new_color);
            }

            file_input.close ();
            if (file_input.fail ()) {
                Logger::Instance () -> log (__PF, 2, "unable to gracefully close file with given name");
            }
                Logger::Instance () -> log (__PF, 2, "SUCCESS");

        }

        void init () override {
            canvas_ = (GLUT::GL::Instance()->init_canvas (coords_, color_));
        }

        void init_dot (Point pnt, GLUT::Color color) {
            Logger::Instance() -> log (__PF);
            entities_.push_back (GLUT::GL::Instance ()-> init_dot (pnt, color));
        }

        void draw () override {
            GLUT::GL::Instance ()-> draw (canvas_.drawable);
            
            for (size_t i = 0; i < entities_.size (); i++)
                GLUT::GL::Instance ()-> draw (entities_[i].drawable);
        }

        bool on_mouse_release (int x, int y) override {
            if (check_bound (x, y)) {

                fprintf (stderr, "RELEASE IN CANVAS!!!!\n");

                Canvas_Param *param = new Canvas_Param;
                param->pnt = Point (x, y);

                End_Use_Current_Tool cmd (this, param);
                
                Manager *man = dynamic_cast <Manager *> (parent_); 
                man -> controller (cmd);

                delete param;

                return true;
            }
            return false;
        }

        bool on_mouse_move (int x, int y) override {
            if (check_bound (x, y)) {
                fprintf (stderr, "MOVE IN CANVAS!!!!\n");
                
                Canvas_Param *param = new Canvas_Param;
                param->pnt = Point (x, y);

                Use_Current_Tool cmd (this, param);
                
                Manager *man = dynamic_cast <Manager *> (parent_); 
                man -> controller (cmd);

                delete param;

                return true;
            }
            return false;
        }

        bool on_mouse_press (int x, int y) override {
            if (check_bound (x, y)) {
                fprintf (stderr, "PRESS IN CANVAS!!!!\n");
            
                Canvas_Param *param = new Canvas_Param;
                param->pnt = Point (x, y);

                Start_Use_Current_Tool cmd (this, param);
                
                Manager *man = dynamic_cast <Manager *> (parent_); 
                man -> controller (cmd);

                delete param;

                return true;
            }
            return false;
        }

        void set_color (GLUT::Color color) {
            color_ = color;
        }
        
        void write_all_to_file (std::fstream& out) {
            for (size_t i = 0; i < entities_.size (); i++) {
                switch (entities_[i].type) {
                    case GLUT::Type::DOT:

                        out << entities_[i].info.bounds.left << " " << entities_[i].info.bounds.top 
                            << " " << entities_[i].info.color.toInteger () << "\n";
                        
                    break;

                    default:
                    break;
                }
            }
        }

        private:
            GLUT::Entity canvas_;
            GLUT::Color color_;
            Coords coords_;
};

#endif