#include <iostream>
#include <vector>

int main() {
    unsigned t, n, k, i, l_i, r_i, v, u;
    std::vector<unsigned> a, b, l, r;
    std::vector<bool> used;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;

            k = 0;
            a.resize(n);
            b.resize(n, n);
            b.assign(n, n);
            used.resize(n, false);
            used.assign(n, false);
            
            for (i = 0; i < n; i++) {
                std::cin >> a[i];
                a[i]--;
            }

            for (i = 0; i < n; i++) {
                if (!used[a[i]] && a[i] != i) {
                    used[a[i]] = true;
                    b[i] = a[i];
                    k++;
                }
            }

            l_i = r_i = 0;
            l.resize(n - k);
            r.resize(n - k);

            for (i = 0; i < n; i++) {
                if (!used[i] && b[i] == n) {
                    l[l_i++] = i;
                    r[r_i++] = i;
                }
            }
            
            for (i = 0; i < n; i++) {
                if (used[i] && b[i] == n) {
                    l[l_i++] = i;
                }
            }

            for (i = 0; i < n; i++) {
                if (!used[i] && b[i] != n) {
                    r[r_i++] = i;
                }
            }

            for (i = 0; i + k < n; i++) {
                if (i + k + 1 == n) {
                    b[l[i]] = r.front();
                } else {
                    b[l[i]] = r[i + 1];
                }
            }

            if (n == k + 1 && l.front() == r.front()) {
                u = l.front();
                v = 0;

                while (u == v || (used[a[u]] && a[u] != b[v])) {
                    v++;
                }

                if (a[u] != b[v]) {
                    k--;
                }

                std::swap(b[u], b[v]);
            }

            std::cout << k << std::endl;

            for (i = 0; i + 1 < n; i++) {
                std::cout << b[i] + 1 << ' ';
            }

            std::cout << b.back() + 1 << std::endl;
        }
    }

    return 0;
}
