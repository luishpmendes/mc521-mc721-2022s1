#include <iostream>
#include <string>

int main() {
    unsigned t, n;
    std::string s;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n >> s;
            
            if (n == 1 || (n == 2 &&  s[0] != s[1])) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }
    
    return 0;
}
