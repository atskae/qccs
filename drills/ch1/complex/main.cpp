#include <iostream>
#include <cassert>

#include "ComplexNum.hpp"

int main() {
    
    std::cout << "Addition: ";
    {
        ComplexNum a(7, 3);
        ComplexNum b(-5, -4);
        
        ComplexNum c = a+b;
        assert(c == ComplexNum(2, -1));
        assert(c+c == ComplexNum(4, -2));

        ComplexNum z(0, 0);
        assert(a+b+z == a+b);
        assert(z+z+z == z);
    }
    std::cout << "passed" << std::endl;

    std::cout << "Multiplication: ";
    {
        ComplexNum a(-9, 8);
        ComplexNum b(-2, 3);
        
        ComplexNum c = a*b;
        assert(c == ComplexNum(-6, -43));
        assert(c*c == ComplexNum(-1813, 516));

        ComplexNum z(0, 0);
        assert(a*b*c*z == z);
    }
    std::cout << "passed" << std::endl;

    std::cout << "Subtraction: ";
    {
        ComplexNum a(3, -7);
        ComplexNum b(-8, -19);
        
        ComplexNum c = a-b;
        assert(c == ComplexNum(11, 12));
        assert(c-c == ComplexNum(0, 0));
        assert(c-c+(a+b) == a+b);
        assert(a+a-a == a);

        ComplexNum z(0, 0);
        assert(a+b-z == a+b);
        assert(z-z == z);
    }
    std::cout << "passed" << std::endl;

    return 0;
}
