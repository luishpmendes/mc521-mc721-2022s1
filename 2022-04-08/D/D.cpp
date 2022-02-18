#include <iostream>

int main() {
    unsigned t, W, H, x1, y1, x2, y2, w, h;
    double result;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;

            if (w + x2 > W + x1 && h + y2 > H + y1) {
                result = -1.0;
            } else {
                result = W;

                if (result < H) {
                    result = H;
                }

                if (w + x2 <= W + x1) {
                    if (w > x1 && x2 + w > W) {
                        if (w + W < x2 + w + x1) {
                            result = w - x1;
                        } else {
                            result = x2 + w - W;
                        }
                    } else {
                        result = 0.0;
                    }
                }

                if (h + y2 <= H + y1) {
                    if (h > y1 && y2 + h > H) {
                        if (h + H < y2 + h + y1) {
                            if (result + y1 > h) {
                                result = h - y1;
                            }
                        } else {
                            if (result + H > y2 + h) {
                                result = y2 + h - H;
                            }
                        }
                    } else {
                        result = 0.0;
                    }
                }
            }

            if (result < 0) {
                std::cout.precision(0);
                std::cout << result << std::endl;
            } else {
                std::cout.precision(9);
                std::cout << std::fixed << result << std::endl;
            }
        }
    }

    return 0;
}
