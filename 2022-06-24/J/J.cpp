#include <iostream>
#include <vector>

int main() {
    unsigned n, a, cntAdd, cntMul, ans;

    while (std::cin >> n) {
        while (n--) {
            std::cin >> a;
            
            ans = 32;

            for (cntAdd = 0; cntAdd <= 15; cntAdd++) {
                for (cntMul = 0; cntMul <= 15; cntMul++) {
                    if (((a + cntAdd) << cntMul) % 32768 == 0) {
                        if (ans > cntAdd + cntMul) {
                            ans = cntAdd + cntMul;
                        }
                    }
                }
            }

            std::cout << ans;

            if (n) {
                std::cout << " ";
            } else {
                std::cout << std::endl;
            }
        }
    }

    return 0;
}
