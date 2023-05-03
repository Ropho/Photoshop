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
            delete (canvas_.drawable);
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
                Logger::Instance () -> log (__PF, LOG_LVL::FATAL, "unable to create file with given name");
                std::terminate ();
            }
            
            write_all_to_file (file_output);

            file_output.close ();
            if (file_output.fail ()) {
                Logger::Instance () -> log (__PF, LOG_LVL::ERROR, "unable to gracefully close file with given name");
            }
                Logger::Instance () -> log (__PF, LOG_LVL::TRACE, "SUCCESS WRITING TO FILE");        
        }
        
        void retrieve_from_file (const std::string &in) {

            std::fstream file_input;
            file_input.open (in, std::fstream::in);
            if (file_input.fail ()) {
                Logger::Instance () -> log (__PF, LOG_LVL::FATAL, "unable to open file with given name");
                std::terminate ();
            }

            GLUT::Entity entity; 
            uint32_t color;
            int type;
            
            while (!file_input.eof ()) {
                file_input >> type;
                
                switch (GLUT::Type (type)) {
                    
                    case GLUT::Type::DOT: {
                        file_input  >> entity.info.bounds.left >> entity.info.bounds.top 
                            >> color;

                        GLUT::Color new_color (color);                    
                        init_dot (Point {entity.info.bounds.left, entity.info.bounds.top}, new_color);
                    } break;

                    case GLUT::Type::RECT: {
                        Logger::Instance () -> log (__PF, LOG_LVL::FATAL, "not handled yet type");
                        std::terminate ();
                    } break;

                    case GLUT::Type::BACKGROUND: {
                        file_input >> color;
                        update_background (GLUT::Color (color));
                    } break;

                    default:
                        Logger::Instance () -> log (__PF, LOG_LVL::FATAL, "unknown type");
                        std::terminate ();
                    break;
                }
            }

            file_input.close ();
            if (file_input.fail ()) {
                Logger::Instance () -> log (__PF, LOG_LVL::ERROR, "unable to gracefully close file with given name");
            }
                Logger::Instance () -> log (__PF, LOG_LVL::TRACE, "SUCCESS READING FROM FILE");

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

                Logger::Instance () -> log (__PF, LOG_LVL::TRACE, "RELEASE IN CANVAS!!!!");

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
                Logger::Instance () -> log (__PF, LOG_LVL::TRACE, "MOVE IN CANVAS!!!!");
                
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
                Logger::Instance () -> log (__PF, LOG_LVL::TRACE, "PRESS IN CANVAS!!!!");

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

        void update_background (GLUT::Color color) {
            set_color (color);
            delete (canvas_.drawable);
            init ();
        }

        void write_all_to_file (std::fstream& out) {

            // BACKGROUND            
            out << int (GLUT::Type::BACKGROUND) << " " << color_.toInteger () << "\n";
            
            // Entities
            for (size_t i = 0; i < entities_.size (); i++) {
                switch (entities_[i].type) {
                    case GLUT::Type::DOT:

                        out << int (GLUT::Type::DOT) << " " << entities_[i].info.bounds.left << " " << entities_[i].info.bounds.top 
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