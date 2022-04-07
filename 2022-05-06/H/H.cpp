#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    unsigned long long t, n, m, q, max_area, min_cost, cost, test_case, i, j, k, l;
    std::vector<std::vector<unsigned long long>> p, dp;

    while (std::cin >> t) {
        for (test_case = 1; test_case <= t; test_case++) {
            std::cin >> n >> m >> q;

            p.clear();
            p.resize(n, std::vector<unsigned long long>(m));

            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    std::cin >> p[i][j];

                    if (i > 0) {
                        p[i][j] += p[i - 1][j];
                    }
                    if (j > 0) {
                        p[i][j] += p[i][j - 1];
                    }
                    if (i > 0 && j > 0) {
                        p[i][j] -= p[i - 1][j - 1];
                    }
                }
            }

            max_area = 0;

            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    for (k = i; k < n; k++) {
                        for (l = j; l < m; l++) {
                            cost = p[k][l];

                            if (i > 0) {
                                cost -= p[i - 1][l];
                            }
                            if (j > 0) {
                                cost -= p[k][j - 1];
                            }
                            if (i > 0 && j > 0) {
                                cost += p[i - 1][j - 1];
                            }

                            if (cost <= q) {
                                if (max_area < (k - i + 1) * (l - j + 1)) {
                                    max_area = (k - i + 1) * (l - j + 1);
                                    min_cost = cost;
                                }
                                if (max_area == (k - i + 1) * (l - j + 1) && min_cost > cost) {
                                    min_cost = cost;
                                }
                            }
                        }
                    }
                }
            }

            std::cout << "Case #" << test_case << ": " << max_area << " " << min_cost << std::endl;
        }
    }

    return 0;
}
