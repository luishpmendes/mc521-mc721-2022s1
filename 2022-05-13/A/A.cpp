#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    unsigned n, q, l, r, i;
    std::string s;
    std::vector<unsigned> dp;

    while (std::cin >> n >> q) {
        dp.resize(n + 1);

        std::cin >> s;

        dp[0] = 0;
        for (i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + s[i - 1] - 'a' + 1;
            
        }

        while (q--) {
            std::cin >> l >> r;
            std::cout << dp[r] - dp[l - 1] << std::endl;
        }
    }
    
    return 0;
}
