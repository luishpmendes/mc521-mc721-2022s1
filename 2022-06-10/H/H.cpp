#include <iostream>
#include <vector>

int main() {
    unsigned n, i, num_negatives;
    std::vector<int> a;
    std::vector<unsigned> b;

    while (std::cin >> n) {
        num_negatives = 0;
        a.resize(n);
        b.clear();
        b.push_back(0);

        for (i = 0; i < n; i++) {
            std::cin >> a[i];

            if (a[i] < 0) {
                num_negatives++;
            }

            if (num_negatives < 3) {
                b.back()++;
            } else {
                b.push_back(1);
                num_negatives = 1;
            }
        }

        std::cout << b.size() << std::endl;

        for (i = 0; i < b.size() - 1; i++) {
            std::cout << b[i] << ' ';
        }

        std::cout << b.back() << std::endl;
    }

    return 0;
}
