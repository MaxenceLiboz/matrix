#include "Vector.hpp"
#include "Matrix.hpp"

void run_linear_interpolation() {

    Vector<float> e1 = Vector<float>({1, 0, 0});
    Vector<float> e2 = Vector<float>({0, 1, 0});
    Vector<float> e3 = Vector<float>({0, 0, 1});

    std::cout << "e1:" << std::endl << e1 << std::endl;
    std::cout << "e2:" << std::endl << e2 << std::endl;
    std::cout << "e3:" << std::endl << e3 << std::endl;

    Vector<float> v1 = Vector<float>({1, 2, 3});
    Vector<float> v2 = Vector<float>({0, 10, -100});

    std::cout << "v1:" << std::endl << v1 << std::endl;
    std::cout << "v2:" << std::endl << v2 << std::endl;;

}


int main() {
    run_linear_interpolation();
    return 0;
}