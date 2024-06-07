#include "Vector.hpp"
#include "Matrix.hpp"

void run_inverse() {
    std::cout << "Matrix inverse" << std::endl;

    Matrix<float> m1 = Matrix<float>({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
    std::cout << "m1: " << std::endl << m1;
    std::cout << "inverse: " << std::endl << m1.inverse() << std::endl;

    Matrix<float> m2 = Matrix<float>({{2, 0, 0}, {0, 2, 0}, {0, 0, 2}});
    std::cout << "m2: " << std::endl << m2;
    std::cout << "inverse: " << std::endl << m2.inverse() << std::endl;

    Matrix<float> m3 = Matrix<float>({{8, 5, -2}, {4, 7, 20}, {7, 6, 1}});
    std::cout << "m3: " << std::endl << m3;
    std::cout << "inverse: " << std::endl << m3.inverse() << std::endl;

    try
    {
        Matrix<float> m4 = Matrix<float>({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
        std::cout << "m4: " << std::endl << m4;
        std::cout << "inverse: " << std::endl << m4.inverse() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Matrix<float> m5 = Matrix<float>({{1, 2, 3}, {4, 5, 6}});
    std::cout << "m5: " << std::endl << m5;
    std::cout << "inverse: " << std::endl << m5.inverse() << std::endl;
}


int main() {
    run_inverse();
    return 0;
}