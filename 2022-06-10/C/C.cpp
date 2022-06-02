#include <iostream>
#include <limits>
#include <list>
#include <queue>
#include <string>
#include <vector>

int main() {
    unsigned n, k, i;
    std::string left, right;
    std::vector<std::list<unsigned>> adj;
    std::vector<unsigned> d;
    std::queue<unsigned> q;

    while (std::cin >> n >> k >> left >> right) {
        adj.resize(2 * n + 1, std::list<unsigned>());
        adj.assign(2 * n + 1, std::list<unsigned>());
        d.resize(2 * n + 1, std::numeric_limits<unsigned>::max() >> 2);
        d.assign(2 * n + 1, std::numeric_limits<unsigned>::max() >> 2);
        q = std::queue<unsigned>();

        for (i = 0; i < n - 1; i++) {
            if (left[i] == '-') {
                if (left[i + 1] == '-') {
                    adj[i].push_back(i + 1);
                    adj[i + 1].push_back(i);
                }

                if (i + k < n) {
                    if (right[i + k] == '-') {
                        adj[i].push_back(n + i + k);
                        adj[n + i + k].push_back(i);
                    }
                } else { // i + k >= n
                    adj[i].push_back(2 * n);
                    adj[2 * n].push_back(i);
                }
            }

            if (right[i] == '-') {
                if (right[i + 1] == '-') {
                    adj[n + i].push_back(n + i + 1);
                    adj[n + i + 1].push_back(n + i);
                }

                if (i + k < n) {
                    if (left[i + k] == '-') {
                        adj[n + i].push_back(i + k);
                        adj[i + k].push_back(n + i);
                    }
                } else { // i + k >= n
                    adj[n + i].push_back(2 * n);
                    adj[2 * n].push_back(n + i);
                }
            }
        }

        if (left[n - 1] == '-') {
            adj[n - 1].push_back(2 * n);
            adj[2 * n].push_back(n - 1);
        }

        if (right[n - 1] == '-') {
            adj[2 * n - 1].push_back(2 * n);
            adj[2 * n].push_back(2 * n - 1);
        }

        d[0] = 0;
        q.push(0);

        while (!q.empty()) {
            i = q.front();
            q.pop();

            for (const unsigned & j : adj[i]) {
                if (d[j] == std::numeric_limits<unsigned>::max() >> 2) {
                    if ((j < n && j >= d[i] + 1) || (j >= n && j - n >= d[i] + 1)) {
                        d[j] = d[i] + 1;
                        q.push(j);
                    }
                }
            }
        }

        if (d[2 * n] < std::numeric_limits<unsigned>::max() >> 2) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
