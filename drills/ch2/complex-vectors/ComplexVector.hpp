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
        ComplexVector<Dim>() {
            for(unsigned int i=0; i<Dim; i++) {
                _vector[i] = ComplexNum();
            }
        }
        
        ComplexVector(std::initializer_list<ComplexNum> list) {
            unsigned int i=0;
            for(ComplexNum cn : list) {
                _vector[i] = cn;
                i++;
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const ComplexVector<Dim>& cv) {
            os << "[";
            for(unsigned int i=0; i<Dim; i++) {
                os << cv._vector[i];
                if(i == Dim-1) os << "]";
                else os << ", ";
            }
            return os;       
        }
        
        friend bool operator==(const ComplexVector<Dim>& cv0, const ComplexVector<Dim>& cv1) {
            for(unsigned int i=0; i<Dim; i++) {
                if(cv0._vector[i] != cv1._vector[i]) return false;
            }
            return true;   
        }
        
        friend bool operator!=(const ComplexVector<Dim>& cv0, const ComplexVector<Dim>& cv1) {
            return !(cv0 == cv1);
        }

        void printDim() { std::cout << "Vector of dimension " << Dim << std::endl; }

        // Operators

        ComplexVector operator+(const ComplexVector& cv) const {
            ComplexVector s;
            for(unsigned int i=0; i<Dim; i++) {
                s._vector[i] = _vector[i] + cv._vector[i];
            }
            return s;
        }

        // Multiply by a scalar
        ComplexVector operator*(const ComplexNum& scalar) const {
            ComplexVector p;
            for(unsigned int i=0; i<Dim; i++) {
                p._vector[i] = _vector[i] * scalar;
            }
            return p;
        }

}; // Complex Vector<Dim>

#endif // QCCS_COMPLEX_VECTOR_H
