#include <iostream>
#include <map>
#include <vector>

int main() {
    unsigned long long t, n, s, ans, i;
    std::vector<unsigned long long> a;
    std::map<unsigned long long, unsigned long long> num_occurences;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;
            a.resize(n);
            num_occurences.clear();
            s = 0;
            ans = 0;

            for (i = 0; i < n; i++) {
                std::cin >> a[i];

                s += a[i];

                if (num_occurences.find(a[i]) == num_occurences.end()) {
                    num_occurences[a[i]] = 0;
                }

                num_occurences[a[i]]++;
            }

            if ((2 * s) % n == 0) {
                for (i = 0; i < n; i++) {
                    if (a[i] * n != s) {
                        ans += num_occurences[((2 * s) / n) - a[i]];
                    } else {
                        ans += num_occurences[a[i]] - 1;
                    }
                }

                ans /= 2;
            }

            std::cout << ans << std::endl;
        }
    }

    return 0;
}
