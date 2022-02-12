#include <iostream>
#include <string>

int main() {
    unsigned long long n, left_numerator,    left_denominator,
                          mediant_numerator, mediant_denominator,
                          right_numerator,   right_denominator,
                          temp_numerator,    temp_denominator;
    std::string path;

    while (std::cin >> n) {
        while (n--) {
            std::cin >> path;

            left_numerator      = 0;
            left_denominator    = 1;
            mediant_numerator   = 1;
            mediant_denominator = 1;
            right_numerator     = 1;
            right_denominator   = 0;

            for (const char & move : path) {
                if (move == 'L') {
                    temp_numerator      = mediant_numerator;
                    temp_denominator    = mediant_denominator;
                    mediant_numerator   = left_numerator   + mediant_numerator;
                    mediant_denominator = left_denominator + mediant_denominator;
                    right_numerator     = temp_numerator;
                    right_denominator   = temp_denominator;
                } else { // move == 'R'
                    temp_numerator      = mediant_numerator;
                    temp_denominator    = mediant_denominator;
                    mediant_numerator   = right_numerator   + mediant_numerator;
                    mediant_denominator = right_denominator + mediant_denominator;
                    left_numerator      = temp_numerator;
                    left_denominator    = temp_denominator;
                }
            }

            std::cout << mediant_numerator << '/' << mediant_denominator << std::endl;
        }
    }

    return 0;
}
