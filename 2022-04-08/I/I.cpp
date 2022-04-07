#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int main() {
    std::vector<unsigned> q (8), p (8);
    unsigned t = 0, i, j, counter, result;
    bool flag;

    while (std::cin >> q[0] >> q[1] >> q[2] >> q[3] >> q[4] >> q[5] >> q[6] >> q[7]) {
        for (i = 0; i < 8; i++) {
            p[i] = i + 1;
        }

        result = 64;

        do {
            flag = false;

            for (i = 0; i < 8 && !flag; i++) {
                for (j = i + 1; j < 8 && !flag; j++) {
                    if (abs(p[i] - p[j]) == abs(i - j)) {
                        flag = true;
                    }
                }
            }

            if (!flag) {
                counter = 0;

                for (i = 0; i < 8 && counter <= result; i++) {
                    if (p[i] != q[i]) {
                        counter++;
                    }
                }

                if (counter < result) {
                    result = counter;
                }
            }
        } while (std::next_permutation(p.begin(), p.end()));

        std::cout << "Case " << ++t << ": " << result << std::endl;
    }


    return 0;
}
