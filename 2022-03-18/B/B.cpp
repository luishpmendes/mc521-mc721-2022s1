#include <cctype>
#include <iostream>
#include <string>

int main() {
    std::string s, t;
    int result;
    unsigned i;

    while (std::cin >> s >> t) {
        result = 0;

        for (i = 0; i < s.size(); i++) {
            if (tolower(s[i]) < tolower(t[i])) {
                result = -1;
                break;
            }
            if (tolower(s[i]) > tolower(t[i])) {
                result = 1;
                break;
            }
        }

        std::cout << result << std::endl;
    }

    return 0;
}
