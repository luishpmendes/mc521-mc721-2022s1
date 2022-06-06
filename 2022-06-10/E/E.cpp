#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int main() {
    int p1, p2, ans;
    bool found;
    std::pair<int, int> u, v;
    std::vector<std::pair<int, int>> perimeter1, perimeter2;
    std::pair<int, int> size;
    std::vector<std::vector<int>> grid, distance;
    std::queue<std::pair<int, int>> q;
    std::vector<std::pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (std::cin >> p1 && p1) {
        perimeter1.resize(p1);
        size = std::make_pair(0, 0);
        q = std::queue<std::pair<int, int>>();
        found = false;

        for (std::pair<int, int> & x : perimeter1) {
            std::cin >> x.first >> x.second;

            if (size.first < x.first) {
                size.first = x.first;
            }

            if (size.second < x.second) {
                size.second = x.second;
            }
        }

        std::cin >> p2;

        perimeter2.resize(p2);

        for (std::pair<int, int> & y : perimeter2) {
            std::cin >> y.first >> y.second;

            if (size.first < y.first) {
                size.first = y.first;
            }

            if (size.second < y.second) {
                size.second = y.second;
            }
        }

        grid.resize(size.first + 1, std::vector<int>(size.second + 1, 0));
        grid.assign(size.first + 1, std::vector<int>(size.second + 1, 0));
        distance.resize(size.first + 1, std::vector<int>(size.second + 1, -1));
        distance.assign(size.first + 1, std::vector<int>(size.second + 1, -1));
        
        for (std::pair<int, int> & x : perimeter1) {
            grid[x.first][x.second] = 1;
            q.push(x);
            distance[x.first][x.second] = 0;
        }

        for (std::pair<int, int> & y : perimeter2) {
            grid[y.first][y.second] = 2;
        }

        while (!q.empty() && !found) {
            u = q.front();
            q.pop();

            if (grid[u.first][u.second] == 2) {
                ans = distance[u.first][u.second];
                found = true;
            } else {
                for (std::pair<int, int> & move : moves) {
                    v = std::make_pair(u.first + move.first, u.second + move.second);

                    if (v.first >= 0 &&
                        v.first < size.first &&
                        v.second >= 0 &&
                        v.second < size.second &&
                        distance[v.first][v.second] < 0) {
                        distance[v.first][v.second] = distance[u.first][u.second] + 1;
                        q.push(v);
                    }
                }
            }
        }

        std::cout << ans << std::endl;
    }

    return 0;
}
