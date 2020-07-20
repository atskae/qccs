#include <iostream>
#include <cassert>

#include "ComplexVector.hpp"

int main() {

    std::cout << "Addition and Scalar Multiplication: ";
    {
        ComplexVector<4> cv = {ComplexNum(6, -4), ComplexNum(7, 3), ComplexNum(4, -8), ComplexNum(0, -3)};
        ComplexVector<4> cw = {ComplexNum(16, 2), ComplexNum(0, -7), ComplexNum(6, 0), ComplexNum(0, -4)};
        // std::cout << cv << " + " << cw << " = " << (cv+cw) << std::endl; // print test
        
        ComplexVector<4> sum = {ComplexNum(22, -2), ComplexNum(7,-4), ComplexNum(10,-8), ComplexNum(0, -7)};
        assert((cv+cw) == sum);

        assert((cv+cw)+sum == cv+(cw+sum));
        assert(sum+cv == cv+sum);

        ComplexVector<4> z; // zero vector
        assert(sum+z == sum);

        // multiply by scalar
        assert(sum * ComplexNum(0,0) == z);
        assert(sum + (sum*ComplexNum(-1,0)) == z); // additive inverse

        cv = {ComplexNum(6,3), ComplexNum(0,0), ComplexNum(5,1), ComplexNum(4,0)};
        ComplexVector<4> scalarMult = {ComplexNum(12, 21), ComplexNum(0,0), ComplexNum(13,13), ComplexNum(12, 8)};
        assert(cv * ComplexNum(3,2) == scalarMult);
    }
    std::cout << "passed" << std::endl;

    return 0;
}
