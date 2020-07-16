#include <iostream>
#include <cassert>

#include "ComplexNum.hpp"

#define ABS(N) ((N < 0) ? (N*-1) : (N))
#define FLOAT_DIFF 0.0001f 
#define FLOAT_EQUAL(a, b) (ABS(a-b) < FLOAT_DIFF)

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

    std::cout << "Division: ";
    {
        ComplexNum a(-2, 1);
        ComplexNum b(1, 2);
        
        ComplexNum c = a/b;
        assert(c == ComplexNum(0,1));

        ComplexNum id(1, 0); // identity
        assert(a/id == a && b/id == b);
        assert((a+b-c)/id == (a+b-c+ComplexNum(0,0)));
       
        // Not sure how to test with fractions...
    }
    std::cout << "passed" << std::endl;

    std::cout << "Conjugate: ";
    {
        ComplexNum a(-7, 4);
        ComplexNum b(8, -14);
    
        ComplexNum ac = a.getConjugate();
        ComplexNum bc = b.getConjugate();

        assert(ac == ComplexNum(-7, -4));
        assert(bc == ComplexNum(8, 14));

        assert(ac * bc == (a*b).getConjugate());
        
        // multiplying by (-1,0) flips the sign of both the real and imaginary parts
        assert(a * ComplexNum(-1, 0) == ComplexNum(7, -4));
        assert(b * ComplexNum(-1, 0) == ComplexNum(-8, 14));
        
        assert(ac + bc == (a+b).getConjugate());
        
        // modulus squared
        ComplexNum d(3, 4);
        assert(d * d.getConjugate() == ComplexNum(25, 0));
    }
    std::cout << "passed" << std::endl;

    std::cout << "Modulus: ";
    {
        ComplexNum a(3, 4);
        assert(FLOAT_EQUAL(a.getModulus(), 5.0));

        ComplexNum b(7, -8);
        assert(FLOAT_EQUAL(b.getModulus(), 10.6301));
        assert(FLOAT_EQUAL(b.getModulus(), (b*ComplexNum(-1,0)).getModulus()));
    }
    std::cout << "passed" << std::endl;

    std::cout << "Cartesian/Polar conversion: ";
    {
        ComplexNum a(1, 1);
        std::cout << std::endl << a << std::endl;
        std::cout << "Cartesian: " << a.getCartesianRep() << std::endl;
        std::cout << "Polar: " << a.getPolarRep() << std::endl;

        assert(FLOAT_EQUAL(a.getModulus(), sqrt(2)));
        assert(FLOAT_EQUAL(a.getAngle(), M_PI/4));
    }
    std::cout << "passed" << std::endl;

    return 0;
}
