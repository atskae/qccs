#ifndef QCCS_COMPLEX_MATRIX_H
#define QCCS_COMPLEX_MATRIX_H

/*
    Programming Drills
    ---
    2.2.1: Convert your functions from the last programming drill so that instead of accepting elements by of C^n,
            they accept elements from C^(m*n)
*/

#include "../../ch1/complex/ComplexNum.hpp"

template<unsigned int M, unsigned int N>
class ComplexMatrix {
    private:
        ComplexNum _matrix[M][N];
    public:
        ComplexMatrix<M, N>() {
            for(unsigned int i=0; i<M; i++) {
                for(unsigned int j=0; j<N; j++) {
                    _matrix[i][j] = ComplexNum();
                }
            }
        }
        
        ComplexMatrix(std::initializer_list<std::initializer_list<ComplexNum>> list) {
            unsigned int i=0;
            for(std::initializer_list<ComplexNum> row : list) {
                unsigned int j=0;
                for(ComplexNum cn : row) {
                    _matrix[i][j] = cn;
                    j++;
                }
                i++;
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const ComplexMatrix<M, N>& cv) {
            for(unsigned int i=0; i<M; i++) {
                os << "[";
                for(unsigned int j=0; j<N; j++) {
                    os << cv._matrix[i][j];
                    if(j == N-1) os << "]\n";
                    else os << ", ";
                }
            }
            os << "---";
            
            return os;       
        }
        
        friend bool operator==(const ComplexMatrix<M, N>& cv0, const ComplexMatrix<M, N>& cv1) {
            for(unsigned int i=0; i<M; i++) {
                for(unsigned int j=0; j<N; j++) {
                    if(cv0._matrix[i][j] != cv1._matrix[i][j]) return false;
                }
            }
            return true;   
        }
        
        friend bool operator!=(const ComplexMatrix<M, N>& cv0, const ComplexMatrix<M, N>& cv1) {
            return !(cv0 == cv1);
        }

        void printM() { std::cout << "Vector of dimension " << M << std::endl; }

        // Operators

        ComplexMatrix operator+(const ComplexMatrix& cv) const {
            ComplexMatrix s;
            for(unsigned int i=0; i<M; i++) {
                for(unsigned int j=0; j<N; j++) {
                    s._matrix[i][j] = _matrix[i][j] + cv._matrix[i][j];
                }
            }
            return s;
        }

        // Multiply by a scalar
        ComplexMatrix operator*(const ComplexNum& scalar) const {
            ComplexMatrix p;
            for(unsigned int i=0; i<M; i++) {
                for(unsigned int j=0; j<N; j++) {
                    p._matrix[i][j] = _matrix[i][j] * scalar;
                }
            }
            return p;
        }

        // Additive inverse
        ComplexMatrix getAdditiveInverse() const { return (*this) * ComplexNum(-1, 0); }

}; // Complex Vector<M, N>

#endif // QCCS_COMPLEX_MATRIX_H
