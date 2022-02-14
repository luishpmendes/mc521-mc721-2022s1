#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    unsigned t, n, i;
    std::vector<unsigned> b;
    bool result;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;
            b.resize(n);

            for (i = 0; i < n; ++i) {
                std::cin >> b[i];
            }

            std::sort(b.begin(), b.end());

            result = false;

            for (i = 1; i < n; ++i) {
                if (b[i] == b[i - 1]) {
                    result = true;
                    break;
                }
            }

            std::cout << (result ? "YES" : "NO") << std::endl;
        }
    }

    return 0;
}
