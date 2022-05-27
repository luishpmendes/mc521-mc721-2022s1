#include <iostream>
#include <list>
#include <queue>
#include <vector>

unsigned get_uncolored_vertex(unsigned n, const std::vector<unsigned> & color) {
    for (unsigned v = 0; v < n; v++) {
        if (color[v] == 2) {
            return v;
        }
    }
    return n;
}

int main() {
    unsigned t, n, m, i, u, v, s, num_colored, num_new_zero, num_new_one, ans;
    std::vector<std::list<unsigned>> adj;
    std::vector<unsigned> color;
    std::queue<unsigned> q;
    bool is_bipartite;
    std::list<unsigned>::iterator it;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n >> m;
            adj.clear();
            adj.resize(n);
            color.clear();
            color.resize(n, 2);
            q = std::queue<unsigned>();
            num_colored = 0;
            is_bipartite = true;
            ans = 0;

            for (i = 0; i < m; i++) {
                std::cin >> u >> v;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            while (is_bipartite && num_colored < n) {
                num_new_zero = num_new_one = 0;
                s = get_uncolored_vertex(n, color);
                q.push(s);
                color[s] = 0;
                num_new_zero = 1;
                num_colored++;

                while (!q.empty() && is_bipartite) {
                    u = q.front();
                    q.pop();

                    for (it = adj[u].begin(); it != adj[u].end() && is_bipartite; it++) {
                        v = *it;

                        if (color[v] == 2) {
                            color[v] = 1 - color[u];
                            q.push(v);
                            num_colored++;

                            if (color[v] == 0) {
                                num_new_zero++;
                            } else {
                                num_new_one++;
                            }
                        } else if (color[v] == color[u]) {
                            is_bipartite = false;
                        }
                    }
                }

                if (is_bipartite) {
                    if (num_new_zero < num_new_one) {
                        ans += num_new_zero;

                        if (num_new_zero == 0) {
                            ans++;
                        }
                    } else {
                        ans += num_new_one;

                        if (num_new_one == 0) {
                            ans++;
                        }
                    }
                }
            }

            if (is_bipartite) {
                std::cout << ans << std::endl;
            } else {
                std::cout << -1 << std::endl;
            }
        }
    }

    return 0;
}
