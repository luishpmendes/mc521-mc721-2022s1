#include <iostream>

int main() {
    unsigned n, ax, ay, bx, by, cx, cy;

    while (std::cin >> n >> ax >> ay >> bx >> by >> cx >> cy) {
        if ((ax < bx && ax > cx) ||
            (ax > bx && ax < cx) ||
            (ay < by && ay > cy) ||
            (ay > by && ay < cy)) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "YES" << std::endl;
        }
    }

    return 0;
}
