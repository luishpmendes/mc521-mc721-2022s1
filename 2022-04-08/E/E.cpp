#include <iostream>
#include <string>

int main() {
    unsigned n, result;
    std::string s;

    while (std::cin >> n) {
        std::cin >> s;
        result = 0;
        
        for (const char & c : s) {
            if (c == '8') {
                result++;
            }
        }

        if (result > n / 11) {
            result = n / 11;
        }

        std::cout << result << std::endl;
    }
        
    return 0;
}
