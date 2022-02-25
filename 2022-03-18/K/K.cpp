#include <iostream>

int main() {
    unsigned n, m, i, j;

    while (std::cin >> n >> m) {
        for (i = j = 0; i < n && j < m; i++) {
            if (2 * (n + i) + 1 <= m) {
                j++;

                std::cout << 2 * (n + i) + 1;

                if (j < m) {
                    std::cout << " ";
                } else {
                    std::cout << std::endl;
                }
            }

            if (2 * i + 1 <= m) {
                j++;

                std::cout << 2 * i + 1;

                if (j < m) {
                    std::cout << " ";
                } else {
                    std::cout << std::endl;
                }
            }

            if (2 * (n + i + 1) <= m) {
                j++;

                std::cout << 2 * (n + i + 1);

                if (j < m) {
                    std::cout << " ";
                } else {
                    std::cout << std::endl;
                }
            }

            if (2 * (i + 1) <= m) {
                j++;
                
                std::cout << 2 * (i + 1);

                if (j < m) {
                    std::cout << " ";
                } else {
                    std::cout << std::endl;
                }
            }
        }
    }

    return 0;
}
