#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s;
    std::vector<unsigned> v;
    unsigned i, result;

    while (std::cin >> s) {
        while (s.back() < 'A' || s.back() > 'Z') {
            s.pop_back();
        }

        v.resize(s.size());

        if (s.front() == 'Q') {
            v.front() = 1;
        } else {
            v.front() = 0;
        }

        for (i = 1; i < s.size(); i++) {
            if (s[i] == 'Q') {
                v[i] = v[i - 1] + 1;
            } else {
                v[i] = v[i - 1];
            }
        }

        result = 0;

        for (i = 1; i < s.size() - 1; i++) {
            if (s[i] == 'A') {
                result += v[i - 1] * (v.back() - v[i]);
            }
        }

        std::cout << result << std::endl;
    }

    return 0;
}
