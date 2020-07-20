#include <iostream>
#include <cassert>

#include "ComplexMatrix.hpp"

int main() {

    std::cout << "Addition and Scalar Multiplication: ";
    {
        std::cout << std::endl;
        ComplexMatrix<4,4> cv = {
            {ComplexNum(6, -4), ComplexNum(7, 3), ComplexNum(4, -8), ComplexNum(0, -3)},
            {ComplexNum(16, 2), ComplexNum(0, -7), ComplexNum(6, 0), ComplexNum(0, -4)}
        };
        //std::cout << cv << std::endl; // print test
        
        ComplexMatrix<4,4> cw = {
            {ComplexNum(0, 3), ComplexNum(1, 1), ComplexNum(-12, 4), ComplexNum(-1, -1)},
            {ComplexNum(7, 7), ComplexNum(-9, 18), ComplexNum(0, 0), ComplexNum(2, 3)}
        };
        //std::cout << cw << std::endl; // print test

        ComplexMatrix<4,4> sum = {
            {ComplexNum(6, -1), ComplexNum(8, 4), ComplexNum(-8, -4), ComplexNum(-1, -4)},
            {ComplexNum(23, 9), ComplexNum(-9, 11), ComplexNum(6, 0), ComplexNum(2, -1)}
        };
        
        //std::cout << sum << std::endl; // print test
        assert(cv+cw == sum);

        ComplexMatrix<4,4> z;
        assert(z == sum + sum.getAdditiveInverse());
        assert(sum+z+cw == sum+cw);
    }
    std::cout << "passed" << std::endl;

    return 0;
}
