#include <iostream>
#include <vector>

int main() {
    unsigned t, n, i;
    std::vector<unsigned long> dp;

    dp.resize(2000200);

    dp[0] = dp[1] = 0;
    dp[2] = 4;

    for (i = 3; i < dp.size(); i++) {
        dp[i] = dp[i - 1] + 2 * dp[i - 2];

        if (i % 3 == 2) {
            dp[i] += 4;
        }

        dp[i] %= 1000000007;
    }

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;
            std::cout << dp[n - 1] << std::endl;
        }
    }

    return 0;
}
