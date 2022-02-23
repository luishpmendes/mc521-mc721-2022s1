#include <iostream>

int main() {
    long long int t, hc, dc, hm, dm, k, w, a, nhc, ndc, i;
    bool result;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> hc >> dc
                     >> hm >> dm
                     >> k >> w >> a;
            
            result = false;

            for (i = 0; i <= k; i++) {
                nhc = hc + i * a;
                ndc = dc + (k - i) * w;

                if ((hm + ndc - 1) / ndc <= (nhc + dm - 1) / dm) {
                    result = true;
                    break;
                }
            }

            if (result) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }

    return 0;
}
