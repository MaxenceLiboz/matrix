#include "Vector.hpp"
#include "Matrix.hpp"

void run_raw_echelon_form() {

    std::cout << "Matrix row echelon form" << std::endl;

    Matrix<float> m1 = Matrix<float>({{0, 2, 3, 4}, {5, 6, 7, 8}});
    std::cout << "m1: " << std::endl << m1;
    std::cout << "RREF: " << std::endl << m1.row_echelon_form() << std::endl;

    Matrix<float> m2 = Matrix<float>({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
    std::cout << "m2: " << std::endl << m2;
    std::cout << "RREF: " << std::endl << m2.row_echelon_form() << std::endl;

    Matrix<float> m3 = Matrix<float>({{1, 2}, {3, 4}});
    std::cout << "m3: " << std::endl << m3;
    std::cout << "RREF: " << std::endl << m3.row_echelon_form() << std::endl;

    Matrix<float> m4 = Matrix<float>({{1, 2}, {2, 4}});
    std::cout << "m4: " << std::endl << m4;
    std::cout << "RREF: " << std::endl << m4.row_echelon_form() << std::endl;

    Matrix<float> m5 = Matrix<float>({{8, 5, -2, 4, 28}, {4, 2.5, 20, 4, -4}, {8, 5, 1, 4, 17}});
    std::cout << "m5: " << std::endl << m5;
    std::cout << "RREF: " << std::endl<<  m5.row_echelon_form(true) << std::endl;

}


int main() {
    run_raw_echelon_form();
    return 0;
}