#include <iostream>
#include <limits>
#include <vector>

int main() {
    unsigned n, i, j, k;
    std::vector<unsigned> v, sum;
    std::vector<std::vector<unsigned>> dp;

    while (std::cin >> n) {
        v.resize(n + 1);
        sum.resize(n + 1);
        sum[0] = 0;

        for (i = 1; i <= n; i++) {
            std::cin >> v[i];
            sum[i] = sum[i - 1] + v[i];
        }

        dp.clear();
        dp.resize(n + 2, std::vector<unsigned>(n + 2, 0));

        for (k = 1; k < n; k++) {
            for (i = 1; i + k <= n; i++) {
                dp[i][i + k] = std::numeric_limits<unsigned>::max() >> 2;

                for (j = i; j <= i + k; j++) {
                    if (dp[i][i + k] > dp[i][j - 1] + dp[j + 1][i + k] + sum[i + k] - sum[i - 1] - v[j]) {
                        dp[i][i + k] = dp[i][j - 1] + dp[j + 1][i + k] + sum[i + k] - sum[i - 1] - v[j];
                    }
                }
            }
        }

        std::cout << dp[1][n] << std::endl;
    }

    return 0;
}
