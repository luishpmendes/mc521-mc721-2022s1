#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <utility>
#include <vector>

int main() {
    unsigned n, c, u, v, s, t, i, min_cost;
    char ym, ub, x, y, me, miguel;
    std::map<char, unsigned> name_to_id;
    std::vector<char> id_to_name, min_places;
    std::vector<std::pair<std::pair<unsigned, unsigned>, unsigned>> edges_y, edges_m;
    std::vector<std::vector<unsigned>> adj_y, adj_m;

    while (std::cin >> n && n) {
        name_to_id.clear();
        edges_y.clear();
        edges_m.clear();
        adj_y.clear();
        adj_m.clear();

        while (n--) {
            std::cin >> ym >> ub >> x >> y >> c;
            
            if (name_to_id.find(x) == name_to_id.end()) {
                name_to_id[x] = name_to_id.size();
            }

            if (name_to_id.find(y) == name_to_id.end()) {
                name_to_id[y] = name_to_id.size();
            }

            u = name_to_id[x];
            v = name_to_id[y];

            if (ym == 'Y') {
                edges_y.push_back({{u, v}, c});

                if (ub == 'B') {
                    edges_y.push_back({{v, u}, c});
                }
            } else { // ym == 'M'
                edges_m.push_back({{u, v}, c});

                if (ub == 'B') {
                    edges_m.push_back({{v, u}, c});
                }
            }
        }

        std::cin >> me >> miguel;

        if (name_to_id.find(me) == name_to_id.end()) {
            name_to_id[me] = name_to_id.size();
        }

        if (name_to_id.find(miguel) == name_to_id.end()) {
            name_to_id[miguel] = name_to_id.size();
        }

        s = name_to_id[me];
        t = name_to_id[miguel];

        n = name_to_id.size();

        id_to_name.resize(n);

        for (auto& p : name_to_id) {
            id_to_name[p.second] = p.first;
        }

        adj_y.resize(n, std::vector<unsigned>(n, std::numeric_limits<unsigned>::max() >> 2));
        adj_y.assign(n, std::vector<unsigned>(n, std::numeric_limits<unsigned>::max() >> 2));
        adj_m.resize(n, std::vector<unsigned>(n, std::numeric_limits<unsigned>::max() >> 2));
        adj_m.assign(n, std::vector<unsigned>(n, std::numeric_limits<unsigned>::max() >> 2));

        for (const std::pair<std::pair<unsigned, unsigned>, unsigned> & edge : edges_y) {
            adj_y[edge.first.first][edge.first.second] = edge.second;
        }

        for (const std::pair<std::pair<unsigned, unsigned>, unsigned> & edge : edges_m) {
            adj_m[edge.first.first][edge.first.second] = edge.second;
        }

        for (v = 0; v < n; v++) {
            adj_y[v][v] = 0;
            adj_m[v][v] = 0;
        }

        for (i = 0; i < n; i++) {
            for (u = 0; u < n; u++) {
                for (v = 0; v < n; v++) {
                    adj_y[u][v] = std::min(adj_y[u][v], adj_y[u][i] + adj_y[i][v]);
                    adj_m[u][v] = std::min(adj_m[u][v], adj_m[u][i] + adj_m[i][v]);
                }
            }
        }

        min_cost = std::numeric_limits<unsigned>::max() >> 2;
        min_places.clear();

        for (v = 0; v < n; v++) {
            if (min_cost == adj_y[s][v] + adj_m[t][v]) {
                min_places.push_back(id_to_name[v]);
            }

            if (min_cost > adj_y[s][v] + adj_m[t][v]) {
                min_cost = adj_y[s][v] + adj_m[t][v];
                min_places.clear();
                min_places.push_back(id_to_name[v]);
            }
        }

        std::sort(min_places.begin(), min_places.end());

        if (min_cost < std::numeric_limits<unsigned>::max() >> 2) {
            std::cout << min_cost << ' ';

            for (i = 0; i < min_places.size() - 1; i++) {
                std::cout << min_places[i] << ' ';
            }

            std::cout << min_places.back() << std::endl;
        } else {
            std::cout << "You will never meet." << std::endl;
        }
    }

    return 0;
}
