#include <iostream>
#include <limits>
#include <vector>

int main() {
    unsigned t, m, s1, s2, ans, j;
    std::vector<std::vector<unsigned>> a (2);

    while (std::cin >> t) {
        while (t--) {
            std::cin >> m;

            a[0].resize(m);
            a[1].resize(m);
            s1 = s2 = 0;
            ans = std::numeric_limits<unsigned>::max();

            for (j = 0; j < m; j++) {
                std::cin >> a[0][j];
                s1 += a[0][j];
            }

            for (j = 0; j < m; j++) {
                std::cin >> a[1][j];
                s1 -= a[0][j];

                if (s1 >= s2) {
                    if (ans > s1) {
                        ans = s1;
                    }
                } else {
                    if (ans > s2) {
                        ans = s2;
                    }
                }

                s2 += a[1][j];
            }

            std::cout << ans << std::endl;
        }
    }

    return 0;
}
