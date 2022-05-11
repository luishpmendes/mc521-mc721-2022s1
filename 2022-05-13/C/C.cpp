#include <iostream>
#include <limits>
#include <vector>

int main() {
    unsigned n, l, k, ans, i, j, pos;
    std::vector<unsigned> d, a;
    std::vector<std::vector<unsigned>> dp;

    while (std::cin >> n >> l >> k) {
        d.resize(n + 1);
        a.resize(n + 1);
        dp.clear();
        dp.resize(n + 1, std::vector<unsigned>(k + 1, std::numeric_limits<unsigned>::max() >> 2));

        for (i = 0; i < n; i++) {
            std::cin >> d[i];
        }

        d[n] = l;

        for (i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        a[n] = 0;
        dp[0][0] = 0;
        ans = std::numeric_limits<unsigned>::max() >> 2;

        for (i = 1; i <= n; i++) {
            for (j = 0; j <= k; j++) {
                for (pos = 0; pos < i; pos++) {
                    if(i <= j + pos + 1 && dp[i][j] > dp[pos][j - i + pos + 1] + a[pos] * (d[i] - d[pos])) {
                        dp[i][j] = dp[pos][j - i + pos + 1] + a[pos] * (d[i] - d[pos]);
                    }
                }

                if (i == n && ans > dp[i][j]) {
                    ans = dp[i][j];
                }
            }
        }

        std::cout << ans << std::endl;
    }
    
    return 0;
}
