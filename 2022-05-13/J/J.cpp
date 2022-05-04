#include <iostream>
#include <string>

int main() {
    int q, i, j, k, size;
    std::string s, t;
    bool result;

    while (std::cin >> q) {
        while (q--) {
            std::cin >> s >> t;
            result = false;

            for (i = 0; i < (int) s.size() && !result; i++) {
                if (s[i] == t[0]) {
                    for (j = i; j < (int) s.size() && !result; j++) {
                        k = i;
                        size = 0;

                        while (size < (int) t.size() && k < j && s[k] == t[size]) {
                            size++;
                            k++;
                        }

                        while (size < (int) t.size() && k >= 0 && s[k] == t[size]) {
                            size++;
                            k--;
                        }

                        if (size == (int) t.size()) {
                            result = true;
                        }
                    }
                }
            }

            std::cout << (result ? "YES" : "NO") << std::endl;
        }
    }
    
    return 0;
}
