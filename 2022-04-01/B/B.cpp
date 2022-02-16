#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int main() {
    unsigned q, t, m, i, j;
    std::vector<std::pair<unsigned, bool>> v;
    std::priority_queue<std::pair<unsigned, int>> heap;
    
    while (std::cin >> q) {
        v.resize(q);
        heap = std::priority_queue<std::pair<unsigned, int>>();
        i = j = 1;

        while (q--) {
            std::cin >> t;

            if (t == 1) {
                std::cin >> m;
                v[i] = std::make_pair(m, false);
                heap.push(std::make_pair(m, -i));
                i++;
            } else if (t == 2) {
                while (v[j].second) {
                    j++;
                }

                v[j].second = true;
                std::cout << j << ' ';
                j++;
            } else { // t == 3
                while (v[-heap.top().second].second) {
                    heap.pop();
                }

                v[-heap.top().second].second = true;
                std::cout << -heap.top().second << ' ';
            }
        }

        std::cout << std::endl;
    }

    return 0;
}
