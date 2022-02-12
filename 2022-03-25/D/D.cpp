#include <iostream>
#include <map>
#include <set>
#include <vector>

int main() {
    unsigned n, i, c, max_frequency, result;
    std::vector<std::set<unsigned>> frosh;
    std::map<std::set<unsigned>, unsigned> frequency;

    while (std::cin >> n && n) {
        frosh.clear();
        frosh.resize(n);
        frequency.clear();
        max_frequency = 0;

        for (std::set<unsigned> & courses : frosh) {
            for (i = 0; i < 5; i++) {
                std::cin >> c;
                courses.insert(c);
            }

            if (frequency.find(courses) == frequency.end()) {
                frequency[courses] = 1;
            } else {
                frequency[courses]++;
            }

            if (max_frequency < frequency[courses]) {
                max_frequency = frequency[courses];
            }
        }

        result = 0;

        for (std::set<unsigned> & courses : frosh) {
            if (frequency[courses] == max_frequency) {
                result++;
            }
        }

        std::cout << result << std::endl;
    }

    return 0;
}
