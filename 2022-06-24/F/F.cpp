#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <vector>

int main() {
    unsigned p, r, c, ans, u, v, i;
    std::string s, t;
    std::map<std::string, unsigned> name_to_id;
    std::vector<std::vector<unsigned>> adj;

    c = 1;

    while (std::cin >> p >> r && (p || r)) {
        name_to_id.clear();
        adj.resize(p, std::vector<unsigned>(p, std::numeric_limits<unsigned>::max() >> 2));
        adj.assign(p, std::vector<unsigned>(p, std::numeric_limits<unsigned>::max() >> 2));

        while (r--) {
            std::cin >> s >> t;

            if (name_to_id.find(s) == name_to_id.end()) {
                name_to_id[s] = name_to_id.size();
            }

            u = name_to_id[s];

            if (name_to_id.find(t) == name_to_id.end()) {
                name_to_id[t] = name_to_id.size();
            }

            v = name_to_id[t];

            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        // Floyd Warshall's algorithm
        for (i = 0; i < p; i++) {
            for (u = 0; u < p; u++) {
                for (v = 0; v < p; v++) {
                    adj[u][v] = std::min(adj[u][v], adj[u][i] + adj[i][v]);
                }
            }
        }

        ans = 0;

        for (u = 0; u < p; u++) {
            for (v = 0; v < p; v++) {
                if (u != v) {
                    ans = std::max(ans, adj[u][v]);
                }
            }
        }

        std::cout << "Network " << c++ << ": ";

        if (ans >= std::numeric_limits<unsigned>::max() >> 2) {
            std::cout << "DISCONNECTED";
        } else {
            std::cout << ans;
        }

        std::cout << std::endl << std::endl;
    }

    return 0;
}
