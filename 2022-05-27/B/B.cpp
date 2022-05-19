#include <iostream>
#include <limits>
#include <vector>

long calc(const std::vector<long> & v, const long & n, const long & d) {
    long mx = 0,
         mn = std::numeric_limits<long>::max(),
         i;
    
    for (i = 1; i < n; i++) {
        mx = std::max(mx, v[i] - v[i - 1] - 1);
        mn = std::min(mn, v[i] - v[i - 1] - 1);
    }

    return std::min(mn, std::max(d - v.back() - 1, (mx - 1) / 2));
}

int main() {
    long t, n, d, mn, pos, i, ans;
    std::vector<long> a, b;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n >> d;
            a.resize(n + 1);
            b.clear();
            a[0] = 0;
            mn = d;
            pos = 0;

            for (i = 1; i <= n; i++) {
                std::cin >> a[i];

                if (mn > a[i] - a[i - 1] - 1) {
                    mn = a[i] - a[i - 1] - 1;
                    pos = i;
                }
            }

            for (i = 0; i <= n; i++) {
                if (i != pos) {
                    b.push_back(a[i]);
                }
            }

            ans = calc(b, n, d);

            if (pos > 1) {
                b[pos - 1] = a[pos];
            }

            ans = std::max(ans, calc(b, n, d));

            std::cout << ans << std::endl;
        }
    }

    return 0;
}
