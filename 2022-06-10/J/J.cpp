#include <iostream>
#include <string>

int main() {
    unsigned n, k;
    std::string s;

    while (std::cin >> n >> k >> s) {
        k--;
        if (k <= n - k - 1) {
            while (k > 0) {
                std::cout << "LEFT" << std::endl;
                k--;
            }

            while (k < n - 1) {
                std::cout << "PRINT " << s[k] << std::endl;
                std::cout << "RIGHT" << std::endl;
                k++;
            }

            std::cout << "PRINT " << s[k] << std::endl;
        } else { // k > n - k - 1
            while (k < n - 1) {
                std::cout << "RIGHT" << std::endl;
                k++;
            }

            while (k > 0) {
                std::cout << "PRINT " << s[k] << std::endl;
                std::cout << "LEFT" << std::endl;
                k--;
            }

            std::cout << "PRINT " << s[k] << std::endl;
        }
    }

    return 0;
}
