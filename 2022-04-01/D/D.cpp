#include <iostream>
#include <list>
#include <utility>
#include <vector>

void dfsVisit(const std::vector<std::list<unsigned>> & adj, const unsigned & u, std::vector<unsigned> & d, unsigned time) {
    time++;
    d[u] = time;

    for (const unsigned & v : adj[u]) {
        if (d[v] == 0) {
            dfsVisit(adj, v, d, time);
        }
    }
}

void dfs(const std::vector<std::list<unsigned>> & adj, const std::vector<unsigned> & roots, std::vector<unsigned> & d) {
    unsigned time = 0;

    for (const unsigned & r : roots) {
        if (d[r] == 0) {
            dfsVisit(adj, r, d, time);
        }
    }
}

int main() {
    unsigned n, i, p, result;
    std::vector<std::list<unsigned>> adj;
    std::vector<unsigned> d, roots;

    while (std::cin >> n) {
        adj.clear();
        adj.resize(n);
        d.clear();
        d.resize(n, 0);
        roots.clear();

        for (i = 0; i < n; ++i) {
            std::cin >> p;

            if (p == (unsigned) -1) {
                roots.push_back(i);
            } else {
                adj[i].push_back(p - 1);
                adj[p - 1].push_back(i);
            }
        }

        dfs(adj, roots, d);

        result = d[0];

        for (i = 1; i < n; ++i) {
            if (result < d[i]) {
                result = d[i];
            }
        }

        std::cout << result << std::endl;
    }

    return 0;
}
