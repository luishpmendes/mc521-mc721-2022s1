#include <iostream>
#include <string>
#include <vector>

int main() {
    unsigned t, n, i, j;
    std::vector<std::string> polygon;
    bool ans;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;

            polygon.resize(n);

            for (std::string & s : polygon) {
                std::cin >> s;
            }

            ans = true;

            for (i = n - 1; i > 0 && ans; i--) {
                for (j = n - 1; j > 0 && ans; j--) {
                    if (polygon[i - 1][j - 1] == '1' &&
                        polygon[i][j - 1] == '0' &&
                        polygon[i - 1][j] == '0')
                        ans = false;
                }
            }

            std::cout << (ans ? "YES" : "NO") << std::endl;
        }
    }

    return 0;
}
