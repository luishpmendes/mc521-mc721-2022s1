#include <iostream>

int main() {
    unsigned t, n, prev_a, curr_a;
    
    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;

            if (n < 20) {
                std::cout << "YES" << std::endl;

                curr_a = 1;

                while (n--) {
                    std::cout << curr_a;

                    prev_a = curr_a;
                    curr_a = 3 * prev_a;

                    if (n) {
                        std::cout << " ";
                    }
                }

                std::cout << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }

    return 0;
}
