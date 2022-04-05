#include <iostream>
#include <vector>

int main() {
    unsigned n, k, i, min_sum_heights, result;
    std::vector<unsigned> h, dp;

    while (std::cin >> n >> k) {
        h.resize(n);
        dp.resize(n + 1);
        dp[0] = 0;
        min_sum_heights = result = 0;

        for (i = 0; i < n; i++) {
            std::cin >> h[i];
            min_sum_heights += h[i];
        }

        for (i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + h[i - 1];
        }

        for (i = 0; i <= n - k; i++) {
            if (min_sum_heights > dp[i + k] - dp[i]) {
                min_sum_heights = dp[i + k] - dp[i];
                result = i;
            }
        }

        std::cout << result + 1 << std::endl;
    }

    return 0;
}
