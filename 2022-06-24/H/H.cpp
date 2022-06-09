#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <queue>
#include <vector>

int main() {
    unsigned n, m, u, v, i;
    double ans;
    std::vector<std::list<unsigned>> adj;
    std::queue<unsigned> q;
    std::vector<unsigned> d;
    std::vector<std::vector<unsigned long long>> dp;

    while (std::cin >> n >> m) {
        adj.resize(n, std::list<unsigned>());
        adj.assign(n, std::list<unsigned>());
        q = std::queue<unsigned>();
        d.resize(n, std::numeric_limits<unsigned>::max() >> 2);
        d.assign(n, std::numeric_limits<unsigned>::max() >> 2);
        dp.resize(n, std::vector<unsigned long long>(n));
        dp.assign(n, std::vector<unsigned long long>(n));

        while (m--) {
            std::cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        d[0] = 0;
        q.push(0);
        dp[0][0] = 1;

        while (!q.empty()) {
            u = q.front();
            q.pop();
            dp[u][u] = dp[u][0];

            for (const unsigned & v : adj[u]) {
                if (d[v] >= d[u] + 1) {
                    if (d[v] == std::numeric_limits<unsigned>::max() >> 2) {
                        q.push(v);
                    }

                    d[v] = d[u] + 1;

                    for (i = 0; i < n; i++) {
                        dp[v][i] += dp[u][i];
                    }
                }
            }
        }

        ans = 1;

        for (i = 1; i < n - 1; i++) {
            if (ans < (double) (dp.back()[i] * 2.0) / (double) dp.back().front()) {
                ans = (double) (dp.back()[i] * 2.0) / (double) dp.back().front();
            }
        }

        std::cout << std::setprecision(12) << std::fixed << ans << std::endl;
    }

    return 0;
}
