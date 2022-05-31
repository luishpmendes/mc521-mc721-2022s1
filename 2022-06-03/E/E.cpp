#include <iostream>
#include <limits>
#include <list>
#include <stack>
#include <vector>

void tarjanSCC(const std::vector<std::list<unsigned>> & adj,
               std::vector<unsigned> & scc,
               std::vector<unsigned> & dfs_low,
               std::vector<unsigned> & dfs_num,
               std::stack<unsigned> & s,
               std::vector<bool> & visited,
               unsigned & dfs_number_counter,
               unsigned & num_scc,
               const unsigned & u) {
    dfs_low[u] = dfs_num[u] = dfs_number_counter++; // dfs_low[u] <= dfs_num[u]
    s.push(u);
    visited[u] = true;

    for (const unsigned & v : adj[u]) {
        if (dfs_num[v] == std::numeric_limits<unsigned>::max()) { // v is not visited
            tarjanSCC(adj, scc, dfs_low, dfs_num, s, visited, dfs_number_counter, num_scc, v);
        }

        if (visited[v]) { // condition for update
            dfs_low[u] = std::min(dfs_low[u], dfs_low[v]);
        }
    }

    if (dfs_low[u] == dfs_num[u]) { // if this is a root (start) of an SCC
        unsigned v = std::numeric_limits<unsigned>::max();

        do {
            v = s.top();
            s.pop();
            visited[v] = false;
            scc[v] = num_scc;
        } while (u != v);

        num_scc++;
    }
}

int main() {
    unsigned t, n, m, x, y, dfs_number_counter, num_SCC, u, ans;
    std::vector<std::list<unsigned>> adj, new_adj;
    std::vector<unsigned> scc, dfs_low, dfs_num, in_degree;
    std::stack<unsigned> s;
    std::vector<bool> visited;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n >> m;

            adj.resize(n, std::list<unsigned>());
            adj.assign(n, std::list<unsigned>());
            scc.resize(n, std::numeric_limits<unsigned>::max());
            scc.assign(n, std::numeric_limits<unsigned>::max());
            dfs_low.resize(n, 0);
            dfs_low.assign(n, 0);
            dfs_num.resize(n, std::numeric_limits<unsigned>::max());
            dfs_num.assign(n, std::numeric_limits<unsigned>::max());
            visited.resize(n, false);
            visited.assign(n, false);
            s = std::stack<unsigned>();
            dfs_number_counter = num_SCC = ans = 0;

            while (m--) {
                std::cin >> x >> y;
                adj[x - 1].push_back(y - 1);
            }

            for (u = 0; u < n; u++) {
                if (dfs_num[u] == std::numeric_limits<unsigned>::max()) {
                    tarjanSCC(adj, scc, dfs_low, dfs_num, s, visited, dfs_number_counter, num_SCC, u);
                }
            }

            new_adj.resize(num_SCC, std::list<unsigned>());
            new_adj.assign(num_SCC, std::list<unsigned>());

            for (u = 0; u < n; u++) {
                for (const unsigned & v : adj[u]) {
                    if (scc[u] != scc[v]) {
                        new_adj[scc[u]].push_back(scc[v]);
                    }
                }
            }

            in_degree.resize(num_SCC, 0);
            in_degree.assign(num_SCC, 0);

            for (u = 0; u < num_SCC; u++) {
                for (const unsigned & v : new_adj[u]) {
                    in_degree[v]++;
                }
            }

            for (u = 0; u < num_SCC; u++) {
                if (in_degree[u] == 0) {
                    ans++;
                }
            }

            std::cout << ans << std::endl;
        }
    }

    return 0;
}
