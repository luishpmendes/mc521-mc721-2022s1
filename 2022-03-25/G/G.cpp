#include <algorithm>
#include <iostream>
#include <string>

int main() {
    unsigned RFP, n, p, r, i, j, max_r;
    double d, lowest_price;
    std::string requirement, proposal, best_proposal;

    RFP = 0;

    while (std::cin >> n >> p && n > 0 && p > 0) {
        std::cin.ignore();

        RFP++;

        for (i = 0; i < n; i++) {
            std::getline(std::cin, requirement);
        }

        max_r = 0;

        for (i = 0; i < p; i++) {
            std::getline(std::cin, proposal);
            std::cin >> d >> r;
            std::cin.ignore();

            for (j = 0; j < r; j++) {
                std::getline(std::cin, requirement);

            }

            if (max_r < r || (max_r == r && lowest_price > d)) {
                max_r = r;
                lowest_price = d;
                best_proposal = proposal;
            }
        }

        if (RFP > 1) {
            std::cout << std::endl;
        }

        std::cout << "RFP #" << RFP << std::endl;
        std::cout << best_proposal << std::endl;
    }

    return 0;
}
