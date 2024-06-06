#include "Vector.hpp"
#include "Matrix.hpp"

void run_cross_product() {

    std::cout << "Cross product of 2 3d vectors" << std::endl;

    Vector<float> v1 = Vector<float>({1, 0});
    Vector<float> v2 = Vector<float>({1, 0});
    std::cout << "v1: " << std::endl << v1;
    std::cout << "v2: " << std::endl << v2;
    std::cout << "cross_product: " << std::endl << cross_product(v1, v2) << std::endl << std::endl;

    Vector<float> v3 = Vector<float>({0, 0, 1});
    Vector<float> v4 = Vector<float>({1, 0, 0});
    std::cout << "v3: " << std::endl << v3;
    std::cout << "v4: " << std::endl << v4;
    std::cout << "cross_product: " << std::endl << cross_product(v3, v4) << std::endl << std::endl;

    Vector<float> v5 = Vector<float>({1, 2, 3});
    Vector<float> v6 = Vector<float>({4, 5, 6});
    std::cout << "v5: " << std::endl << v5;
    std::cout << "v6: " << std::endl << v6;
    std::cout << "cross_product: " << std::endl << cross_product(v5, v6) << std::endl << std::endl;

    Vector<float> v7 = Vector<float>({4, 2, -3});
    Vector<float> v8 = Vector<float>({-2, -5, 16});
    std::cout << "v7: " << std::endl << v7;
    std::cout << "v8: " << std::endl << v8;
    std::cout << "cross_product: " << std::endl << cross_product(v7, v8) << std::endl << std::endl;
}


int main() {
    run_cross_product();
    return 0;
}