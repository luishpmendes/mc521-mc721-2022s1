#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    unsigned n, k;
    std::vector<unsigned> a;

    while (std::cin >> n >> k) {
        a.resize(n);

        for (unsigned & x : a) {
            std::cin >> x;
        }

        std::nth_element(a.begin(), a.begin() + n - k, a.end());

        std::cout << a[n - k] << std::endl;
    }

    return 0;
}
