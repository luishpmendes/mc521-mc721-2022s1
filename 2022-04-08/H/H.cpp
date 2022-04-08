#include <iostream>
#include <vector>

int main() {
    unsigned long long C, d, k, degree, i, j, x, y;
    std::vector<unsigned long long> c, a, b;

    while (std::cin >> C) {
        while (C--) {
            std::cin >> degree;

            c.resize(degree + 1);

            for (unsigned long long & coef : c) {
                std::cin >> coef;
            }

            std::cin >> d >> k;

            a.clear();

            for (i = 1; i <= k; i++) {
                x = c[0];
                y = i;

                for (j = 1; j < c.size(); j++) {
                    x += c[j] * y;
                    y *= i;
                }

                a.push_back(x);
            }

            b.clear();

            for (i = 0; i < a.size() && b.size() < k; i++) {
                for (j = 0; j < (i + 1)*d && b.size() < k; j++) {
                    b.push_back(a[i]);
                }
            }

            std::cout << b.back() << std::endl;
        }
    }

    return 0;
}
