#include <iostream>

int main() {
    unsigned t, n, k, i, j;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n >> k;

            if (k == 1) {
                std::cout << "YES" << std::endl;

                for (i = 1; i <= n; i++) {
                    std::cout << i << ' ' << std::endl;
                }
            } else if (n & 1) {
                std::cout << "NO" << std::endl;
            } else {
                std::cout << "YES" << std::endl;

                for (i = 1; i <= n; i ++) {
                    for (j = i; j <= n * k; j += n) {
                        std::cout << j << ' ';
                    }

                    std::cout << std::endl;
                }
            }
        }
    }

    return 0;
}
