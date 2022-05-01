#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    unsigned t, n;
    std::string s;
    
    while (std::cin >> t) {
        while (t--) {
            std::cin >> n >> s;

            if (n >= 4 && 
              ((s[n - 4] == '2' && s[n - 3] == '0' && s[n - 2] == '2' && s[n - 1] == '0') ||
              (s[0] == '2' && s[n - 3] == '0' && s[n - 2] == '2' && s[n - 1] == '0') ||
              (s[0] == '2' && s[1] == '0' && s[n - 2] == '2' && s[n - 1] == '0') ||
              (s[0] == '2' && s[1] == '0' && s[2] == '2' && s[n - 1] == '0') ||
              (s[0] == '2' && s[1] == '0' && s[2] == '2' && s[3] == '0'))) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            } 
        }
    }
        
    return 0;
}
