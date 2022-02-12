#include <algorithm>
#include <iostream>
#include <set>

int main() {
    unsigned n, m, cd;
    std::set<unsigned> jack, jill, both;

    while (std::cin >> n >> m && n && m) {
        jack.clear();
        jill.clear();
        both.clear();

        for (unsigned i = 0; i < n; i++) {
            std::cin >> cd;
            jack.insert(cd);
        }

        for (unsigned i = 0; i < m; i++) {
            std::cin >> cd;
            jill.insert(cd);
        }

        std::set_intersection(jack.begin(), jack.end(), jill.begin(), jill.end(),
                              std::inserter(both, both.begin()));
        
        std::cout << both.size() << std::endl;
    }

    return 0;
}
