#include <iostream>
#include <limits>
#include <vector>

int main() {
    int n, r, q, x, v, i;
    std::vector<int> busyness, distance;
    std::vector<std::pair<std::pair<int, int>, int>> edges;
    x = 0;

    while (std::cin >> n) {
        x++;
        busyness.resize(n);
        distance.resize(n, std::numeric_limits<int>::max() >> 2);
        distance.assign(n, std::numeric_limits<int>::max() >> 2);

        for (int & x : busyness) {
            std::cin >> x;
        }

        std::cin >> r;

        edges.resize(r, std::make_pair(std::make_pair(0, 0), 0));

        for (std::pair<std::pair<int, int>, int> & edge : edges) {
            std::cin >> edge.first.first >> edge.first.second;
            edge.first.first--;
            edge.first.second--;
            edge.second = (busyness[edge.first.second] - busyness[edge.first.first])
                        * (busyness[edge.first.second] - busyness[edge.first.first])
                        * (busyness[edge.first.second] - busyness[edge.first.first]);
        }

        // Bellman-Ford
        distance[0] = 0;
        for (i = 0; i < n - 1; i++) { // relax all E edges V-1 times
            for (const std::pair<std::pair<int, int>, int> & edge : edges) { // this loops = O(E), overall O(VE)
                if (distance[edge.first.first] != (std::numeric_limits<int>::max() >> 2) &&
                    distance[edge.first.second] > distance[edge.first.first] + edge.second) { // relax
                    distance[edge.first.second] = distance[edge.first.first] + edge.second;
                }
            }
        }

        // after running the O(VE) Bellman Ford’s algorithm above
        for (const std::pair<std::pair<int, int>, int> & edge : edges) { // one more pass to check
            if (distance[edge.first.first] != (std::numeric_limits<int>::max() >> 2) &&
                distance[edge.first.second] > distance[edge.first.first] + edge.second) { // if this is still possible
                distance[edge.first.second] = -(std::numeric_limits<int>::max() >> 2); // then negative cycle exists!
            }
        }

        std::cin >> q;

        std::cout << "Set #" << x << std::endl;

        while (q--) {
            std::cin >> v;
            v--;

            if (distance[v] < 3 || distance[v] == (std::numeric_limits<int>::max() >> 2)) {
                std::cout << "?" << std::endl;
            } else {
                std::cout << distance[v] << std::endl;
            }
        }
    }

    return 0;
}
