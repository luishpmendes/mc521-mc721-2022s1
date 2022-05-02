#include <iostream>
#include <vector>

int main() {
    int t, n, i;
    std::vector<int> a;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;
            a.resize(n);

            for (int & x : a) {
                std::cin >> x;
            }

            for (i = n - 1; i >= 0; i--) {
                if (a[i] > 1) {
                    if (i > 0 && a[i - 1] < a[i] - 1) {
                        a[i - 1] = a[i] - 1;
                    }

                    a[i] = 1;
                }
            }
            
            for (i = 0; i < n; i++) {
                std::cout << a[i] << " ";
            }
            std::cout << std::endl;
        }
    }
    
    return 0;
}
