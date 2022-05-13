#include <iostream>
#include <vector>

int main() {
    unsigned long n, k, m, i, j, l;
    std::vector<std::vector<unsigned long>> dp;
    
    while (std::cin >> n >> k >> m) {
        dp.clear();
        dp.resize(n + 1, std::vector<unsigned long>(k + 1, 0));

        for (i = 1; i <= n && i <= m; i++) {
            dp[i][1] = 1;
        }

        for (j = 2; j <= k; j++) {
            for (i = j; i <= n; i++) {
                for (l = 1; l <= m && i > l; l++) {
                    dp[i][j] += dp[i - l][j - 1];
                }
            }
        }

        std::cout << dp[n][k] << std::endl;
    }

    return 0;
}
