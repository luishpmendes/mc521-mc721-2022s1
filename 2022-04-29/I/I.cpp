#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    unsigned n, m, i, result_i, result_j;
    std::vector<unsigned> p;
    std::vector<unsigned>::iterator it_j;

    while (std::cin >> n) {
        p.clear();
        p.resize(n);

        for (i = 0; i < n; i++) {
            std::cin >> p[i];
        }

        std::cin >> m;

        std::sort(p.begin(), p.end());

        for (i = 0; i < n && p[i] <= m - p[i]; i++) {
            if (std::binary_search(p.begin() + i + 1, p.end(), m - p[i])) {
                result_i = p[i];
                result_j = m - p[i];
            }
        }

        std::cout << "Peter should buy books whose prices are " << result_i << " and " << result_j << "." << std::endl << std::endl;
    }

    return 0;
}
