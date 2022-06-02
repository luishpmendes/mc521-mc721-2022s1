#include <iostream>
#include <vector>

int main() {
    unsigned n, s, i;
    std::vector<unsigned> a, b;
    bool ans;

    while (std::cin >> n >> s) {
        s--;
        a.resize(n);
        b.resize(n);

        for (i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        for (i = 0; i < n; i++) {
            std::cin >> b[i];
        }

        ans = true;

        if (!a[0]) {
            ans = false;
        } else if (!a[s]) {
            ans = false;

            if (b[s]) {
                for (i = s + 1; i < n && !ans; i++) {
                    if (a[i] && b[i]) {
                        ans = true;
                    }
                }
            }
        }

        std::cout << (ans ? "YES" : "NO") << std::endl;
    }

    return 0;
}
