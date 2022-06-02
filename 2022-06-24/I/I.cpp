#include <iostream>
#include <string>
#include <vector>

int main() {
    unsigned n, i, j;
    std::string s, t;
    std::vector<unsigned> count_s ('Z' - 'A' + 1, 0), count_t ('Z' - 'A' + 1, 0);
    bool ans;

    while (std::cin >> n) {
        while (n--) {
            std::cin >> s >> t;

            count_s.assign('Z'-'A'+1, 0);
            count_t.assign('Z'-'A'+1, 0);
            ans = true;

            for (const char & c : s) {
                count_s[c-'A']++;
            }

            for (const char & c : t) {
                count_t[c-'A']++;
            }

            for (i = 0; i < 'Z' - 'A' + 1 && ans; i++) {
                if (count_s[i] < count_t[i]) {
                    ans = false;
                }
            }

            if (ans) {
                for (i = 0; i < 'Z' - 'A' + 1; i++) {
                    for (j = count_t[i]; j < count_s[i]; j++) {
                        s.replace(s.find(i + 'A'), 1, "");
                    }
                }

                if (s.compare(t) != 0) {
                    ans = false;
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
