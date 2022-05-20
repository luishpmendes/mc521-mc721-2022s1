#include <iostream>
#include <vector>

int main() {
    unsigned n, t, i;
    std::vector<unsigned> a;
    std::vector<bool> c;

    while (std::cin >> n >> t) {
        a.resize(n - 1);
        c.resize(n);

        for (i = 0; i < n - 1; i++) {
            std::cin >> a[i];
            c[i] = false;
        }

        c[i] = false;

        i = 0;

        while (i < n - 1) {
            c[i] = true;
            i += a[i];
        }

        c[i] = true;

        if (c[t - 1]) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
