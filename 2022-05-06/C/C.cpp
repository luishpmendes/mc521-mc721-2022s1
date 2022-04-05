#include <iostream>
#include <limits>
#include <vector>

int main() {
    unsigned n, a, b, c, i;
    std::vector<int> dp;

    while (std::cin >> n >> a >> b >> c) {
        dp.clear();
        dp.resize(n + 1, std::numeric_limits<int>::min());
        dp[0] = 0;

        for (i = a; i <= n; i++) {
            if (dp[i] < 1 + dp[i - a]) {
                dp[i] = 1 + dp[i - a];
            }
        }

        for (i = b; i <= n; i++) {
            if (dp[i] < 1 + dp[i - b]) {
                dp[i] = 1 + dp[i - b];
            }
        }

        for (i = c; i <= n; i++) {
            if (dp[i] < 1 + dp[i - c]) {
                dp[i] = 1 + dp[i - c];
            }
        }

        std::cout << dp[n] << std::endl;
    }

    return 0;
}
