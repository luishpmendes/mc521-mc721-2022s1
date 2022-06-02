#include <iostream>
#include <vector>

int main() {
    unsigned n, i;
    std::vector<unsigned> f;
    bool ans;

    while (std::cin >> n) {
        f.resize(n);

        for (i = 0; i < n; i++) {
            std::cin >> f[i];
            f[i]--;
        }

        ans = false;

        for (i = 0; i < n && !ans; i++) {
            if (f[f[f[i]]] == i) {
                ans = true;
            }
        }

        std::cout << (ans ? "YES" : "NO") << std::endl;
    }

    return 0;
}
