#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
    int x;
    unsigned c, p, i, j, k;
    std::set<unsigned> s;
    std::vector<unsigned> v;

    for (i = 1; i <= 20; i++) {
        for (j = 1; j <= 3; j++) {
            s.insert(i*j);
        }
    }
    s.insert(0);
    s.insert(50);

    v = std::vector<unsigned>(s.begin(), s.end());

    while (std::cin >> x && x > 0) {
        c = p = 0;

        for (i = 0; i < v.size(); i++) {
            for (j = i; j < v.size(); j++) {
                for (k = j; k < v.size(); k++) {
                    if (v[i] + v[j] + v[k] == unsigned(x)) {
                        c++;
                    }
                }
            }
        }

        for (i = 0; i < v.size(); i++) {
            for (j = 0; j < v.size(); j++) {
                for (k = 0; k < v.size(); k++) {
                    if (v[i] + v[j] + v[k] == unsigned(x)) {
                        p++;
                    }
                }
            }
        }

        if (c) {
            std::cout << "NUMBER OF COMBINATIONS THAT SCORES " << x << " IS " << c << "." << std::endl;
            std::cout << "NUMBER OF PERMUTATIONS THAT SCORES " << x << " IS " << p << "." << std::endl;
        } else {
            std::cout << "THE SCORE OF " << x << " CANNOT BE MADE WITH THREE DARTS." << std::endl;
        }

        std::cout << "**********************************************************************" << std::endl;
    }

    std::cout << "END OF OUTPUT" << std::endl;

    return 0;
}
