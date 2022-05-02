#include <iostream>

int main() {
    unsigned t, n, m, k;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n >> m >> k;
            
            if (k + 1 == n * m){
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }
    
    return 0;
}
