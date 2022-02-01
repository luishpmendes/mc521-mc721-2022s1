#include <iostream>

int main() {
    unsigned i, j, r, c, x, result;
    bool flag;

    flag = true;

    while (flag) {
        i = j = r = c = x = result = 0;

        for (i = 1; i <= 5 && flag; i++) {
            for (j = 1; j <= 5 && flag; j++) {
                if (std::cin >> x) {
                    if (x == 1) {
                        r = i;
                        c = j;
                    }
                } else {
                    flag = false;
                }
            }
        }

        if (flag) {
            if (r >= 3) {
                result += r - 3;
            } else {
                result += 3 - r;
            }

            if (c >= 3) {
                result += c - 3;
            } else {
                result += 3 - c;
            }

            std::cout << result << std::endl;
        }
    }

    return 0;
}
