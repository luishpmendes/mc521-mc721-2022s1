#include <iostream>
#include <string>
#include <vector>

int main() {
    unsigned t, i, j;
    std::string n;
    char c;
    std::vector<bool> v (999, false);
    bool flag;

    for (i = 7; i < 999; i += 7) {
        v[i] = true;
    }

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;
            flag = v[std::stoi(n)];

            for (i = 0; i < n.size() && !flag; i++) {
                c = n[n.size() - 1 - i];

                for (j = 0; j <= 9 && !flag; j++) {
                    n[n.size() - 1 - i] = '0' + j;

                    if (v[std::stoi(n)]) {
                        flag = true;
                        break;
                    }
                }

                if (flag) {
                    break;
                }

                n[n.size() - 1 - i] = c;
            }

            std::cout << n << std::endl;
        }
    }

    return 0;
}
