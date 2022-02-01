#include <iostream>

int main() {
    unsigned n, i;
    int x, y, z, sum_x, sum_y, sum_z;

    while (std::cin >> n) {
        sum_x = sum_y = sum_z = 0;
        for (i = 0; i < n; ++i) {
            std::cin >> x >> y >> z;
            sum_x += x;
            sum_y += y;
            sum_z += z;
        }
        
        if (sum_x == 0 && sum_y == 0 && sum_z == 0) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
