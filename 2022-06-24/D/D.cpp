#include <iostream>
#include <string>
#include <vector>

int main() {
    unsigned t, n, m, i, j;
    std::vector<std::vector<unsigned>> table;
    std::string s;
    bool ans;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n >> m;

            table.resize(n, std::vector<unsigned>(m, 0));
            table.assign(n, std::vector<unsigned>(m, 0));
            ans = true;

            for (i = 0; i < n; i++) {
                std::cin >> s;

                for (j = 0; j < m; j++) {
                    table[i][j] = s[j] - '0';
                }
            }

            for (i = 0; i < n - 1 && ans; i++) {
                for (j = 0; j < m - 1 && ans; j++) {
                    if (table[i][j] + table[i][j + 1] + table[i + 1][j] + table[i + 1][j + 1] == 3) {
                        ans = false;
                    }
                }
            }

            if (ans) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }

    return 0;
}
