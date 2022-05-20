#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    unsigned n, max_rep, cur_rep, i, j;
    std::vector<unsigned> v;

    while (std::cin >> n && n) {
        v.resize(n);

        for (unsigned & x : v) {
            std::cin >> x;
        }

        std::sort(v.begin(), v.end());

        max_rep = 0;
        cur_rep = 1;

        for (i = 1; i < n; i++) {
            if (v[i] == v[i - 1]) {
                cur_rep++;
            } else {
                cur_rep = 1;
            }

            max_rep = std::max(max_rep, cur_rep);
        }

        std::cout << max_rep << std::endl;

        for (i = 0; i < max_rep; i++) {
            std::cout << v[i];

            for (j = i + max_rep; j < n; j += max_rep) {
                std::cout << ' ' << v[j];
            }
            std::cout << std::endl;
        }

    }

    return 0;
}
