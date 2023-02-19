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

/////////////////////////////////////////////////OPERATORS
        Point operator + (const Point& other) {
            return {get_x () + other.get_x (), get_y () + other.get_y ()};
        }

        Point operator - (const Point& other) {
            return {get_x () - other.get_x (), get_y () - other.get_y ()};
        }
        
};



class Coords {

    public:
        
        Coords () 
            {}

        Coords (Point strt, int width, int height) :
            width_ (width), height_ (height), strt_ (strt)
            {}

        int width () const {
            return width_;
        }

        int height () const {
                return height_;
        }

        Point strt () const {
            return strt_;
        }

        Coords operator + (const Coords& other) {
            return {strt () + other.strt (), width () + other.width (), height () + other.height ()};
        }

        Coords operator - (const Coords& other) {
            return {strt () - other.strt (), width () - other.width (), height () - other.height ()};
        }

        // void set (const Point &strt, int width, int height) {
        //     width_ = width;
        //     strt_ = strt;
        //     height_ = height;
        // }

    private:
        int width_   = 0;
        int height_  = 0;
        Point strt_  = {};
};


#endif