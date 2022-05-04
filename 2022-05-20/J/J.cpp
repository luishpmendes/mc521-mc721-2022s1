#include <iostream>
#include <string>
#include <vector>

int main() {
    unsigned k, a, b, i, sum;
    std::string s;
    std::vector<unsigned> v;
    
    while (std::cin >> k >> a >> b >> s) {
        if (s.size() < k * a || s.size() > k * b) {
            std::cout << "No solution" << std::endl;
        } else {
            v.clear();
            v.resize(k, a);
            v.back() = s.size() - (k - 1) * a;

            while (v.back() > b) {
                for (i = 0; i < k - 1 && v.back() > b; i++) {
                    v.back()--;
                    v[i]++;
                }
            }

            sum = 0;

            for (i = 0; i < k; i++) {
                std::cout << s.substr(sum, v[i]) << std::endl;
                sum += v[i];
            }
        }
    }

    return 0;
}
