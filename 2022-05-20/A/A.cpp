#include <iostream>

int main() {
    long long n, ans;
    
    while (std::cin >> n) {
        if (n & 1) {
            ans = 0;
        } else {
            ans = (1 << (n >> 1));
        }

        std::cout << ans << std::endl;
    }

    return 0;
}
