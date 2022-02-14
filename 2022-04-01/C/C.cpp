#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    unsigned t, n, i, j;
    std::vector<unsigned> a, b;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;
            a.resize(n);
            b.resize(n);

            for (i = 0; i < n; i++) {
                std::cin >> a[i];
            }

            std::sort(a.begin(), a.end());

            j = 0;
            for (i = 0; i < n; i++) {
                if (i == 0 || a[i] != a[i - 1]) {
                    b[j++] = a[i];
                }
            }

            for (i = 0; i < n; i++) {
                if (i > 0 && a[i] == a[i - 1]) {
                    b[j++] = a[i];
                }
            }

            for (j = 0; j < n - 1; j++) {
                std::cout << b[j] << ' ';
            }

            std::cout << b[j] << std::endl;
        }
    }

    return 0;
}
