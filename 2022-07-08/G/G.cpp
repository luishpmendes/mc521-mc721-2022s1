#include <iostream>
#include <vector>

int main() {
    unsigned n, i, x;
    int ans;
    std::vector<unsigned> a(5, 0), b(5, 0);

    while (std::cin >> n) {
        a.assign(5, 0);
        b.assign(5, 0);
        ans = 0;

        for (i = 0; i < n; i++) {
            std::cin >> x;
            a[x-1]++;
        }

        for (i = 0; i < n; i++) {
            std::cin >> x;
            b[x-1]++;
        }

        for (i = 0; i < 5 && ans >= 0; i++) {
            if (a[i] > b[i]) {
                if ((a[i] - b[i]) % 2 == 0) {
                    ans += (a[i] - b[i]) / 2;
                } else {
                    ans = -1;
                }
            } else {
                if ((b[i] - a[i]) % 2 == 0) {
                    ans += (b[i] - a[i]) / 2;
                } else {
                    ans = -1;
                }
            }
        }

        if (ans > 0) {
            ans /= 2;
        }

        std::cout << ans << std::endl;
    }

    return 0;
}
