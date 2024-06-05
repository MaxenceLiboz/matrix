#include "Vector.hpp"
#include "Matrix.hpp"

void run_dot_vector() {

    std::cout << "Manhattan, euclidean and supremum norm" << std::endl;

    Vector<float> v1 = Vector<float>({0, 0, 0});
    std::cout << "v1: " << std::endl << v1;
    std::cout << v1.norm_1() << ", " << v1.norm() << ", " << v1.norm_inf() << std::endl << std::endl;


    Vector<float> v3 = Vector<float>({1, 2, 3});
    std::cout << "v3: " << std::endl << v3;
    std::cout << v3.norm_1() << ", " << v3.norm() << ", " << v3.norm_inf() << std::endl << std::endl;

    Vector<float> v5 = Vector<float>({-1, -2});
    std::cout << "v5: " << std::endl << v5;
    std::cout << v5.norm_1() << ", " << v5.norm() << ", " << v5.norm_inf() << std::endl << std::endl;
}


int main() {
    run_dot_vector();
    return 0;
}