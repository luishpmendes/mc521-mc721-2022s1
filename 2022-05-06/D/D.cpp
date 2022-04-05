#include <iostream>
#include <vector>

int main() {
    unsigned n, q, m, i, max_x;
    std::vector<unsigned> x, c;

    while (std::cin >> n) {
        x.resize(n);
        max_x = 0;

        for (i = 0; i < n; i++) {
            std::cin >> x[i];

            if (max_x < x[i]) {
                max_x = x[i];
            }
        }

        std::cin >> q;

        c.clear();
        c.resize(max_x + 1, 0);

        for (i = 0; i < n; i++) {
            c[x[i]]++;
        }

        for (i = 1; i <= max_x; i++) {
            c[i] += c[i - 1];
        }

        while (q--) {
            std::cin >> m;

            if (m > max_x) {
                std::cout << c.back() << std::endl;
            } else {
                std::cout << c[m] << std::endl;
            }
        }

    }

    return 0;
}
