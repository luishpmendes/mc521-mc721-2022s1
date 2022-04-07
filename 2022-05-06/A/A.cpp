#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    unsigned t, n, i, j, result;
    std::vector<unsigned> w, lis, lds;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;

            w.resize(n);
            for (i = n; i > 0; i--) {
                std::cin >> w[i - 1];
            }

            lis.resize(n);
            lis[0] = 1;
            for (i = 1; i < n; i++) {
                lis[i] = 1;
                for (j = 0; j < i; j++) {
                    if (w[i] > w[j]) {
                        lis[i] = std::max(lis[i], lis[j] + 1);
                    }
                }
            }

            lds.resize(n);
            lds[0] = 1;
            for (i = 1; i < n; i++) {
                lds[i] = 1;
                for (j = 0; j < i; j++) {
                    if (w[i] < w[j]) {
                        lds[i] = std::max(lds[i], lds[j] + 1);
                    }
                }
            }

            result = 0;
            for (i = 0; i < n; i++) {
                if (result < lis[i] + lds[i] - 1) {
                    result = lis[i] + lds[i] - 1;
                }
            }

            std::cout << result << std::endl;
        }
    }
    
    return 0;
}
