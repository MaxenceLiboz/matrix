#include "Vector.hpp"
#include "Matrix.hpp"

void run_trace() {

    std::cout << "Matrix multiplication of vector" << std::endl;

    Matrix<float> m1 = Matrix<float>({{1, 0}, {0, 1}});
    std::cout << "m1: " << std::endl << m1;
    std::cout << "m1.trace(): " << m1.trace() << std::endl << std::endl;

    Matrix<float> m2 = Matrix<float>({{2,-5, 0}, {4, 3, 7}, {-2, 3, 4}});
    std::cout << "m2: " << std::endl << m2;
    std::cout << "m2.trace(): " << m2.trace() << std::endl << std::endl;

    Matrix<float> m3 = Matrix<float>({{-2, -8, 4}, {1, -23, 4}, {0, 6, 4}});
    std::cout << "m3: " << std::endl << m3;
    std::cout << "m3.trace(): " << m3.trace() << std::endl << std::endl;
}


int main() {
    run_trace();
    return 0;
}