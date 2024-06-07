#include "Vector.hpp"
#include "Matrix.hpp"

void run_rank() {
    std::cout << "Matrix rank" << std::endl;

    Matrix<float> m1 = Matrix<float>({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
    std::cout << "m1: " << std::endl << m1;
    std::cout << "rank: " << m1.rank() << std::endl;

    Matrix<float> m2 = Matrix<float>({{1, 2, 0, 0}, {2, 4, 0, 0}, {-1, 2, 1, 1}});
    std::cout << "m2: " << std::endl << m2;
    std::cout << "rank: " << m2.rank() << std::endl;

    Matrix<float> m3 = Matrix<float>({{8, 5, -2}, {4, 7, 20}, {7, 6, 1}, {21, 18, 7}});
    std::cout << "m3: " << std::endl << m3;
    std::cout << "rank: " << m3.rank() << std::endl;

    Matrix<float> m4 = Matrix<float>({{1, 2, 3}, {2, 4, 6}, {4, 8, 12}});
    std::cout << "m4: " << std::endl << m4;
    std::cout << "rank: " << m4.rank() << std::endl;
}


int main() {
    run_rank();
    return 0;
}