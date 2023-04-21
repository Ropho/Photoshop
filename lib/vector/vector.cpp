#include "vector.hpp"

int main (void) {

    //explicit needed
    // vector <int> vec {};
    // printf ("%ld\n", size_t (2) * size_t (3));

    // vector <int> kek (10, 1);
    // vector <int> kek (1);
    // vector <int> vec (vector <int> (10, 2));
    
    //ПОЧЕМУ ТУТ PARAM CTOR!!!!
    // vector <int> vec = vector <int> (5, 2);

    // vec = kek;
    // vec = vector <int> (5, 0);
    // vec[1] = 5;
    // int x = vec[1];

    vector <int> vec {};
    vec.push_back (10);
    std::cout << vec.pop_back () << '\n';

    printf ("\nSIZE: %ld\nCAP %ld\nDATA: ", vec.size (), vec.cap ());
    for (int i = 0; i < vec.size (); ++i)
        printf ("%d ", vec[i]);

    puts ("\nSUCCESS");

    return 0;
}