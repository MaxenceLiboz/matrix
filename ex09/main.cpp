#include "Vector.hpp"
#include "Matrix.hpp"

void run_transpose() {

    std::cout << "Matrix transposition" << std::endl;

    Matrix<float> m1 = Matrix<float>({{1, 2, 3, 4}, {5, 6, 7, 8}});
    std::cout << "m1: " << std::endl << m1;
    std::cout << "m1.transpose(): " << std::endl << m1.transpose();

    Matrix<float> m2 = Matrix<float>({{2,-5, 0}, {4, 3, 7}, {-2, 3, 4}, {1, 0, 0}});
    std::cout << "m2: " << std::endl << m2;
    std::cout << "m2.transpose(): " << std::endl << m2.transpose();

    Matrix<float> m3 = Matrix<float>({{-2, -8, 4}, {1, -23, 4}, {0, 6, 4}});
    std::cout << "m3: " << std::endl << m3;
    std::cout << "m3.transpose(): " << std::endl << m3.transpose();
}


int main() {
    run_transpose();
    return 0;
}