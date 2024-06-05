#include "Vector.hpp"
#include "Matrix.hpp"

void run_linear_combinaison() {

    Vector<float> e1 = Vector<float>(std::vector<float>{1, 0, 0});
    Vector<float> e2 = Vector<float>(std::vector<float>{0, 1, 0});
    Vector<float> e3 = Vector<float>(std::vector<float>{0, 0, 1});

    std::cout << "e1:" << std::endl << e1 << std::endl;
    std::cout << "e2:" << std::endl << e2 << std::endl;
    std::cout << "e3:" << std::endl << e3 << std::endl;

    Vector<float> e4 = linear_combination(std::array<Vector<float>, 3> {e1, e2, e3}, std::array<float, 3>{10, -2, 0.5});
    std::cout << "e4:" << std::endl << e4 << std::endl;
    
    Vector<float> v1 = Vector<float>(std::vector<float>{1, 2, 3});
    Vector<float> v2 = Vector<float>(std::vector<float>{0, 10, -100});

    std::cout << "v1:" << std::endl << v1 << std::endl;
    std::cout << "v2:" << std::endl << v2 << std::endl;

    Vector<float> v3 = linear_combination(std::array<Vector<float>, 2> {v1, v2}, std::array<float, 2>{10, -2});
    std::cout << "v3:" << std::endl << v3 << std::endl;

}


int main() {
    run_linear_combinaison();
    return 0;
}