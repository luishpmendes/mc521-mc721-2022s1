#include <iostream>

int main() {
    unsigned r, g, b, ans;

    while (std::cin >> r >> g >> b) {
        ans = 30 + 3*((r+1)/2-1);

        if (ans < 31 + 3*((g+1)/2-1)) {
            ans = 31 + 3*((g+1)/2-1);
        }

        if (ans < 32 + 3*((b+1)/2-1)) {
            ans = 32 + 3*((b+1)/2-1);
        }
        
        std::cout << ans << std::endl;
    }

    return 0;
}
