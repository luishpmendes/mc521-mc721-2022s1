#include <iostream>
#include <vector>

int main() {
    unsigned n, m, result, i, j;
    std::vector<std::vector<unsigned>> theather, left, right, up, down;

    while (std::cin >> n >> m) {
        theather.clear();
        left.clear();
        right.clear();
        up.clear();
        down.clear();
        theather.resize(n, std::vector<unsigned>(m, 0));
        left.resize(n, std::vector<unsigned>(m, 0));
        right.resize(n, std::vector<unsigned>(m, 0));
        up.resize(n, std::vector<unsigned>(m, 0));
        down.resize(n, std::vector<unsigned>(m, 0));
        result = 0;

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                std::cin >> theather[i][j];
            }
        }

        for (i = 0; i < n; i++) {
            left[i][0] = theather[i][0];
            right[i][m - 1] = theather[i][m - 1];

            for (j = 1; j < m; j++) {
                if (left[i][j - 1] || theather[i][j]) {
                    left[i][j] = 1;
                }

                if (right[i][m - j] || theather[i][m - 1 - j]) {
                    right[i][m - 1 - j] = 1;
                }
            }
        }

        for (j = 0; j < m; j++) {
            up[0][j] = theather[0][j];
            down[n - 1][j] = theather[n - 1][j];

            for (i = 1; i < n; i++) {
                if (up[i - 1][j] || theather[i][j]) {
                    up[i][j] = 1;
                }

                if (down[n - i][j] || theather[n - 1 - i][j]) {
                    down[n - 1 - i][j] = 1;
                }
            }
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (!theather[i][j] && left[i][j]) {
                    result++;
                }

                if (!theather[i][j] && right[i][j]) {
                    result++;
                }

                if (!theather[i][j] && up[i][j]) {
                    result++;
                }

                if (!theather[i][j] && down[i][j]) {
                    result++;
                }
            }
        }

        std::cout << result << std::endl;
    }

    return 0;
}
