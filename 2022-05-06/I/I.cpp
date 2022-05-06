#include <iostream>
#include <limits>
#include <vector>

int main() {
    long t, a, b, c, i, j, k, i1, j1, k1;
    long sum, max_sum;
    std::vector<std::vector<std::vector<long>>> m;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> a >> b >> c;
            m.clear();
            m.resize(a, std::vector<std::vector<long>>(b, std::vector<long>(c)));

            for (i = 0; i < a; i++) {
                for (j = 0; j < b; j++) {
                    for (k = 0; k < c; k++) {
                        std::cin >> m[i][j][k];

                        if (i > 0) {
                            m[i][j][k] += m[i - 1][j][k];
                        }

                        if (j > 0) {
                            m[i][j][k] += m[i][j - 1][k];
                        }

                        if (k > 0) {
                            m[i][j][k] += m[i][j][k - 1];
                        }

                        if (i > 0 && j > 0) {
                            m[i][j][k] -= m[i - 1][j - 1][k];
                        }

                        if (i > 0 && k > 0) {
                            m[i][j][k] -= m[i - 1][j][k - 1];
                        }

                        if (j > 0 && k > 0) {
                            m[i][j][k] -= m[i][j - 1][k - 1];
                        }

                        if (i > 0 && j > 0 && k > 0) {
                            m[i][j][k] += m[i - 1][j - 1][k - 1];
                        }
                    }
                }
            }

            max_sum = std::numeric_limits<long>::min();

            for (i = 0; i < a; i++) {
                for (j = 0; j < b; j++) {
                    for (k = 0; k < c; k++) {
                        for (i1 = i; i1 < a; i1++) {
                            for (j1 = j; j1 < b; j1++) {
                                for (k1 = k; k1 < c; k1++) {
                                    sum = m[i1][j1][k1];

                                    if (i > 0) {
                                        sum -= m[i - 1][j1][k1];
                                    }

                                    if (j > 0) {
                                        sum -= m[i1][j - 1][k1];
                                    }

                                    if (k > 0) {
                                        sum -= m[i1][j1][k - 1];
                                    }

                                    if (i > 0 && j > 0) {
                                        sum += m[i - 1][j - 1][k1];
                                    }

                                    if (i > 0 && k > 0) {
                                        sum += m[i - 1][j1][k - 1];
                                    }

                                    if (j > 0 && k > 0) {
                                        sum += m[i1][j - 1][k - 1];
                                    }

                                    if (i > 0 && j > 0 && k > 0) {
                                        sum -= m[i - 1][j - 1][k - 1];
                                    }

                                    if (sum > max_sum) {
                                        max_sum = sum;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            std::cout << max_sum << std::endl;

            if (t) {
                std::cout << std::endl;
            }
        }
    }
    
    return 0;
}
