#include "Vector.hpp"
#include "Matrix.hpp"

void run_determinant() {

    std::cout << "Matrix row echelon form" << std::endl;

    Matrix<float> m1 = Matrix<float>({{1, -1}, {-1, 1}});
    std::cout << "m1: " << std::endl << m1;
    std::cout << "Determinant: " << m1.determinant() << std::endl;

    Matrix<float> m2 = Matrix<float>({{2, 0, 0}, {0, 2, 0}, {0, 0, 2}});
    std::cout << "m2: " << std::endl << m2;
    std::cout << "Determinant: " << m2.determinant() << std::endl;

    Matrix<float> m3 = Matrix<float>({{8, 5, -2}, {4, 7, 20}, {7, 6, 1}});
    std::cout << "m3: " << std::endl << m3;
    std::cout << "Determinant: " << m3.determinant() << std::endl;

    Matrix<float> m4 = Matrix<float>({{8, 5, -2, 4}, {4, 2.5, 20, 4}, {8, 5, 1 ,4}, {28, -4, 17, 1}});
    std::cout << "m4: " << std::endl << m4;
    std::cout << "Determinant: " << m4.determinant() << std::endl;

    Matrix<float> m5 = Matrix<float>({{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}});
    std::cout << "m5: " << std::endl << m5;
    std::cout << "Determinant: " << m5.determinant() << std::endl;

    Matrix<float> m6 = Matrix<float>({{1, 2, 3}, {4, 5, 6}});
    std::cout << "m6: " << std::endl << m6;
    std::cout << "Determinant: " << m6.determinant() << std::endl;
}


int main() {
    run_determinant();
    return 0;
}