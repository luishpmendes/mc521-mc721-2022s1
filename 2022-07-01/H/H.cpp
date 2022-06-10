#include <iostream>
#include <list>
#include <vector>

void dfs(const std::vector<std::list<unsigned>> & adj,
         const unsigned & u,
         const unsigned & pi,
         const unsigned & color,
         std::vector<unsigned> & counter) {
    counter[color]++;

    for (const unsigned & v : adj[u]) {
        if (v != pi) {
            dfs(adj, v, u, 1 - color, counter);
        }
    }
}

int main() {
    unsigned n, i, u, v;
    std::vector<std::list<unsigned>> adj;
    std::vector<unsigned> counter;

    while (std::cin >> n) {
        adj.resize(n, std::list<unsigned>());
        adj.assign(n, std::list<unsigned>());
        counter.resize(2, 0);
        counter.assign(2, 0);

        for (i = 0; i < n - 1; i++) {
            std::cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(adj, 0, 0, 0, counter);

        std::cout << counter[0] * counter[1] - n + 1 << std::endl;
    }

    return 0;
}
