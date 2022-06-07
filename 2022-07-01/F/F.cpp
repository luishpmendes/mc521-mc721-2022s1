#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    unsigned n, i;
    std::vector<std::pair<unsigned, unsigned>> p;

    while (std::cin >> n) {
        p.resize(n);

        for (i = 0; i < n; i++) {
            std::cin >> p[i].first;
            p[i].second = i;
        }

        std::nth_element(p.begin(), p.begin() + n - 1, p.end());
        std::nth_element(p.begin(), p.begin() + n - 2, p.end());

        std::cout << p[n - 1].second + 1 << ' ' << p[n - 2].first << std::endl;
    }

    return 0;
}
