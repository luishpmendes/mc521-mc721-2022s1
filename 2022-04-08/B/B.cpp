#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    unsigned f, r, i, j;
    std::vector<unsigned> front, rear;
    std::vector<double> d;
    double result;

    std::cout << std::setprecision(2) << std::fixed;

    while (std::cin >> f >> r && f && r) {
        front.resize(f);
        rear.resize(r);
        d.resize(f * r);

        for (i = 0; i < f; i++) {
            std::cin >> front[i];
        }

        for (j = 0; j < r; j++) {
            std::cin >> rear[j];
        }

        for (i = 0; i < f; i++) {
            for (j = 0; j < r; j++) {
                d[i * r + j] = ((double) rear[j]) / ((double) front[i]);
            }
        }

        std::sort(d.begin(), d.end());

        result = d[1] / d[0];

        for (i = 2; i < f * r; i++) {
            result = std::max(result, d[i] / d[i - 1]);
        }

        std::cout << result << std::endl;
    }

    return 0;
}
