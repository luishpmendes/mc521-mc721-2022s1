#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

int main() {
    unsigned n, i;
    std::vector<std::string> names;
    std::vector<int> scores;
    std::string winner_name;
    int winner_score;
    std::set<std::string> possible_winners;
    std::map<std::string, int> scoreboard;

    while (std::cin >> n) {
        names.resize(n);
        scores.resize(n);
        scoreboard.clear();

        for (i = 0; i < n; i++) {
            std::cin >> names[i] >> scores[i];

            if (scoreboard.find(names[i]) == scoreboard.end()) {
                scoreboard[names[i]] = scores[i];
            } else {
                scoreboard[names[i]] += scores[i];
            }
        }

        winner_score = 0;

        for (std::map<std::string, int>::iterator it = scoreboard.begin(); it != scoreboard.end(); it++) {
            if (it->second > winner_score) {
                winner_score = it->second;
            }
        }

        possible_winners.clear();

        for (std::map<std::string, int>::iterator it = scoreboard.begin(); it != scoreboard.end(); it++) {
            if (it->second == winner_score) {
                possible_winners.insert(it->first);
            }
        }

        scoreboard.clear();

        for (i = 0; i < n; i++) {
            if (scoreboard.find(names[i]) == scoreboard.end()) {
                scoreboard[names[i]] = scores[i];
            } else {
                scoreboard[names[i]] += scores[i];
            }

            if (scoreboard[names[i]] >= winner_score && possible_winners.find(names[i]) != possible_winners.end()) {
                winner_name = names[i];
                break;
            }
        }

        std::cout << winner_name << std::endl;
    }

    return 0;
}
