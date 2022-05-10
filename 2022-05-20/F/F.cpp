#include <iostream>
#include <string>
#include <vector>
#include <utility>

int main() {
    std::string s;
    std::vector<std::pair<unsigned, unsigned>> dp;
    unsigned i;

    while (std::cin >> s) {
        dp.resize(s.size() + 1);
        dp[0] = {0, 0};

        for (i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                dp[i + 1].first = dp[i].first + 1;

                if (dp[i].first < dp[i].second) {
                    dp[i + 1].second = dp[i].first;
                } else { // dp[i].first >= dp[i].second
                    dp[i + 1].second = dp[i].second;
                }
            } else { // s[i] >= 'A' && s[i] <= 'Z'
                dp[i + 1].first = dp[i].first;

                if (dp[i].first < dp[i].second) {
                    dp[i + 1].second = dp[i].first + 1;
                } else { // dp[i].first >= dp[i].second
                    dp[i + 1].second = dp[i].second + 1;
                }
            }
        }

        if (dp.back().first < dp.back().second) {
            std::cout << dp.back().first << std::endl;
        } else { // dp.back().first >= dp.back().second
            std::cout << dp.back().second << std::endl;
        }
    }

    return 0;
}
