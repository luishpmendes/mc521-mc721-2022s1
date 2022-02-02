#include <iostream>

int main() {
    int n, m, a, b, result;

    while (std::cin >> n >> m >> a >> b) {
        if (m * a <= b) {
            result = n  * a;
        } else if ((n % m) * a < b) {
            result = (n / m) * b + (n % m) * a;
        } else {
            result = (n / m) * b + b;
        }

        std::cout << result << std::endl;
    }

    return 0;
}
