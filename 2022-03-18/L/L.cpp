#include <iostream>

int main() {
    unsigned long long t, x1, y1, x2, y2;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> x1 >> y1 >> x2 >> y2;
            std::cout << (x2 - x1) * (y2 - y1) + 1 << std::endl;
        }
    }

    return 0;
}
