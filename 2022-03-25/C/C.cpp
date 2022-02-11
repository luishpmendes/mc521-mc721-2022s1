#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

int main() {
    unsigned c, n, t, m, i, arrival, time;
    std::string bank;
    std::vector<std::pair<unsigned, unsigned>> cars;
    std::queue<std::pair<unsigned, unsigned> *> left, right, ferry;

    while (std::cin >> c) {
        while (c--) {
            std::cin >> n >> t >> m;

            left = 
            right = 
            ferry = std::queue<std::pair<unsigned, unsigned> *>();
            cars.clear();
            cars.resize(m);

            for (i = 0; i < m; i++) {
                std::cin >> arrival >> bank;

                cars[i] = std::make_pair(arrival, 0);

                if (bank.compare("left") == 0) {
                    left.push(&(cars[i]));
                } else { // bank.compare("right") == 0
                    right.push(&(cars[i]));
                }
            }

            time = 0;
            bank = "left";

            while (!left.empty() || !right.empty()) {
                while (!ferry.empty()) {
                    ferry.front()->second = time;
                    ferry.pop();
                }

                if (bank.compare("left") == 0) {
                    while (!left.empty() && left.front()->first <= time && 
                           ferry.size() < n) {
                        ferry.push(left.front());
                        left.pop();
                    }
                } else { // bank.compare("right") == 0
                    while (!right.empty() && right.front()->first <= time && 
                           ferry.size() < n) {
                        ferry.push(right.front());
                        right.pop();
                    }
                }

                if (bank.compare("left") == 0) {
                    if (!ferry.empty()) {
                        time += t;
                        bank = "right";
                    } else if ((left.empty() && !right.empty()) || 
                               (!left.empty() && !right.empty() && 
                                left.front()->first > right.front()->first)) {
                        time += t;

                        if (time < right.front()->first + t) {
                            time = right.front()->first + t;
                        }

                        bank = "right";
                    } else if (!left.empty()) {
                        time = left.front()->first;
                    }
                } else { // bank.compare("right") == 0
                    if (!ferry.empty()) {
                        time += t;
                        bank = "left";
                    } else if ((right.empty() && !left.empty()) || 
                               (!right.empty() && !left.empty() && 
                                right.front()->first > left.front()->first)) {
                        time += t;

                        if (time < left.front()->first + t) {
                            time = left.front()->first + t;
                        }

                        bank = "left";
                    } else if (!right.empty()) {
                        time = right.front()->first;
                    }
                }
            }

            while (!ferry.empty()) {
                ferry.front()->second = time;
                ferry.pop();
            }

            for (i = 0; i < m; i++) {
                std::cout << cars[i].second << std::endl;
            }

            if (c) {
                std::cout << std::endl;
            }
        }
    }

    return 0;
}
