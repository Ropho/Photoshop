#ifndef POINT_HPP
#define POINT_HPP

class Point {

    private:
    
        double x_ = 0;
        double y_ = 0;
    
    public:

        Point () :
            x_ (0), y_ (0)
            {}

        Point (double x_init, double y_init) :
            x_ (x_init), y_ (y_init)
            {}
       
       ~Point () 
            {}

        void set_coord (double x_set, double y_set) {x_ = x_set; y_ = y_set;}
        void set_x (double x_set) {x_ = x_set;}
        void set_y (double y_set) {y_ = y_set;}

        double get_x () const {return x_;}
        double get_y () const {return y_;}
};


#endif