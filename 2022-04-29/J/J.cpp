#include <iostream>
#include <utility>
#include <vector>

int main() {
    unsigned n, q, Q, t, x, y, i, j, ax;
    std::vector<unsigned> p, r, a;

    while (std::cin >> n >> q) {
        p.resize(n);
        r.resize(n);
        a.resize(n);
        Q = 100;

        for (i = 0; i < n; i++) {
            std::cin >> p[i];
            p[i]--;
            r[p[i]] = i;
        }

        for (i = 0; i < n; i++) {
            x = i;

            for (j = 0; j < Q; j++) {
                x = p[x];
            }

            a[i] = x;
        }

        while (q--) {
            std::cin >> t >> x >> y;

            if (t == 1) {
                x--;
                y--;
                std::swap(r[p[x]], r[p[y]]);
                std::swap(p[x], p[y]);
                ax = x;

                for(i = 0; i < Q; i++) {
                    ax = p[ax];
                }

                for(i = 0; i < Q; i++) {
                    a[x] = ax;
                    x = r[x];
                    ax = r[ax];
                }
                
                std::swap(x, y);
                ax = x;

                for(i = 0; i < Q; i++) {
                    ax = p[ax];
                }

                for(i = 0; i < Q; i++) {
                    a[x] = ax;
                    x = r[x];
                    ax = r[ax];
                }
            } else { // t == 2
                x--;

                while(y >= Q) {
                    y -= Q;
                    x = a[x];
                }

                while(y--) {
                    x = p[x];
                }

                std::cout << x + 1 << std::endl;
            }
        }
    }

    return 0;
}
