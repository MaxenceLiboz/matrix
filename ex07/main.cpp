#include "Vector.hpp"
#include "Matrix.hpp"

void run_matrix_multiplication() {

    std::cout << "Matrix multiplication of vector" << std::endl;

    Matrix<float> m1 = Matrix<float>({{1, 0}, {0, 1}});
    Vector<float> v1 = Vector<float>({4, 2});
    std::cout << "m1: " << std::endl << m1;
    std::cout << "v1: " << std::endl << v1;
    std::cout << "m1 * v1: " << std::endl << m1.mul_vec(v1) << std::endl << std::endl;

    Matrix<float> m2 = Matrix<float>({{2, 0}, {0, 2}});
    std::cout << "m2: " << std::endl << m2;
    std::cout << "v1: " << std::endl << v1;
    std::cout << "m2 * v1: " << std::endl << m2.mul_vec(v1) << std::endl << std::endl;

    Matrix<float> m3 = Matrix<float>({{2, -2}, {-2, 2}});
    std::cout << "m3: " << std::endl << m3;
    std::cout << "v1: " << std::endl << v1;
    std::cout << "m3 * v1: " << std::endl << m3.mul_vec(v1) << std::endl << std::endl;

    Matrix<float> m4 = Matrix<float>({{2, 1}, {4, 2}});
    std::cout << "m1: " << std::endl << m1;
    std::cout << "m4: " << std::endl << m4;
    std::cout << "m1 * m4: " << std::endl << m1.mul_mat(m4) << std::endl << std::endl;

    Matrix<float> m5 = Matrix<float>({{3, -5}, {6, 8}});
    Matrix<float> m6 = Matrix<float>({{2, 1}, {4, 2}});
    std::cout << "m5: " << std::endl << m5;
    std::cout << "m6: " << std::endl << m6;
    std::cout << "m5 * m6: " << std::endl << m5.mul_mat(m6) << std::endl << std::endl;

    Matrix<float> m7 = Matrix<float>({{1, 2, 3}, {4, 5, 6}, {-2, -1, -3}, {2, 1, 5}});
    Matrix<float> m8 = Matrix<float>({{1, 2, 3}, {4, 5, 6}, {-7, 4, -2}});
    std::cout << "m7: " << std::endl << m7;
    std::cout << "m8: " << std::endl << m8;
    std::cout << "m7 * m8: " << std::endl << m7.mul_mat(m8) << std::endl << std::endl;
}


int main() {
    run_matrix_multiplication();
    return 0;
}