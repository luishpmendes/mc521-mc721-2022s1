#include <iostream>
#include <string>
#include <map>

int main() {
    unsigned n;
    std::string s;
    std::map<std::string, unsigned> registration_system;

    while (std::cin >> n) {
        registration_system.clear();

        while (n--) {
            std::cin >> s;

            if (registration_system.find(s) == registration_system.end()) {
                registration_system[s] = 1;
                std::cout << "OK" << std::endl;
            } else {
                std::cout << s + std::to_string(registration_system[s]) << std::endl;
                registration_system[s + std::to_string(registration_system[s])] = 1;
                registration_system[s]++;
            }
        }
    }

    return 0;
}
