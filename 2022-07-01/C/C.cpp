#include <iostream>
#include <string>
#include <list>
#include <utility>
#include <vector>

int dfs(const std::vector<std::list<unsigned>> & adj,
        const std::string & s,
        const unsigned & u,
        std::vector<bool> & visited,
        std::vector<int> & balance) {
    int result;

    if (s[u] == 'B') {
        result = -1;
    } else { // s[u] == 'W'
        result = +1;
    }

    visited[u] = true;

    for (auto v : adj[u]) {
        if (!visited[v]) {
            result += dfs(adj, s, v, visited, balance);
        }
    }

    balance[u] = result;

    return result;
}

int main() {
    unsigned t, n, i, ans;
    std::vector<unsigned> a;
    std::string s;
    std::vector<std::list<unsigned>> adj;
    std::vector<bool> visited;
    std::vector<int> balance;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;

            a.resize(n);
            a[0] = n;
            adj.resize(n, std::list<unsigned>());
            adj.assign(n, std::list<unsigned>());
            visited.resize(n, false);
            visited.assign(n, false);
            balance.resize(n, 0);
            balance.assign(n, 0);
            ans = 0;

            for (i = 1; i < n; i++) {
                std::cin >> a[i];
                a[i]--;

                adj[a[i]].push_back(i);
                adj[i].push_back(a[i]);
            }

            std::cin >> s;

            dfs(adj, s, 0, visited, balance);

            for (i = 0; i < n; i++) {
                if (balance[i] == 0) {
                    ans++;
                }
            }

            std::cout << ans << std::endl;
        }
    }

    return 0;
}
