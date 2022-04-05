#include <iostream>
#include <string>
#include <vector>

int main() {
    int t, n, x, y;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;
            y = n % 2020;
            x = (n - y) / 2020 - y;

            if (x >= 0 && 2020 * x + 2021 * y == n) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }

    return 0;
}
