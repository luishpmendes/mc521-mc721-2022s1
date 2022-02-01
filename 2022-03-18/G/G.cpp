#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::string s, term;
    std::vector<unsigned> terms;
    std::stringstream ss;
    unsigned i;

    while (std::cin >> s) {
        terms.clear();
        ss = std::stringstream(s);

        while (getline(ss, term, '+')) {
            terms.push_back(std::stoi(term));
        }

        std::sort(terms.begin(), terms.end());

        for (i = 0; i < terms.size() - 1; ++i) {
            std::cout << terms[i];

            if (i < terms.size() - 1) {
                std::cout << '+';
            }
        }

        std::cout << terms[i] << std::endl;
    }

    return 0;
}
