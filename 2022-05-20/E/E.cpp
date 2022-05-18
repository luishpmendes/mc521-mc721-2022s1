#include <iostream>
#include <limits>
#include <vector>

int tsp(unsigned pos, int bitmask, unsigned n, const std::vector<std::vector<int>> & dist, std::vector<std::vector<int>> & memo) {
    // bitmask stores the visited coordinates
    if (bitmask == (1 << (n + 1)) - 1) {
        return dist[pos][0]; // return trip to close the loop
    }

    if (memo[pos][bitmask] != -1) {
        return memo[pos][bitmask];
    }

    int ans = std::numeric_limits<int>::max();

    for (unsigned nxt = 0; nxt <= n; nxt++) { // O(n) here
        if (nxt != pos && !(bitmask & (1 << nxt))) { // if coordinate nxt is not visited yet
            if (ans > dist[pos][nxt] + tsp(nxt, bitmask | (1 << nxt), n, dist, memo)) {
                ans = dist[pos][nxt] + tsp(nxt, bitmask | (1 << nxt), n, dist, memo);
            }
        }
    }

    return memo[pos][bitmask] = ans;
}

int main() {
    unsigned t, x_size, y_size, n, i, j;
    std::vector<unsigned> x(1), y(1);
    std::vector<std::vector<int>> dist;
    std::vector<std::vector<int>> memo;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> x_size >> y_size; // these two values are not used
            std::cin >> x[0] >> y[0];
            std::cin >> n;

            x.resize(n + 1);
            y.resize(n + 1);
            dist.clear();
            dist.resize(n + 1, std::vector<int>(n + 1, 0));
            memo.clear();
            memo.resize(n + 1, std::vector<int>(1 << 11, -1));

            for (i = 1; i <= n; i++) {
                std::cin >> x[i] >> y[i];
            }

            for (i = 0; i <= n; i++) { // build distance table
                for (j = 0; j <= n; j++) {
                    dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]); // Manhattan distance
                }
            }

            std::cout << "The shortest path has length " << tsp(0, 1, n, dist, memo) << std::endl;
        }
    }

    return 0;
}
