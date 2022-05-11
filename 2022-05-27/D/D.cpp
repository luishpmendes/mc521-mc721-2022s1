#include <iostream>
#include <string>

int main() {
    unsigned t, n, c, l, r;
    std::string s;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n >> s;
            c = l = 0;

            while (l + 1 < n) {
                if (s[l] == '(' || (s[l] == ')' && s[l + 1] == ')')) {
                    l += 2;
                } else {
                    r = l + 1;

                    while (r < n && s[r] != ')') {
                        r++;
                    }

                    if (r == n) {
                        break;
                    }

                    l = r + 1;
                }

                c++;
            }

            std::cout << c << ' ' << n - l << std::endl;
        }
    }

    return 0;
}
