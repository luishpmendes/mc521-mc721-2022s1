#include <iostream>

int main() {
    unsigned n, x, i, num_even, num_odd, last_even, last_odd;

    while (std::cin >> n) {
        num_even = num_odd = last_even = last_odd = 0;

        for (i = 0; i < n; ++i) {
            std::cin >> x;

            if ((x & 1) == 0) {
                num_even++;
                last_even = i + 1;
            } else {
                num_odd++;
                last_odd = i + 1;
            }
        }

        if (num_even == 1) {
            std::cout << last_even << std::endl;
        } else { // num_odd == 1
            std::cout << last_odd << std::endl;
        }
    }
    
    return 0;
}
