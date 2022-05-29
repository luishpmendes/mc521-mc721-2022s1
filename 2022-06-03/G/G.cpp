#include <iostream>
#include <string>
#include <vector>

int floodfill(std::vector<std::string> & grid, int n, int m, int * dr, int * dc, int i, int j, char c1, char c2) {
    if (j == -1) {
        return floodfill(grid, n, m, dr, dc, i, m - 1, c1, c2);
    }

    if (j == m) {
        return floodfill(grid, n, m, dr, dc, i, 0, c1, c2);
    }

    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != c1) { // outside the grid or does not have color c1
        return 0;
    }

    int result = 1; // adds 1 to result because vertex (i, j) has c1 as its color
    grid[i][j] = c2; // changes the color of vertex (i, j) to c2 to avoid cycling!

    for (int d = 0; d < 8; d++) {
        result += floodfill(grid, n, m, dr, dc, i + dr[d], j + dc[d], c1, c2);
    }

    return result;
}

int main() {
    int n, m, x, y, i, j, ans, aux;
    std::vector<std::string> grid;
    int dr[] = {1, 0, -1,  0};
    int dc[] = {0, 1,  0, -1};
    char c1, c2;

    while (std::cin >> n >> m) {
        grid.resize(n, "");
        grid.assign(n, "");

        for (i = 0; i < n; i++) {
            std::cin >> grid[i];
        }

        std::cin >> x >> y;

        c1 = c2 = grid[x][y];
        ans = 0;

        for (i = 0; i < n && c1 == c2; i++) {
            for (j = 0; j < m && c1 == c2; j++) {
                if (grid[i][j] != c1) {
                    c2 = grid[i][j];
                }
            }
        }

        if (c1 != c2) {
            floodfill(grid, n, m, dr, dc, x, y, c1, c2);

            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    aux = floodfill(grid, n, m, dr, dc, i, j, c1, c2);

                    if (ans < aux) {
                        ans = aux;
                    }
                }
            }
        }

        std::cout << ans << std::endl;
    }

    return 0;
}
