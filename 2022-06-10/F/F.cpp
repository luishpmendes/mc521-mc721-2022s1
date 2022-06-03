#include <iostream>
#include <limits>
#include <list>
#include <queue>
#include <utility>
#include <vector>

void dijkstra(const std::vector<std::list<std::pair<unsigned, unsigned>>> & adj, unsigned s, std::vector<unsigned> & dist, std::priority_queue<std::pair<unsigned, unsigned>, std::vector<std::pair<unsigned, unsigned>>, std::greater<std::pair<unsigned, unsigned>>> & pq) {
    dist[s] = 0;
    pq.push(std::make_pair(0, s));

    while (!pq.empty()) { // main loop
        unsigned u = pq.top().second, // greedy: get shortest unvisited vertex
                 d = pq.top().first;
        pq.pop();

        if (d > dist[u]) { // this is a very importat check
            continue;
        }

        for (const std::pair<unsigned, unsigned> & v : adj[u]) { // all outgoing edges from u
            if (dist[v.first] > dist[u] + v.second) {
                dist[v.first] = dist[u] + v.second; // relax operation
                pq.push(std::make_pair(dist[v.first], v.first));
            }
        }
    }
}

int main() {
    unsigned N, n, m, S, T, x, u, v, w;
    std::vector<std::list<std::pair<unsigned, unsigned>>> adj;
    std::vector<unsigned> dist;
    std::priority_queue<std::pair<unsigned, unsigned>, std::vector<std::pair<unsigned, unsigned>>, std::greater<std::pair<unsigned, unsigned>>> pq;

    while (std::cin >> N) {
        for (x = 1; x <= N; x++) {
            std::cin >> n >> m >> S >> T;

            adj.resize(n, std::list<std::pair<unsigned, unsigned>>());
            adj.assign(n, std::list<std::pair<unsigned, unsigned>>());
            dist.resize(n, std::numeric_limits<unsigned>::max() >> 2);
            dist.assign(n, std::numeric_limits<unsigned>::max() >> 2);
            pq = std::priority_queue<std::pair<unsigned, unsigned>, std::vector<std::pair<unsigned, unsigned>>, std::greater<std::pair<unsigned, unsigned>>>();

            while (m--) {
                std::cin >> u >> v >> w;

                adj[u].push_back(std::make_pair(v, w));
                adj[v].push_back(std::make_pair(u, w));
            }

            dijkstra(adj, S, dist, pq);

            if (dist[T] < std::numeric_limits<unsigned>::max() >> 2) {
                std::cout << "Case #" << x << ": " << dist[T] << std::endl;
            } else {
                std::cout << "Case #" << x << ": unreachable" << std::endl;
            }
        }
    }

    return 0;
}
