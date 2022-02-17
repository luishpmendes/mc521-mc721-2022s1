#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

int main() {
    unsigned t, n, i, l, r, id;
    std::vector<unsigned> a;
    auto cmp = [](const std::pair<unsigned, unsigned> & a,
                  const std::pair<unsigned, unsigned> & b) {
        if (a.second + b.first == a.first + b.second) {
            return a.first < b.first;
        }

        return a.second + b.first > a.first + b.second;
    };
    std::set<std::pair<unsigned, unsigned>, decltype(cmp)> segs(cmp);
    std::set<std::pair<unsigned, unsigned>, decltype(cmp)>::iterator it;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;

            a.clear();
            a.resize(n, 0);
            segs.clear();
            segs.insert(std::make_pair(0, n - 1));

            for (i = 1; i <= n; i++) {
                it = segs.begin();
                l = it->first;
                r = it->second;
                id = floor((l + r) / 2);
                segs.erase(it);
                a[id] = i;

                if (id > l) {
                    segs.insert(std::make_pair(l, id - 1));
                }

                if (id < r) {
                    segs.insert(std::make_pair(id + 1, r));
                }
            }

            for (i = 0; i < n - 1; i++) {
                std::cout << a[i] << ' ';
            }

            std::cout << a.back() << std::endl;
        }
    }

    return 0;
}
