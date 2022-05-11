#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int t, n, k, i, j;
    std::vector<int> v;
    bool ans;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n >> k;
            v.resize(n);

            for (int & x : v) {
                std::cin >> x;
            }

            if (n == 1) {
                ans = (v.front() == k);
            } else {
                ans = false;
                std::sort(v.begin(), v.end());
                i = 0;
                j = 1;

                while (i < n && j < n && !ans) {
                    if (v[i] + k == v[j]) {
                        ans = true;
                    } else if (v[i] + k < v[j]) {
                        i++;
                    } else { // v[i] + k > v[j]
                        j++;
                    }
                }
            }

            if (ans) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }

    return 0;
}
