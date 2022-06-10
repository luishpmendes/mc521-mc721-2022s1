#include <iostream>
#include <vector>

int main() {
    unsigned t, n, v, u, color;
    std::vector<unsigned> p;
    std::vector<bool> leaf, used;
    std::vector<std::vector<unsigned>> paths;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;

            p.resize(n);
            leaf.resize(n, true);
            leaf.assign(n, true);
            paths.resize(n, std::vector<unsigned>());
            paths.assign(n, std::vector<unsigned>());
            used.resize(n, false);
            used.assign(n, false);
            color = 0;

            for (v = 0; v < n; v++) {
                std::cin >> p[v];
                p[v]--;
                leaf[p[v]] = false;
            }

            if (n == 1) {
                std::cout << 1 << std::endl
                          << 1 << std::endl
                          << 1 << std::endl
                               << std::endl;
            } else {
                for (u = 0; u < n; u++) {
                    if (leaf[u]) {
                        used[u] = true;
                        paths[color].push_back(u);

                        v = u;

                        while (p[v] != v && !used[p[v]]) {
                            v = p[v];
                            used[v] = true;
                            paths[color].push_back(v);
                        }

                        color++;
                    }
                }

                std::cout << color << std::endl;

                for (u = 0; u < color; u++) {
                    std::cout << paths[u].size() << std::endl;

                    for (v = paths[u].size(); v > 1; v--) {
                        std::cout << paths[u][v - 1] + 1 << ' ';
                    }

                    std::cout << paths[u][0] + 1 << std::endl;
                }

                std::cout << std::endl;
            }
        }
    }

    return 0;
}
