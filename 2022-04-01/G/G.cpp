#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <utility>
#include <vector>

int main() {
    unsigned t, n, l, r, i, min_len;
    std::string s;
    std::vector<std::pair<std::pair<int, int>, unsigned>> v;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n >> s;
            v.resize(n + 1);
            v[0] = {{0, 0}, 0};

            for (i = 0; i < n; i++) {
                if (s[i] == 'L') {
                    v[i + 1].first.first = v[i].first.first + 1;
                    v[i + 1].first.second = v[i].first.second;
                } else if (s[i] == 'R') {
                    v[i + 1].first.first = v[i].first.first - 1;
                    v[i + 1].first.second = v[i].first.second;
                } else if (s[i] == 'U') {
                    v[i + 1].first.first = v[i].first.first;
                    v[i + 1].first.second = v[i].first.second + 1;
                } else { // s[i] == 'D'
                    v[i + 1].first.first = v[i].first.first;
                    v[i + 1].first.second = v[i].first.second - 1;
                }
                v[i + 1].second = i + 1;
            }

            std::sort(v.begin(), v.end());

            l = r = 0;
            min_len = std::numeric_limits<unsigned>::max();

            for (i = 0; i < n; i++) {
                if (v[i].first.first == v[i + 1].first.first && v[i].first.second == v[i + 1].first.second) {
                    if (min_len > v[i + 1].second - v[i].second) {
                        min_len = v[i + 1].second - v[i].second;
                        l = v[i].second;
                        r = v[i + 1].second;
                    }
                }
            }

            if (min_len < std::numeric_limits<unsigned>::max()) {
                std::cout << l + 1 << ' ' << r << std::endl;
            } else {
                std::cout << -1 << std::endl;
            }
        }
    }

    return 0;
}
