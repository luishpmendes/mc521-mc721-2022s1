#include <algorithm>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

int main() {
    unsigned n, m, S, i, j, k, result;
    std::vector<std::pair<unsigned, unsigned>> v;
    std::vector<std::vector<unsigned>> dp;

    while (std::cin >> n) {
        while (n--) {
            std::cin >> m >> S;
            v.resize(m);

            for (std::pair<unsigned, unsigned> & x : v) {
                std::cin >> x.first >> x.second;
            }

            dp.clear();
            dp.resize(S + 1, std::vector<unsigned>(S + 1, std::numeric_limits<unsigned>::max() << 2));
            dp[0][0] = 0;

            for (i = 0; i < m; i++) {
                for (j = v[i].first; j <= S; j++) {
                    for (k = v[i].second; k <= S; k++) {
                        if (dp[j][k] > dp[j - v[i].first][k - v[i].second] + 1) {
                            dp[j][k] = dp[j - v[i].first][k - v[i].second] + 1;
                        }
                    }
                }
            }

            result = std::numeric_limits<unsigned>::max() << 2;

            for (i = 0; i <= S; i++) {
                for (j = 0; j <= S; j++) {
                    if (i * i + j * j == S * S && result > dp[i][j]) {
                        result = dp[i][j];
                    }
                }
            }

            if (result == std::numeric_limits<unsigned>::max() << 2) {
                std::cout << "not possible" << std::endl;
            } else {
                std::cout << result << std::endl;
            }
        }
    }
    
    return 0;
}
