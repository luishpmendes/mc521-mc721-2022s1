#include <algorithm>
#include <iostream>
#include <limits>
#include <list>
#include <queue>
#include <set>
#include <vector>

unsigned augment(const unsigned & n,
             const unsigned & v,
             const int & minEdge,
             const unsigned & s,
             const std::vector<unsigned> & p,
             std::vector<std::vector<int>> & res) {
    unsigned f = 0;

    if (v == s) {
        f = minEdge;
    } else if(p[v] != n) {
        f = augment(n, p[v], std::min(minEdge, res[p[v]][v]), s, p, res);
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }

    return f;
}

unsigned edmonds_karp(const std::vector<std::list<unsigned>> & adj,
                      const unsigned & s,
                      const unsigned & t,
                      std::vector<unsigned> & p,
                      std::vector<std::vector<int>> & res) {
    unsigned mf = 0, // mf stands for max_flow
             f, u;
    std::vector<unsigned> d(adj.size(), std::numeric_limits<unsigned>::max() >> 2);
    std::queue<unsigned> q;

    while (1) { // O(VE^2) (actually O(V^3E) Edmonds Karp's algorithm
        // run BFS
        d.assign(adj.size(), std::numeric_limits<unsigned>::max() >> 2);
        q = std::queue<unsigned>();

        d[s] = 0; // distance from source s to s is 0
        q.push(s);  // start from source
        p.assign(adj.size(), adj.size()); // record the BFS spanning tree, from s to t!

        while (!q.empty()) {
            u = q.front();  // queue: layer by layer!
            q.pop();

            if (u == t) {
                break;  // immediately stop BFS if we already reach sink t
            }
            
            // for each neighbor of u
            for (auto & v : adj[u]) { // note: this part is slow
                // if v is unvisited + reachable
                if (res[u][v] > 0 && d[v] == std::numeric_limits<unsigned>::max() >> 2) {
                    d[v] = d[u] + 1; // make d[v] != INF to flag it
                    q.push(v); // enqueue v for the next iteration
                    p[v] = u;
                }
            }
        }
        
        // find the min edge weight `f' along this path, if any
        f = augment(adj.size(), t, std::numeric_limits<int>::max() >> 2, s, p, res);

        if (f == 0) {
            break; // we cannot send any more flow (`f' = 0), terminate
        }

        // we can still send a flow, increase the max flow!
        mf += f;
    }

    return mf;
}

void dfs(const std::vector<std::list<unsigned>> & adj,
         const std::vector<std::vector<int>> & res,
         unsigned u,
         std::vector<bool> & visited,
         std::set<unsigned> & component) {
    visited[u] = true;
    component.insert(u);

    for (auto & v : adj[u]) {
        if (!visited[v] && res[u][v] > 0) {
            dfs(adj, res, v, visited, component);
        }
    }
}

void mincut(const std::vector<std::list<unsigned>> & adj,
            const std::vector<std::vector<int>> & res,
            const unsigned & s) {
    std::set<unsigned> component;
    std::vector<bool> visited(adj.size(), false);

    dfs(adj, res, s, visited, component);

    for (auto & u : component) {
        for (auto & v : adj[u]) {
            if (component.find(v) == component.end()) {
                std::cout << u + 1 << " " << v + 1 << std::endl;
            }
        }
    }

    std::cout << std::endl;
}

int main() {
    unsigned n, m, u, v, w;
    std::vector<std::list<unsigned>> adj;
    std::vector<unsigned> p;
    std::vector<std::vector<int>> res;

    adj.reserve(50);
    p.reserve(50);
    res.reserve(50);

    while (std::cin >> n >> m && (n || m)) {
        adj.resize(n, std::list<unsigned>());
        adj.assign(n, std::list<unsigned>());
        p.resize(n, n);
        p.assign(n, n);
        res.resize(n, std::vector<int>(n, 0));
        res.assign(n, std::vector<int>(n, 0));

        while (m--) {
            std::cin >> u >> v >> w;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            res[u][v] = w;
            res[v][u] = w;
        }

        edmonds_karp(adj, 0, 1, p, res);
        mincut(adj, res, 0);
    }

    return 0;
}
