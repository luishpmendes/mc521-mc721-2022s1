#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, prev, curr, i;
    std::vector<bool> v;

    while (std::cin >> n) {
        v.clear();
        v.resize(n - 1, false);

        if (n > 0) {
            std::cin >> curr;
        }

        for (i = 1; i < n; i++) {
            prev = curr;
            std::cin >> curr;

            if (prev < curr) {
                if (curr - prev - 1 >= 0 && curr - prev - 1 < n - 1) {
                    v[curr - prev - 1] = true;
                }
            } else {
                if (prev - curr - 1 >= 0 && prev - curr - 1 < n - 1) {
                    v[prev - curr - 1] = true;
                }
            }
        }

        if (std::all_of(v.begin(), v.end(), [](bool b) { return b; })) {
            std::cout << "Jolly" << std::endl;
        } else {
            std::cout << "Not jolly" << std::endl;
        }
    }

    return 0;
}
