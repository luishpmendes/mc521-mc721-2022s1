#include <iostream>

int main() {
    unsigned t, a, b;
    
    while (std::cin >> t) {
        while (t--) {
            std::cin >> a >> b;

            if (a == 0) {
                std::cout << 1 << std::endl;
            } else {
                std::cout << 2 * b + a + 1 << std::endl;
            }
        }
    }

    return 0;
}
