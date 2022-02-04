#include <iostream>
#include <limits>
#include <vector>

int main() {
    unsigned N, B, H, W, i, j, result;
    std::vector<unsigned> p;
    std::vector<std::vector<unsigned>> a;
    bool stay_home, enough_beds;

    while (std::cin >> N >> B >> H >> W) {
        p.clear();
        a.clear();
        p.resize(H);
        a.resize(H, std::vector<unsigned>(W));

        for (i = 0; i < H; i++) {
            std::cin >> p[i];

            for (j = 0; j < W; j++) {
                std::cin >> a[i][j];
            }
        }

        result = std::numeric_limits<unsigned>::max();
        stay_home = true;

        for (i = 0; i < H; i++) {
            if (N * p[i] <= B) {
                enough_beds = false;

                for (j = 0; j < W; j++) {
                    if (a[i][j] > N) {
                        enough_beds = true;
                        break;
                    }
                }

                if (enough_beds) {
                    stay_home = false;
                    result = std::min(result, N * p[i]);
                }
            }
        }

        if (stay_home) {
            std::cout << "stay home" << std::endl;
        } else {
            std::cout << result << std::endl;
        }
    }

    return 0;
}
