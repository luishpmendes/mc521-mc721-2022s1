#include <iostream>

int main() {
    long long t, n, B, x, y, prev_a, curr_a, sum;
    
    while (std::cin >> t) {
        while (t--) {
            std::cin >> n >> B >> x >> y;

            prev_a = sum = 0;

            while (n--) {
                if (prev_a + x <= B) {
                    curr_a = prev_a + x;
                } else {
                    curr_a = prev_a - y;
                }

                sum += curr_a;
                prev_a = curr_a;
            }

            std::cout << sum << std::endl;
        }
    }

    return 0;
}
