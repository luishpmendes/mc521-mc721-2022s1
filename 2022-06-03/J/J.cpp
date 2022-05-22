#include <iostream>
#include <string>
#include <vector>

int main() {
    unsigned r, c, i, j;
    std::vector<std::string> pasture;
    bool ans;

    while (std::cin >> r >> c) {
        pasture.resize(r);

        for (std::string & s : pasture) {
            std::cin >> s;
        }

        ans = true;

        for (i = 0; i < r && ans; i++) {
            for (j = 0; j < c && ans; j++) {
                if (pasture[i][j] == 'W') {
                    if ((i > 0 && pasture[i - 1][j] == 'S') ||
                        (i < r - 1 && pasture[i + 1][j] == 'S') ||
                        (j > 0 && pasture[i][j - 1] == 'S') ||
                        (j < c - 1 && pasture[i][j + 1] == 'S')) {
                        ans = false;
                    }
                }
            }
        }

        if (ans) {
            std::cout << "Yes" << std::endl;

            for (i = 0; i < r; i++) {
                for (j = 0; j < c; j++) {
                    if (pasture[i][j] == 'W') {
                        if (i > 0 && pasture[i - 1][j] == '.') {
                            pasture[i - 1][j] = 'D';
                        }
                        if (i < r - 1 && pasture[i + 1][j] == '.') {
                            pasture[i + 1][j] = 'D';
                        }
                        if (j > 0 && pasture[i][j - 1] == '.') {
                            pasture[i][j - 1] = 'D';
                        }
                        if (j < c - 1 && pasture[i][j + 1] == '.') {
                            pasture[i][j + 1] = 'D';
                        }
                    }
                }
            }

            for (i = 0; i < r; i++) {
                std::cout << pasture[i] << std::endl;
            }
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}
