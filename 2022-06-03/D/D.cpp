#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <utility>
#include <vector>

void articulation_point(const std::vector<std::list<unsigned>> & adj,
                        unsigned u,
                        unsigned & dfs_number_counter,
                        unsigned dfs_root,
                        unsigned & root_children,
                        std::vector<int> & dfs_low,
                        std::vector<int> & dfs_num,
                        std::vector<int> & dfs_parent,
                        std::vector<int> & articulation_points) {
    dfs_num[u] = dfs_low[u] = dfs_number_counter++; // dfs_low[u] <= dfs_num[u]

    for (const unsigned & v : adj[u]) {
        if (dfs_num[v] == -1) { // a tree edge
            dfs_parent[v] = u;

            if (u == dfs_root) { // special case if u is a root
                root_children++;
            }

            articulation_point(adj,
                               v,
                               dfs_number_counter,
                               dfs_root,
                               root_children,
                               dfs_low,
                               dfs_num,
                               dfs_parent,
                               articulation_points);

            if (dfs_low[v] >= dfs_num[u]) { // for articulation point
                articulation_points[u]++; // store this information first
            }

            dfs_low[u] = std::min(dfs_low[u], dfs_low[v]);
        } else if ((int) v != dfs_parent[u]) { // a back edge and not direct cycle
            dfs_low[u] = std::min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
    unsigned n, m, dfs_number_counter, u, dfs_root, root_children, i;
    int x, y;
    std::vector<std::list<unsigned>> adj;
    std::vector<int> dfs_low, dfs_num, dfs_parent, articulation_points;
    std::vector<std::pair<unsigned, unsigned>> permutation;

    while (std::cin >> n >> m && (n || m)) {
        dfs_number_counter = 0;
        adj.resize(n);
        adj.assign(n, std::list<unsigned>());
        dfs_low.resize(n, -1);
        dfs_low.assign(n, -1);
        dfs_num.resize(n, -1);
        dfs_num.assign(n, -1);
        dfs_parent.resize(n, -1);
        dfs_parent.assign(n, -1);
        articulation_points.resize(n, 0);
        articulation_points.assign(n, 0);
        permutation.resize(n);

        while (std::cin >> x >> y && x >= 0 && y >= 0) {
            adj[(unsigned) x].push_back((unsigned) y);
            adj[(unsigned) y].push_back((unsigned) x);
        }

        for (u = 0; u < n; u++) {
            if (dfs_num[u] == -1) {
                dfs_root = u;
                root_children = 0;
                articulation_point(adj,
                                   u,
                                   dfs_number_counter,
                                   dfs_root,
                                   root_children,
                                   dfs_low,
                                   dfs_num,
                                   dfs_parent,
                                   articulation_points);
                articulation_points[dfs_root] = (root_children > 1);
            }
        }

        for (u = 0; u < n; u++) {
            permutation[u] = std::make_pair(u, articulation_points[u] + 1);
        }

        std::sort(permutation.begin(), permutation.end(), [](const std::pair<unsigned, unsigned> & a, const std::pair<unsigned, unsigned> & b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }

            return a.second > b.second;
        });

        for (i = 0; i < m; i++) {
            std::cout << permutation[i].first << ' ' << permutation[i].second << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
