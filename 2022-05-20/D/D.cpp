#include <iostream>

int main() {
    long long n, rhombus, i;
    
    while (std::cin >> n) {
        rhombus = 1;

        for (i = 1; i < n; i++) {
            rhombus += 4 * i;
        }

        std::cout << rhombus << std::endl;
    }

    return 0;
}
