#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "../general.hpp"

#define DUMP 0xDEAD

template <typename T>
class vector {

    public:

/////////////////////////////////////////////////DTOR
        ~vector () {
            LOG ("~VECTOR");

            clear ();
       }

/////////////////////////////////////////////////CTOR
        vector () {
            LOG ("DEFAULT CTOR");
        }


        explicit vector (const size_t& size) :
            cap_ (MULTY_ * size), size_ (size)
        {
            LOG ("SIZE CTOR");

            cap_ *= MULTY_;

            data_ = (T*) operator new (cap_ * sizeof (T));

            for (size_t i = 0; i < size_; ++i)
                new (data_ + i) T {};

        }

        vector (const size_t& size, const T& init) :
            size_ (size), cap_ (size)
        {

            LOG ("PARAM CTOR");

            cap_ *= MULTY_;

            data_ = (T*) operator new (cap_ * sizeof (T));

            for (int i = 0; i < size_; ++i)
                new (data_ + i) T (init);
        }


        vector (const vector& vec) :
            cap_ (vec.cap ()), size_ (vec.size ())
        {
            LOG ("COPY CTOR");

            data_ = (T*) operator new (cap_ * sizeof (T));

            for (size_t i = 0; i < size_; ++i)
                new (data_ + i) T (vec[i]);
        }



        vector (vector&& vec) = delete;

        // vector (vector&& vec) noexcept :
        //     cap_ (vec.cap ()), size_ (vec.size ()), data_ (vec.data ())
        // {
            // LOG ("MOVE CTOR");
         
        //     vec.data_ = nullptr;
        //     vec.cap_  = 0;
        //     vec.size_ = 0;

        //     // for (int i = 0; i < size_; ++i)
        //         // operator[] (i) = 1;
        // }


/////////////////////////////////////////////////DATA
        void push_back (const T& val) {
            
            if (size_ == cap_)
                resize_up ();
            
            new (data_ + size_++) T (val);
            
        }

        T pop_back () {

            if (size_ < cap_ / DELETER_)
                resize_down ();

            T out = data_[size_ - 1];
            data_[size_-- - 1] = DUMP;

            return out;
        }


/////////////////////////////////////////////////MEMORY
        void resize_down () {

            size_t new_cap = cap_ / DELETER_;
            
            for (size_t i = new_cap; ++i; i < cap_) {
                data_[i].~T ();
            }
            cap_ = new_cap;
        }

        void resize_up () {


            vector tmp (size_);
            
            if (cap_ != 0) {
                tmp.cap_ = cap_ * MULTY_;
            }
            else
                tmp.cap_ = 1;

            for (size_t i = 0; i < size_; ++i) {
                tmp[i] = data_[i];
            }

            (*this) = tmp;
        }

        void clear () {

            for (size_t i = 0; i < size_; ++i)
                data_[i].~T ();
            
            operator delete (data_);

            data_ = nullptr;
            size_ = 0;
            cap_  = 0;
        }

/////////////////////////////////////////////////OTHER
        bool empty () {
            return (size_ == 0);
        }

/////////////////////////////////////////////////GETTERS
        size_t cap () const {
            return cap_;
        }

        size_t size () const {
            return size_;
        }

        T* data () const {
            return data_;
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


    vector& operator = (const vector & vec) {

            LOG ("=");

        clear ();

        size_ = vec.size ();
        cap_  = vec.cap  ();

        data_ = (T*) operator new (cap_ * sizeof (T));

        for (size_t i = 0; i < size_; ++i)
            new (data_ + i) T (vec[i]);

        return *this;
    }


    vector& operator = (vector && vec) {

            LOG ("MOVE");

        clear ();

        size_ = vec.size ();
        cap_  = vec.cap  ();
        data_ = vec.data_;

        vec.cap_  = 0;
        vec.size_ = 0;
        vec.data_ = nullptr;

        return *this;
    }

    
    private:

        const size_t MULTY_   = 3;
        const size_t DELETER_ = 2;
        size_t cap_  = 0;
        size_t size_ = 0;

        T *data_ = nullptr;

};


#endif