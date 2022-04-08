#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    unsigned t, k, i, j, counter, i1, i2, i3, i4, i5;
    std::vector<std::string> grid1(6), grid2(6), grid1t(5), grid2t(5);
    char p1, p2, p3, p4, p5;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> k;
            std::cin.ignore();

            for (std::string & s : grid1) {
                std::getline(std::cin, s);
            }

            for (std::string & s : grid2) {
                std::getline(std::cin, s);
            }

            for (i = 0; i < 5; i++) {
                grid1t[i] = "";
                grid2t[i] = "";
            }
            
            for (i = 0; i < 6; i++) {
                for (j = 0; j < 5; j++) {
                    grid1t[j] += grid1[i][j];
                    grid2t[j] += grid2[i][j];
                }
            }

            for (i = 0; i < 5; i++) {
                std::sort(grid1t[i].begin(), grid1t[i].end());
                std::sort(grid2t[i].begin(), grid2t[i].end());
            }

            counter = 0;

            for (i1 = 0; i1 < 6 && counter < k; i1++) {
                if (i1 == 0 || grid1t[0][i1] != grid1t[0][i1 - 1]) {
                    for (i2 = 0; i2 < 6 && counter < k; i2++) {
                        if (i2 == 0 || grid1t[1][i2] != grid1t[1][i2 - 1]) {
                            for (i3 = 0; i3 < 6 && counter < k; i3++) {
                                if (i3 == 0 || grid1t[2][i3] != grid1t[2][i3 - 1]) {
                                    for (i4 = 0; i4 < 6 && counter < k; i4++) {
                                        if (i4 == 0 || grid1t[3][i4] != grid1t[3][i4 - 1]) {
                                            for (i5 = 0; i5 < 6 && counter < k; i5++) {
                                                if (i5 == 0 || grid1t[4][i5] != grid1t[4][i5 - 1]) {
                                                    p1 = grid1t[0][i1];
                                                    p2 = grid1t[1][i2];
                                                    p3 = grid1t[2][i3];
                                                    p4 = grid1t[3][i4];
                                                    p5 = grid1t[4][i5];

                                                    if (binary_search(grid2t[0].begin(), grid2t[0].end(), p1) &&
                                                        binary_search(grid2t[1].begin(), grid2t[1].end(), p2) &&
                                                        binary_search(grid2t[2].begin(), grid2t[2].end(), p3) &&
                                                        binary_search(grid2t[3].begin(), grid2t[3].end(), p4) &&
                                                        binary_search(grid2t[4].begin(), grid2t[4].end(), p5)) {
                                                        counter++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if (counter == k) {
                std::cout << p1 << p2 << p3 << p4 << p5 << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }

    return 0;
}
