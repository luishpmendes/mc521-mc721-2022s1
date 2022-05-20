#include <iostream>
#include <vector>

unsigned dfs(unsigned a, const std::vector<unsigned> & p, std::vector<bool> & visited) {
    visited[a] = true;

    if (visited[p[a]]) {
        return p[a];
    } else {
        return dfs(p[a], p, visited);
    }
}

int main() {
    unsigned n, a;
    std::vector<unsigned> p;
    std::vector<bool> visited;

    while (std::cin >> n) {
        p.resize(n);
        visited.reserve(n);

        for (unsigned & x : p) {
            std::cin >> x;
            x--;
        }

        for (a = 0; a < n; a++) {
            visited.clear();
            visited.resize(p.size(), false);
            std::cout << dfs(a, p, visited) + 1 << ' ';
        }

        std::cout << std::endl;
    }

    return 0;
}
