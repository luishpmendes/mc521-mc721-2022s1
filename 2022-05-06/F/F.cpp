#include <iostream>
#include <vector>

int main() {
    unsigned n, i, result;
    std::vector<unsigned> a, dp;

    while (std::cin >> n) {
        a.resize(n);
        dp.resize(n);

        for (i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        result = 1;
        dp[0] = 1;

        for (i = 1; i < n; i++) {
            if (a[i] >= a[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = 1;
            }

            if (result < dp[i]) {
                result = dp[i];
            }
        }

        std::cout << result << std::endl;
    }

    return 0;
}
