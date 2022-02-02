#include <iostream>
#include <vector>

unsigned go (const unsigned & n,
             const unsigned & m,
             const std::vector<unsigned> & a,
             const std::vector<std::vector<unsigned>> & adj,
             unsigned v,
             unsigned pi,
             unsigned k) {
    unsigned result = 0;
    bool is_leaf = true;

    if (k <= m) {
        for (const unsigned & u : adj[v]) {
            if (u != pi) {
                is_leaf = false;
                result += go(n, m, a, adj, u, v, k * a[u] + a[u]);
            }
        }

        if (is_leaf) {
            result++;
        }
    }

    return result;
}

int main() {
    unsigned n, m, x, y, i;
    std::vector<unsigned> a;
    std::vector<std::vector<unsigned>> adj;

    while (std::cin >> n >> m) {
        a.resize(n);
        adj.resize(n);

        for (i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        for (i = 0; i < n - 1; i++) {
            std::cin >> x >> y;
            x--;
            y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        std::cout << go(n, m, a, adj, 0, 1000000, a[0]) << std::endl;
    }

    return 0;
}
