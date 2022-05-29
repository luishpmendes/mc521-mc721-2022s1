#include <iostream>
#include <list>
#include <map>
#include <string>
#include <queue>
#include <vector>

int main() {
    unsigned n, m, t, i, u;
    std::string b1, b2;
    std::vector<std::string> id_to_name;
    std::map<std::string, unsigned> name_to_id;
    std::vector<std::list<unsigned>> adj;
    std::vector<unsigned> in_degree;
    std::vector<bool> used;
    std::priority_queue<int> q;
    std::vector<unsigned> ans;

    t = 0;

    while (std::cin >> n) {
        id_to_name.resize(n, "");
        id_to_name.assign(n, "");
        name_to_id.clear();
        adj.resize(n, std::list<unsigned>());
        adj.assign(n, std::list<unsigned>());
        in_degree.resize(n, 0);
        in_degree.assign(n, 0);
        used.resize(n, false);
        used.assign(n, false);
        q = std::priority_queue<int>();
        ans.clear();

        for (u = 0; u < n; u++) {
            std::cin >> id_to_name[u];
            name_to_id[id_to_name[u]] = u;
        }

        std::cin >> m;

        for (i = 0; i < m; i++) {
            std::cin >> b1 >> b2;
            adj[name_to_id[b1]].push_back(name_to_id[b2]);
            in_degree[name_to_id[b2]]++;
        }

        for (u = 0; u < n; u++) {
            if (in_degree[u] == 0) {
                q.push(-u);
            }
        }

        while (!q.empty()) {
            u = -q.top();
            q.pop();
            used[u] = true;
            ans.push_back(u);

            for (const unsigned & v : adj[u]) {
                if (!used[v]) {
                    in_degree[v]--;
                    if (in_degree[v] == 0) {
                        q.push(-v);
                    }
                }
            }
        }

        std::cout << "Case #" << ++t << ": Dilbert should drink beverages in this order: ";

        for (i = 0; i < n - 1; i++) {
            std::cout << id_to_name[ans[i]] << ' ';
        }

        std::cout << id_to_name[ans[n - 1]] << "." << std::endl << std::endl;
    }

    return 0;
}
