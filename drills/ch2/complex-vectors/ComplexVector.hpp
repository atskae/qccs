#ifndef QCCS_COMPLEX_VECTOR_H
#define QCCS_COMPLEX_VECTOR_H

/*
    Programming Drills
    ---
    2.1.1: Write three functions that perform the addition, inverse, and scalar multiplication operations for C^n,
            i.e., write a function that accepts the appropriate input for each of the operations and outputs the vector.
    
*/

#include <iostream>

#include "../../ch1/complex/ComplexNum.hpp"

template<unsigned int Dim>
class ComplexVector {
    private:
        ComplexNum _vector[Dim];
    public:
        ComplexVector<Dim>() {}
        
        void printDim() { std::cout << "Vector of dimension " << Dim << std::endl; }

}; // Complex Vector<Dim>

#endif // QCCS_COMPLEX_VECTOR_H
