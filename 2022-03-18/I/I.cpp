#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    unsigned n, l, i;
    std::vector<unsigned> a;
    double result;

    std::cout << std::setprecision(10) << std::fixed;

    while (std::cin >> n >> l) {
        a.clear();
        a.resize(n);

        for (i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        std::sort(a.begin(), a.end());

        result = a.front();

        if (result < l - a.back()) {
            result = l - a.back();
        }

        for (i = 1; i < n; i++) {
            if (result < ((double) (a[i] - a[i - 1])) / 2.0) {
                result = ((double) (a[i] - a[i - 1])) / 2.0;
            }
        }

        std::cout << result << std::endl;
    }

    return 0;
}
