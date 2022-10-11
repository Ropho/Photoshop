#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <typename T>
class vector {

    public:

    //    ~vector () {

    //    }


        vector () = default;


        explicit vector (const size_t& size) :
            cap_ (MULTY_ * size), size_ (size)
        {
            cap_ *= MULTY_;

            data_ = (T*) operator new (cap_ * sizeof (T));

            for (int i = 0; i < size_; ++i)
                new (data_ + i) T {};
            // printf ("%ld", *((size_t*)((char*) data_ - 8)));
        }


        vector (const size_t& size, const T& init) :
            size_ (size), cap_ (size)
        {

            cap_ *= MULTY_;

            data_ = (T*) operator new (cap_ * sizeof (T));

            for (int i = 0; i < size_; ++i)
                new (data_ + i) T (init);
        }

        // vector (const vector& vec) :
        //     cap_ (vec.cap (), size_ (vec.size ()))
        // {

        // }

/////////////////////////////////////////////////GETTERS
        size_t cap () const {
            return cap_;
        }

        size_t size () const {
            return size_;
        }

/////////////////////////////////////////////////OPERATORS

    // vec[1] = x;
    T& operator [] (const size_t& index) {
        return data_[index];
    }

    // auto x = vec[1];
    const T& operator [] (const size_t& index) const {
        return data_[index];
    }

    // bool check = false;

    private:
        const size_t MULTY_ = 2;

        size_t cap_  = 0;
        size_t size_ = 0;

        T *data_ = nullptr;

};


#endif