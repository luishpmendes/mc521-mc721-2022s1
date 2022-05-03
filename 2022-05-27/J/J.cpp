#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    unsigned t, n;
    std::vector<unsigned> a;
    
    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;
            a.resize(n);

            for (auto& x : a) {
                std::cin >> x;
            }

            std::sort(a.rbegin(), a.rend());

            std::cout << a[0] + a[1] << std::endl;
        }
    }

    return 0;
}
