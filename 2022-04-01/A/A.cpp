#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

int main() {
    unsigned t, n, i;
    std::vector<unsigned> p, q;
    std::string s;
    std::vector<std::tuple<char, unsigned, unsigned>> v;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;

            p.resize(n);
            q.resize(n);
            v.resize(n);

            for (i = 0; i < n; i++) {
                std::cin >> p[i];
            }

            std::cin >> s;

            for (i = 0; i < n; i++) {
                v[i] = std::make_tuple(s[i], p[i], i);
            }

            std::sort(v.begin(), v.end());

            for (i = 0; i < n; i++) {
                q[std::get<2>(v[i])] = i + 1;
            }

            for (i = 0; i < n - 1; i++) {
                std::cout << q[i] << ' ';
            }

            std::cout << q[i] << std::endl;
        }
    }

    return 0;
}
