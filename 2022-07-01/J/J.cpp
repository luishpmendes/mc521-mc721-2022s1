#include <iostream>
#include <limits>
#include <list>
#include <queue>
#include <string>
#include <vector>

void bfs(const std::vector<std::list<unsigned>> & adj, unsigned s, std::queue<unsigned> & q, std::vector<unsigned> & dist) {
    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        unsigned u = q.front();
        q.pop();

        for (const unsigned & v : adj[u]) {
            if (dist[v] == std::numeric_limits<unsigned>::max() >> 2) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    unsigned n, d, i, j;
    std::string s;
    std::vector<std::list<unsigned>> adj;
    std::queue<unsigned> q;
    std::vector<unsigned> dist;

    while (std::cin >> n >> d >> s) {
        adj.resize(n, std::list<unsigned>());
        adj.assign(n, std::list<unsigned>());
        q = std::queue<unsigned>();
        dist.resize(n, std::numeric_limits<unsigned>::max() >> 2);
        dist.assign(n, std::numeric_limits<unsigned>::max() >> 2);

        for (i = 0; i < n; i++) {
            if (s[i] == '1') {
                for (j = i + 1; j <= i + d && j < n; j++) {
                    if (s[j] == '1') {
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
        }

        bfs(adj, 0, q, dist);

        if (dist.back() == std::numeric_limits<unsigned>::max() >> 2) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << dist.back() << std::endl;
        }
    }

    return 0;
}
