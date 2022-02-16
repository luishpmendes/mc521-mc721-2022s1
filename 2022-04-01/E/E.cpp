#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    unsigned long long n, b, d, y, k, i, count;
    std::vector<std::pair<unsigned long long, bool>> v;

    while (std::cin >> n) {
        v.resize(2 * n);

        for (i = 0; i < n; i++) {
            std::cin >> b >> d;
            v[i] = std::make_pair(b, true);
            v[i + n] = std::make_pair(d, false);
        }

        std::sort(v.begin(), v.end());

        k = count = 0;

        for (i = 0; i < 2 * n; i++) {
            if (v[i].second) {
                count++;
            } else {
                count--;
            }

            if (k < count) {
                k = count;
                y = v[i].first;
            }
        }

        std::cout << y << ' ' << k << std::endl;
    }
    
    return 0;
}
