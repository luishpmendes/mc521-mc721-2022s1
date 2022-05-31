#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s, t, m;
    std::vector<std::string> ans;
    unsigned curr_row, curr_col, dest_row, dest_col;

    while (std::cin >> s >> t) {
        curr_col = s[0] - 'a';
        curr_row = s[1] - '1';
        dest_col = t[0] - 'a';
        dest_row = t[1] - '1';

        while (curr_row != dest_row || curr_col != dest_col) {
            m = "";

            if (curr_col < dest_col) {
                curr_col++;
                m += 'R';
            } else if (curr_col > dest_col) {
                curr_col--;
                m += 'L';
            }

            if (curr_row < dest_row) {
                curr_row++;
                m += 'U';
            } else if (curr_row > dest_row) {
                curr_row--;
                m += 'D';
            }

            ans.push_back(m);
        }

        std::cout << ans.size() << std::endl;

        for (const std::string & move : ans) {
            std::cout << move << std::endl;
        }
    }

    return 0;
}
