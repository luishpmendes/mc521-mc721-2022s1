#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    unsigned t = 0, b, s, y, min, i;
    std::vector<unsigned> bachelor;

    while (std::cin >> b >> s && (b || s)) {
        bachelor.resize(b);

        for (unsigned & x : bachelor) {
            std::cin >> x;
        }

        for (i = 0; i < s; i++) {
            std::cin >> y;
        }

        std::cout << "Case " << ++t << ": ";

        if (b <= s) {
            std::cout << 0;
        } else { // b > s
            min = bachelor[0];

            for (i = 1; i < b; i++) {
                if (min > bachelor[i]) {
                    min = bachelor[i];
                }
            }

            std::cout << b - s << ' ' << min;
        }
        std::cout << std::endl;
    }

    return 0;
}
