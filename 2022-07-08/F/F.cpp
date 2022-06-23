#include <iostream>
#include <vector>

int main() {
    unsigned t, n, k, i, j, princess_result, prince_result;
    std::vector<std::vector<unsigned>> g;
    std::vector<bool> princess_married, prince_married;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;

            g.resize(n);
            princess_married.resize(n, false);
            princess_married.assign(n, false);
            prince_married.resize(n, false);
            prince_married.assign(n, false);
            princess_result = prince_result = n;

            for (i = 0; i < n; i++) {
                std::cin >> k;
                g[i].resize(k);
                for (j = 0; j < k; j++) {
                    std::cin >> g[i][j];
                    g[i][j]--;
                }
            }

            for (i = 0; i < n; i++) {
                for (j = 0; j < g[i].size() && !princess_married[i]; j++) {
                    if (!prince_married[g[i][j]]) {
                        princess_married[i] = true;
                        prince_married[g[i][j]] = true;
                    }
                }
            }

            for (i = 0; i < n && (princess_result >= n || prince_result >= n); i++) {
                if (!princess_married[i]) {
                    for (j = 0; j < n && !princess_married[i]; j++) {
                        if (!prince_married[j]) {
                            princess_result = i;
                            prince_result = j;
                            princess_married[i] = true;
                        }
                    }
                }
            }

            if (princess_result >= n || prince_result >= n) {
                std::cout << "OPTIMAL" << std::endl;
            } else {
                std::cout << "IMPROVE" << std::endl;
                std::cout << princess_result + 1 << " " << prince_result + 1 << std::endl;
            }
        }
    }

    return 0;
}
