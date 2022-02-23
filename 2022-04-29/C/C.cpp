#include <iostream>
#include <vector>

void build (int l, int r, const std::vector<int> & a, std::vector<int> & d, int curD = 0) {
    if (l <= r) {
        int m = l;
        
        for (int i = l + 1; i <= r; i++) {
            if (a[m] < a[i]) {
                m = i;
            }
        }

        d[m] = curD;

        build(l, m - 1, a, d, curD + 1);
        build(m + 1, r, a, d, curD + 1);
    }
}

int main() {
    int t, n;
    std::vector<int> a, d;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;
            a.resize(n);
            d.resize(n);

            for (int & x : a) {
                std::cin >> x;
            }

            build(0, n - 1, a, d);

            for (const int & x : d) {
                std::cout << x << ' ';
            }

            std::cout << std::endl;
        }
    }

    return 0;
}
