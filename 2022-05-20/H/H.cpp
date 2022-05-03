#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    std::string s;
    unsigned k;
    std::vector<std::string> index_to_month;
    std::map<std::string, unsigned> month_to_index;

    index_to_month.push_back("January");
    index_to_month.push_back("February");
    index_to_month.push_back("March");
    index_to_month.push_back("April");
    index_to_month.push_back("May");
    index_to_month.push_back("June");
    index_to_month.push_back("July");
    index_to_month.push_back("August");
    index_to_month.push_back("September");
    index_to_month.push_back("October");
    index_to_month.push_back("November");
    index_to_month.push_back("December");

    for (unsigned i = 0; i < index_to_month.size(); ++i) {
        month_to_index[index_to_month[i]] = i;
    }

    while(std::cin >> s >> k) {
        std::cout << index_to_month[(month_to_index[s] + k) % 12] << std::endl;
    }
    
    return 0;
}
