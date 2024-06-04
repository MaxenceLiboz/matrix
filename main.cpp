#include "main.hpp"

int main() {
    Vector<float> v1 = Vector<float>(std::vector<float>{1, 2, 3, 4});

    std::cout << v1 << std::endl;

    Matrix<float> m1 = Matrix<float>(2, 2, new float[4]{1, 2, 3, 4});

    std::cout << m1 << std::endl;

    std::cout << m1.toVector() << std::endl;

    std::cout << v1.toMatrix(2, 2) << std::endl;

    Vector<float> v2 = Vector<float>(std::vector<float>{1, 2, 3, 4});

    std::cout << v1.add(v2) << std::endl;
    std::cout << v1.substract(v2) << std::endl;
    std::cout << v1.scaling(2) << std::endl;

    Matrix<float> m2 = Matrix<float>(2, 2, new float[4]{1, 2, 3, 4});
    std::cout << m1.add(m2) << std::endl;
    std::cout << m1.substract(m2) << std::endl;
    std::cout << m1.scaling(2) << std::endl;
    return 0;
}