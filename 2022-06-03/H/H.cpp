#include <iostream>
#include <string>
#include <vector>

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

int main() {
    unsigned n, m, s, i, j, row, col, dir, new_row, new_col, stickers;
    std::vector<std::string> arena;
    std::string instructions;

    while (std::cin >> n >> m >> s && (n || m || s)) {
        stickers = 0;
        arena.clear();
        arena.resize(n);

        for (i = 0; i < n; i++) {
            std::cin >> arena[i];

            for (j = 0; j < m; j++) {
                if (arena[i][j] == 'N') {
                    row = i;
                    col = j;
                    dir = NORTH;
                } else if (arena[i][j] == 'S') {
                    row = i;
                    col = j;
                    dir = SOUTH;
                } else if (arena[i][j] == 'L') {
                    row = i;
                    col = j;
                    dir = EAST;
                } else if (arena[i][j] == 'O') {
                    row = i;
                    col = j;
                    dir = WEST;
                }
            }
        }

        std::cin >> instructions;

        for (const char & c : instructions) {
            if (c == 'D') {
                if (dir == NORTH) {
                    dir = EAST;
                } else if (dir == SOUTH) {
                    dir = WEST;
                } else if (dir == EAST) {
                    dir = SOUTH;
                } else if (dir == WEST) {
                    dir = NORTH;
                }
            } else if (c == 'E') {
                if (dir == NORTH) {
                    dir = WEST;
                } else if (dir == SOUTH) {
                    dir = EAST;
                } else if (dir == EAST) {
                    dir = NORTH;
                } else if (dir == WEST) {
                    dir = SOUTH;
                }
            } else if (c == 'F') {
                if (dir == NORTH) {
                    new_row = row - 1;
                    new_col = col;
                } else if (dir == SOUTH) {
                    new_row = row + 1;
                    new_col = col;
                } else if (dir == EAST) {
                    new_row = row;
                    new_col = col + 1;
                } else if (dir == WEST) {
                    new_row = row;
                    new_col = col - 1;
                }

                if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m) {
                    if (arena[new_row][new_col] == '*') {
                        stickers++;
                    }

                    if (arena[new_row][new_col] == '.' || arena[new_row][new_col] == '*') {
                        arena[row][col] = '.';
                        row = new_row;
                        col = new_col;
                    }

                    if (dir == NORTH) {
                        arena[row][col] = 'N';
                    } else if (dir == SOUTH) {
                        arena[row][col] = 'S';
                    } else if (dir == EAST) {
                        arena[row][col] = 'E';
                    } else if (dir == WEST) {
                        arena[row][col] = 'O';
                    }
                }
            }
        }

        std::cout << stickers << std::endl;
    }

    return 0;
}
