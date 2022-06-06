#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    long long t, n, i, ans, sum;
    std::vector<long long> d;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;
            
            d.resize(n);

            for (i = 0; i < n; i++) {
                std::cin >> d[i];
            }

            std::sort(d.begin(), d.end());

            ans = 0;
            sum = d.front();

            for (i = 1; i < n; i++) {
                ans -= i * d[i] - sum;
                sum += d[i];
            }

            ans += d.back();

            std::cout << ans << std::endl;
        }
    }

    return 0;
}
