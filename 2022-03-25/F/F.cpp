#include <iostream>
#include <vector>

int main() {
    unsigned n, r, c, k, i, j;
    std::vector<std::vector<unsigned>> prev_h, curr_h;

    while (std::cin >> n >> r >> c >> k && n && r && c && k) {
        curr_h.resize(r);

        for (i = 0; i < r; i++) {
            curr_h[i].resize(c);

            for (j = 0; j < c; j++) {
                std::cin >> curr_h[i][j];
            }
        }

        while (k--) {
            prev_h = curr_h;

            for (i = 0; i < r; i++) {
                for (j = 0; j < c; j++) {
                    if (i > 0 && prev_h[i][j] == (prev_h[i - 1][j] + 1) % n) {
                        curr_h[i][j] = prev_h[i - 1][j];
                    } else if (i < r - 1 && prev_h[i][j] == (prev_h[i + 1][j] + 1) % n) {
                        curr_h[i][j] = prev_h[i + 1][j];
                    } else if (j > 0 && prev_h[i][j] == (prev_h[i][j - 1] + 1) % n) {
                        curr_h[i][j] = prev_h[i][j - 1];
                    } else if (j < c - 1 && prev_h[i][j] == (prev_h[i][j + 1] + 1) % n) {
                        curr_h[i][j] = prev_h[i][j + 1];
                    }
                }
            }
        }

        for (i = 0; i < r; i++) {
            for (j = 0; j < c - 1; j++) {
                std::cout << curr_h[i][j] << ' ';
            }
            std::cout << curr_h[i][c - 1] << std::endl;
        }
    }

    return 0;
}
