#include "Vector.hpp"
#include "Matrix.hpp"

void run_vector() {
    Vector<float> v1 = Vector<float>(std::vector<float>{1, 2, 3, 4});
    std::cout << "vector 1: " << std::endl << v1 << std::endl;

    Vector<float> v2 = Vector<float>(std::vector<float>{4, 3, 2, 4});
    std::cout << "vector 2: " << std::endl << v2 << std::endl;

    std::cout << "v1 + v2: " << std::endl << v1.add(v2) << std::endl;
    std::cout << "v1 - v2: " << std::endl << v1.sub(v2) << std::endl;
    std::cout << "v1 * 2: " << std::endl << v1.scl(2) << std::endl;

    Vector<float> v3 = Vector<float>(std::vector<float>{1, 2, 3});
    std::cout << "vector 3: " << std::endl << v3 << std::endl;

    std::cout << "v3 + v2: " << std::endl << v3.add(v2) << std::endl;
    std::cout << "v3 - v2: " << std::endl << v3.sub(v2) << std::endl;
    std::cout << "v3 * 2: " << std::endl << v3.scl(2) << std::endl;
}

void run_matrix() {
    Matrix<float> m1 = Matrix<float>(2, 2, new float[4]{1, 2, 3, 4});
    std::cout << "matrix 1: " << std::endl << m1 << std::endl;

    Matrix<float> m2 = Matrix<float>(2, 2, new float[4]{4, 3, 2, 4});
    std::cout << "matrix 2: " << std::endl << m2 << std::endl;

    std::cout << "m1 + m2: " << std::endl << m1.add(m2) << std::endl;
    std::cout << "m1 - m2: " << std::endl << m1.sub(m2) << std::endl;
    std::cout << "m1 * 2: " << std::endl << m1.scl(2) << std::endl;

    Matrix<float> m3 = Matrix<float>(2, 3, new float[6]{1, 2, 3, 4, 5, 6});
    std::cout << "matrix 3: " << std::endl << m3 << std::endl;

    std::cout << "m3 + m2: " << std::endl << m3.add(m2) << std::endl;
    std::cout << "m3 - m2: " << std::endl << m3.sub(m2) << std::endl;
    std::cout << "m3 * 2: " << std::endl << m3.scl(2) << std::endl;
}

int main() {
    run_vector();
    run_matrix();
    return 0;
}