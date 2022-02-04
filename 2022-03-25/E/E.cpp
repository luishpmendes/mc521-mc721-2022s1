#include <iostream>

int main() {
    unsigned K;
    int N, M, X, Y;

    while (std::cin >> K && K > 0) {
        std::cin >> N >> M;

        while (K--) {
            std::cin >> X >> Y;
            
            if (X < N && Y > M) {
                std::cout << "NO" << std::endl;
            } else if (X > N && Y > M) {
                std::cout << "NE" << std::endl;
            } else if (X > N && Y < M) {
                std::cout << "SE" << std::endl;
            } else if (X < N && Y < M) {
                std::cout << "SO" << std::endl;
            } else {
                std::cout << "divisa" << std::endl;
            }
        }
    }

    return 0;
}
