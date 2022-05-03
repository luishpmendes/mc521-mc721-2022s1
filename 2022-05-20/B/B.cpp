#include <iostream>
#include <utility>
#include <vector>

int main() {
    long long n, i;
    std::vector<long long> a;
    std::vector<std::pair<long long, long long>> dp;

    while (std::cin >> n) {
        a.resize(n);
        dp.resize(n);

        for (i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        if (a[0] >= 1) {
            dp[0].first =  a[0] - 1;
        } else {
            dp[0].first = -a[0] + 1;
        }

        if (a[0] >= -1) {
            dp[0].second =  a[0] + 1;
        } else {
            dp[0].second = -a[0] - 1;
        }

        for (i = 1; i < n; i++) {
            if (a[i] >= 1) {
                dp[i].first = dp[i - 1].first + a[i] - 1;
                
                if (dp[i].first > dp[i - 1].second + a[i] + 1) {
                    dp[i].first = dp[i - 1].second + a[i] + 1;
                }

                dp[i].second = dp[i - 1].second + a[i] - 1;

                if (dp[i].second > dp[i - 1].first + a[i] + 1) {
                    dp[i].second = dp[i - 1].first + a[i] + 1;
                }
            } else if (a[i] == 0) {
                dp[i].first = dp[i - 1].first + 1;

                if (dp[i].first > dp[i - 1].second + 1) {
                    dp[i].first = dp[i - 1].second + 1;
                }

                dp[i].second = dp[i - 1].second + 1;

                if (dp[i].second > dp[i - 1].first + 1) {
                    dp[i].second = dp[i - 1].first + 1;
                }
            } else { // a[i] <= -1
                dp[i].first = dp[i - 1].first - a[i] + 1;

                if (dp[i].first > dp[i - 1].second - a[i] - 1) {
                    dp[i].first = dp[i - 1].second - a[i] - 1;
                }

                dp[i].second = dp[i - 1].second - a[i] + 1;

                if (dp[i].second > dp[i - 1].first - a[i] - 1) {
                    dp[i].second = dp[i - 1].first - a[i] - 1;
                }
            }
        }

        std::cout << dp[n - 1].first << std::endl;
    }
    
    return 0;
}
