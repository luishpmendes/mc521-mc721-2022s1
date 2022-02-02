#include <iostream>

int main() {
    unsigned t, a, b, c, A, B, C, cA, cB, cC, i, result, answer;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> a >> b >> c;
            A = B = C = 0;
            answer = 1E9;

            for (cA = 1; cA <= 2 * a; ++cA) {
                for (cB = cA; cB <= 2 * b; cB += cA) {
                    for (i = 0; i < 2; ++i) {
                        cC = cB * (c / cB) + i * cB;

                        if (cA < a) {
                            result = a - cA;
                        } else {
                            result = cA - a;
                        }

                        if (cB < b) {
                            result += b - cB;
                        } else {
                            result += cB - b;
                        }

                        if (cC < c) {
                            result += c - cC;
                        } else {
                            result += cC - c;
                        }

                        if (answer > result) {
                            answer = result;
                            A = cA;
                            B = cB;
                            C = cC;
                        }
                    }
                }
            }

            std::cout << answer << std::endl
                      << A << ' ' << B << ' ' << C << std::endl;
        }
    }

    return 0;
}
