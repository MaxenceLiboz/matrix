#include "Vector.hpp"
#include "Matrix.hpp"

void run_dot_vector() {
    std::cout << "Dot product of a vector" << std::endl;

    Vector<float> v1 = Vector<float>({0, 0});
    Vector<float> v2 = Vector<float>({1, 1});
    std::cout << "v1: " << std::endl << v1;
    std::cout << "v2: " << std::endl << v2;
    std::cout << "v1 . v2: " << v1.dot(v2) << std::endl << std::endl;

    Vector<float> v3 = Vector<float>({1, 1});
    Vector<float> v4 = Vector<float>({1, 1});
    std::cout << "v3: " << std::endl << v3;
    std::cout << "v4: " << std::endl << v4;
    std::cout << "v3 . v4: " << v3.dot(v4) << std::endl << std::endl;

    Vector<float> v5 = Vector<float>({-1, 6});
    Vector<float> v6 = Vector<float>({3, 2});
    std::cout << "v5: " << std::endl << v5;
    std::cout << "v6: " << std::endl << v6;
    std::cout << "v5 . v6: " << v5.dot(v6) << std::endl << std::endl;

    Vector<float> v7 = Vector<float>({1, 2, 3, 4});
    Vector<float> v8 = Vector<float>({4, 3, 2, 4});
    std::cout << "v7: " << std::endl << v7;
    std::cout << "v8: " << std::endl << v8;
    std::cout << "v7 . v8: " << v7.dot(v8) << std::endl << std::endl;

    Vector<float> v9 = Vector<float>({1, 2, 3, 4});
    Vector<float> v10 = Vector<float>({4, 3});
    std::cout << "v9: " << std::endl << v9;
    std::cout << "v10: " << std::endl << v10;
    std::cout << "v9 . v10: " << v9.dot(v10) << std::endl << std::endl;
}


int main() {
    run_dot_vector();
    return 0;
}