#include "vector.hpp"

int main (void) {

    //explicit needed
    // vector <int> vec = 3;
    // printf ("%ld\n", size_t (2) * size_t (3));

    vector <int> vec (3);

    // vec[1] = 5;
    // int x = vec[1];
    for (int i = 0; i < vec.size (); ++i)
        printf ("%d ", vec[i]);

    return 0;
}