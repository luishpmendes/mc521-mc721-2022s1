#include <iostream>
#include <vector>

int main() {
    unsigned t, n, a, i;
    std::vector<bool> used;
    bool ans;

    std::cin.sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;

            used.resize(n, false);
            used.assign(n, false);
            ans = true;

            for (i = 0; i < n; i++) {
                std::cin >> a;

                while (a > n || (a > 0 && used[a - 1])) {
                    a >>= 1;
                }
                
                if (a > 0) {
                    used[a - 1] = true;
                } else {
                    ans = false;
                }
            }

            std::cout << (ans ? "YES" : "NO") << std::endl;
        }
    }

    return 0;
}
