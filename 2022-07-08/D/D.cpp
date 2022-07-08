#include <iostream>
#include <limits>
#include <list>
#include <queue>
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
    std::vector<bool> visited(adj.size(), false);
    std::queue<unsigned> q;

    while (1) { // O(VE^2) (actually O(V^3E) Edmonds Karp's algorithm
        // run BFS
        visited.assign(adj.size(), false);
        q = std::queue<unsigned>();

        visited[s] = true;
        q.push(s);  // start from source
        p.assign(adj.size(), adj.size()); // record the BFS spanning tree, from s to t!

        while (!q.empty()) {
            u = q.front();  // queue: layer by layer!
            q.pop();

            if (u == t) {
                break;  // immediately stop BFS if we already reach sink t
            }
            
            // for each neighbor of u
            for (const unsigned & v : adj[u]) { // note: this part is slow
                // if v is unvisited + reachable
                if (res[u][v] > 0 && !visited[v]) {
                    visited[v] = true; // flag v
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

int main() {
    unsigned m, w, n, c, d, i, j, k, s, t;
    std::vector<std::list<unsigned>> adj;
    std::vector<unsigned> p;
    std::vector<std::vector<int>> res;

    adj.reserve(100);
    p.reserve(100);
    res.reserve(100);

    while (std::cin >> m >> w && (m || w)) {
        n = 2 * m; // split each vertex into 2 vertices

        s = 0; // boss
        t = n - 1; // server

        adj.resize(n, std::list<unsigned>());
        adj.assign(n, std::list<unsigned>());
        p.resize(n, n);
        p.assign(n, n);
        res.resize(n, std::vector<int>(n, 0));
        res.assign(n, std::vector<int>(n, 0));

        adj[0].push_back(m);
        adj[m].push_back(0);
        adj[m - 1].push_back(m + m - 1);
        adj[m + m - 1].push_back(m - 1);
        res[0][m] = res[m - 1][m + m - 1] = std::numeric_limits<int>::max() >> 2;

        for (j = 0; j + 2 < m; j++) {
            std::cin >> i >> c;

            i--; // convert to 0-based indexing

            adj[i].push_back(m + i);
            adj[m + i].push_back(i);
            res[i][m + i] = c;
        }

        while (w--) {
            std::cin >> j >> k >> d;
            
            // convert to 0-indexed
            j--;
            k--;

            adj[m + j].push_back(k);
            adj[k].push_back(m + j);
            adj[m + k].push_back(j);
            adj[j].push_back(m + k);
            res[m + j][k] = res[m + k][j] = d;
        }

        std::cout << edmonds_karp(adj, s, t, p, res) << std::endl;
    }

    return 0;
}
