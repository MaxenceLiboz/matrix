#include "main.hpp"

int main() {
    Vector<float> v1 = Vector<float>(std::vector<float>{1, 2, 3, 4});

    std::cout << v1 << std::endl;

    Matrix<float> m1 = Matrix<float>(2, 2, new float[4]{1, 2, 3, 4});

    std::cout << m1 << std::endl;

    std::cout << m1.toVector() << std::endl;

    std::cout << v1.toMatrix(2, 2) << std::endl;
    return 0;
}