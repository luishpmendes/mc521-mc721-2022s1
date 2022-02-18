#include <iostream>
#include <vector>

int main() {
    std::vector<unsigned> a(6);
    unsigned i, j, k, sum;
    bool result;

    while (std::cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5]) {
        sum = a[0] + a[1] + a[2] + a[3] + a[4] + a[5];
        result = false;

        for (i = 0; i < 6 && !result; i++) {
            for (j = i + 1; j < 6 && !result; j++) {
                for (k = j + 1; k < 6 && !result; k++) {
                    if (2 * (a[i] + a[j] + a[k]) == sum) {
                        result = true;
                    }
                }
            }
        }

        if (result) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
