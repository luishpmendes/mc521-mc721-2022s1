#include <iostream>
#include <vector>

bool can(const unsigned & n, const unsigned & m, const std::vector<unsigned> & c, const unsigned & capacity) {
    unsigned i, k, sum;

    for (i = 0, k = 1, sum = 0; i < n; i++) {
        sum += c[i];

        if (sum > capacity) {
            sum = c[i];
            k++;
        }
    }

    return k <= m;
}

int main() {
    unsigned n, m, lo, hi, mid, ans;
    std::vector<unsigned> c;

    while (std::cin >> n >> m) {
        lo = hi = 0;
        c.resize(n);

        for (unsigned i = 0; i < n; i++) {
            std::cin >> c[i];

            if (lo < c[i]) {
                lo = c[i];
            }

            hi += c[i];
        }

        while (hi >= lo) {
            mid = (lo + hi) / 2;

            if (can(n, m, c, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        std::cout << ans << std::endl;
    }

    return 0;
}
