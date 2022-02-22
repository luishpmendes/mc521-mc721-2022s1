#include <iostream>

int main() {
    unsigned k, n, w, total;

    while (std::cin >> k >> n >> w) {
        total = (k * w * (w + 1)) / 2;

        if (total <= n) {
            std::cout << 0 << std::endl;
        } else {
            std::cout << total - n << std::endl;
        }
    }

    return 0;
}
