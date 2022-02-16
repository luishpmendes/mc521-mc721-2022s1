#include <iostream>

int main() {
    int n, m, x, y;

    while (std::cin >> n >> m) {
        x = m / 2;
        y = m / 2 + 1;

        while (n--) {
            if (x <= m - y) {
                std::cout << y << std::endl;
                y++;
            } else { // x > m - y
                std::cout << x << std::endl;
                x--;
            }

            if (x == 0 && y == m + 1) {
                x = m / 2;
                y = m / 2 + 1;
            }
        }
    }

    return 0;
}
