#ifndef QCCS_COMPLEX_NUM_H
#define QCCS_COMPLEX_NUM_H

/*
    Programming Drills
    ---
    1.1.1: Write a program that accepts two complex numbers and outputs their sum and their product.
    1.2.1: Take the program that you wrote in the last programming drill and make it also perform
                subtraction and division of complex numbers. In addition, let the user enter a complex
                number and have the computer return its modulus and conjugate.
*/

#include <string>
#include <ostream>

#include <math.h> // sqrt()

// Numbers that have the form a+bi, where a is the real part, b is the imaginary part, and i is the sqrt(-1)
class ComplexNum {
    private:
        int _real; // real part
        int _img; // imaginary part

    public:
        ComplexNum(): _real(0), _img(0) {}
        ComplexNum(int real, int img): _real(real), _img(img) {}

        friend std::ostream& operator<<(std::ostream& os, const ComplexNum& cn);
        friend bool operator==(const ComplexNum& cn0, const ComplexNum& cn1);
        friend bool operator!=(const ComplexNum& cn0, const ComplexNum& cn1);

        // Operations on complex numbers
        ComplexNum operator+(const ComplexNum& cn) {
            return ComplexNum(_real + cn._real, _img + cn._img);
        }
       
        ComplexNum operator*(const ComplexNum& cn) {
            int real = (_real * cn._real) + (_img * cn._img * -1);
            int img = (_real * cn._img) + (_img * cn._real);
            return ComplexNum(real, img);
        }

        ComplexNum operator-(const ComplexNum& cn) {
            return ComplexNum(_real - cn._real, _img - cn._img);
        }

        ComplexNum operator/(const ComplexNum& cn) {
            int denom = (cn._real * cn._real) + (cn._img * cn._img);
            int real = ((_real * cn._real) + (_img * cn._img)) / denom;
            int img = ((cn._real * _img) - (_real * cn._img)) / denom;
            return ComplexNum(real, img);
        }

        ComplexNum getConjugate() { return ComplexNum(_real, _img * -1); }
        
        double getModulus() { return sqrt(_real*_real + _img*_img); }

}; // class ComplexNum

std::ostream& operator<<(std::ostream& os, const ComplexNum& cn) {
    std::string op = "";
    if(cn._img >= 0) op = "+";
    return os << cn._real  << op << cn._img << "i";
}

bool operator==(const ComplexNum& cn0, const ComplexNum& cn1) {
    return (cn0._real == cn1._real) && (cn0._img == cn1._img);
}

bool operator!=(const ComplexNum& cn0, const ComplexNum& cn1) {
    return !(cn0 == cn1);
}

#endif // QCCS_COMPLEX_NUM_H
