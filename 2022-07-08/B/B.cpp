#include <iostream>

int main() {
    unsigned n, m, a, b, i, x;

    while (std::cin >> n >> m) {
        a = n/m + 1;
        b = m - n%m;

        for (i = 0; i < m; i++) {
            x = a;

            if (b) {
                x--;
                b--;
            }

            if (i) {
                std::cout << ' ';
            }

            std::cout << x;
        }

        std::cout << std::endl;
    }

    return 0;
}
