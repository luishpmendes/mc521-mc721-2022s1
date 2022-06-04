#include <iostream>
#include <limits>
#include <list>
#include <queue>
#include <utility>
#include <vector>

void dijkstra(const std::vector<std::list<std::pair<unsigned long long, unsigned long long>>> & adj,
              const unsigned long long & s,
              std::vector<unsigned long long> & dist,
              std::vector<unsigned long long> & pi,
              std::priority_queue<std::pair<unsigned long long, unsigned long long>,
                                  std::vector<std::pair<unsigned long long, unsigned long long>>,
                                  std::greater<std::pair<unsigned long long, unsigned long long>>> & pq) {
    dist[s] = 0;
    pq.push(std::make_pair(0, s));

    while (!pq.empty()) { // main loop
        unsigned long long u = pq.top().second, // greedy: get shortest unvisited vertex
                           d = pq.top().first;
        pq.pop();

        if (d > dist[u]) { // this is a very importat check
            continue;
        }

        for (const std::pair<unsigned long long, unsigned long long> & v : adj[u]) { // all outgoing edges from u
            if (dist[v.first] > dist[u] + v.second) {
                dist[v.first] = dist[u] + v.second; // relax operation
                pi[v.first] = u;
                pq.push(std::make_pair(dist[v.first], v.first));
            }
        }
    }
}

int main() {
    unsigned long long n, m, a, b, w;
    std::vector<std::list<std::pair<unsigned long long, unsigned long long>>> adj;
    std::vector<unsigned long long> dist, pi, ans;
    std::priority_queue<std::pair<unsigned long long, unsigned long long>,
                        std::vector<std::pair<unsigned long long, unsigned long long>>,
                        std::greater<std::pair<unsigned long long, unsigned long long>>> pq;

    while (std::cin >> n >> m) {
        adj.resize(n, std::list<std::pair<unsigned long long, unsigned long long>>());
        adj.assign(n, std::list<std::pair<unsigned long long, unsigned long long>>());
        dist.resize(n, std::numeric_limits<unsigned long long>::max() >> 2);
        dist.assign(n, std::numeric_limits<unsigned long long>::max() >> 2);
        pi.resize(n, n);
        pi.assign(n, n);
        pq = std::priority_queue<std::pair<unsigned long long, unsigned long long>,
                                 std::vector<std::pair<unsigned long long, unsigned long long>>,
                                 std::greater<std::pair<unsigned long long, unsigned long long>>>();

        while (m--) {
            std::cin >> a >> b >> w;
            a--;
            b--;

            adj[a].push_back(std::make_pair(b, w));
            adj[b].push_back(std::make_pair(a, w));
        }

        dijkstra(adj, 0, dist, pi, pq);

        if (pi[n - 1] < n) {
            ans.clear();

            for (a = n - 1; a != 0; a = pi[a]) {
                ans.push_back(a);
            }

            ans.push_back(0);

            for (a = ans.size(); a > 1; a--) {
                std::cout << ans[a - 1] + 1 << " ";
            }

            std::cout << ans[0] + 1 << std::endl;
        } else {
            std::cout << -1 << std::endl;
        }
    }

    return 0;
}
