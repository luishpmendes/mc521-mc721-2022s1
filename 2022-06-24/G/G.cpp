#include <iostream>
#include <vector>

int main() {
    unsigned long long n, i, t, sum;
    std::vector<unsigned long long> a;

    while (std::cin >> n) {
        a.resize(n);
        t = (1 << 19);
        sum = 0;

        for (i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        for (i = 0; i < n - 1; i++) {
            while (i + t > n - 1) {
                t >>= 1;
            }

            a[i + t] += a[i];
            sum += a[i];

            std::cout << sum << std::endl;
        }
    }

    return 0;
}
