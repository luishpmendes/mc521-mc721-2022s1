#include <iostream>
#include <string>

int main() {
    unsigned n, t, i;
    std::string s, r;

    while (std::cin >> n >> t >> s) {
        r = s;

        while (t--) {
            for (i = 0; i < n - 1; i++) {
                if (s[i] == 'B' && s[i + 1] == 'G') {
                    r[i] = 'G';
                    r[i + 1] = 'B';
                }
            }

            s = r;
        }

        std::cout << s << std::endl;
    }

    return 0;
}
