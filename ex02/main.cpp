#include "Vector.hpp"
#include "Matrix.hpp"

void run_lerp() {

    std::cout << "Linear Interpolation" << std::endl;
    std::cout << lerp(Vector<float>({0, 0}), Vector<float>({1, 1}), 0.0f) << std::endl;
    std::cout << lerp(Vector<float>({0, 0}), Vector<float>({1, 1}), 0.5f) << std::endl;
    std::cout << lerp(Vector<float>({0, 0}), Vector<float>({1, 1}), 1.0f) << std::endl;
    std::cout << lerp(Vector<float>({2, 1}), Vector<float>({4, 2}), 0.3f) << std::endl;

    std::cout << lerp(Matrix<float>({{0, 0}, {0, 0}}), Matrix<float>({{1, 1}, {1, 1}}), 0.0f) << std::endl;
    std::cout << lerp(Matrix<float>({{0, 0}, {0, 0}}), Matrix<float>({{1, 1}, {1, 1}}), 0.5f) << std::endl;
    std::cout << lerp(Matrix<float>({{0, 0}, {0, 0}}), Matrix<float>({{1, 1}, {1, 1}}), 1.0f) << std::endl;
    std::cout << lerp(Matrix<float>({{2, 1}, {3, 4}}), Matrix<float>({{20, 10}, {30, 40}}), 0.5f) << std::endl;
}


int main() {
    run_lerp();
    return 0;
}