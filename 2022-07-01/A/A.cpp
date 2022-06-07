#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
    int n, plus, minus, a, b, c, d, e;
    std::string handle;
    std::vector<std::pair<int, std::string>> contestants;

    while (std::cin >> n) {
        contestants.resize(n);

        for (std::pair<int, std::string> & contestant : contestants) {
            std::cin >> handle >> plus >> minus >> a >> b >> c >> d >> e;
            contestant.first = 100 * plus - 50 * minus + a + b + c + d + e;
            contestant.second = handle;
        }

        std::sort(contestants.rbegin(), contestants.rend());

        std::cout << contestants.front().second << std::endl;
    }

    return 0;
}
