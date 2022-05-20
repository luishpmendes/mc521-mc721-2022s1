#include <iostream>
#include <vector>

int main() {
    unsigned t, n, s, i, ans;
    std::vector<unsigned> c;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;
            c.resize(n);

            for (unsigned & x : c) {
                std::cin >> x;
            }

            s = 0;
            ans = 1;

            for (i = 1; i < n; i++) {
                if (c[i] > s + c[i - 1]) {
                    s += c[i - 1];
                    ans++;
                }
            }

            std::cout << ans << std::endl;
        }
    }

    return 0;
}
