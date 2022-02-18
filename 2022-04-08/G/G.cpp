#include <iostream>
#include <vector>

int main() {
    unsigned n, i, j;
    std::vector<int> x, d;
    bool result;

    while (std::cin >> n) {
        x.resize(n);
        d.resize(n);

        for (i = 0; i < n; i++) {
            std::cin >> x[i] >> d[i];
        }

        result = false;

        for (i = 0; i < n && !result; i++) {
            for (j = i + 1; j < n && !result; j++) {
                if (x[i] + d[i] == x[j] && x[j] + d[j] == x[i]) {
                    result = true;
                }
            }
        }

        if (result) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
