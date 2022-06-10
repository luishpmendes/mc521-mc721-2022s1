#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    unsigned t, n, i, j;
    std::vector<unsigned> a, dp;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;
            
            a.resize(n);
            dp.resize(n);

            for (i = 0; i < n; i++) {
                std::cin >> a[i];
            }

            for (i = n; i > 0; i--) {
                dp[i - 1] = a[i - 1];
                j = i - 1 + a[i - 1];

                if (j < n) {
                    dp[i - 1] += dp[j];
                }
            }

            std::cout << *std::max_element(dp.begin(), dp.end()) << std::endl;
        }
    }

    return 0;
}
