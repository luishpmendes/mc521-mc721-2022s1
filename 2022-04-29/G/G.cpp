#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    unsigned n, i;
    std::vector<unsigned> t;
    std::vector<unsigned>::iterator it;
    bool result;

    while (std::cin >> n) {
        t.resize(n);

        for (i = 0; i < n; i++) {
            std::cin >> t[i];
        }

        std::sort(t.begin(), t.end());
        it = std::unique(t.begin(), t.end());
        t.resize(std::distance(t.begin(), it));

        result = false;

        if (t.size() >= 3) {
            for (i = 0; i < t.size() - 2; i++) {
                if (t[i + 2] <= t[i] + 2) {
                    result = true;
                    break;
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
