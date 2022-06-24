#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

class disjoint_sets {
    private:

    std::vector<unsigned> p;

    std::vector<unsigned> rank;

    void link_sets(unsigned x, unsigned y) {
        if (x != y) {
            if (this->rank[x] > this->rank[y]) {
                this->p[y] = x;
            } else {
                this->p[x] = y;

                if (this->rank[x] == this->rank[y]) {
                    this->rank[y]++;
                }
            }
        }
    }

    public:
    disjoint_sets(unsigned n) : p(n, std::numeric_limits<unsigned>::max()), rank(n, 0) {}

    disjoint_sets() : disjoint_sets::disjoint_sets(0) {}

    bool has_set(unsigned x) const {
        return (x < this->p.size() && this->p[x] < std::numeric_limits<unsigned>::max());
    }

    void make_set(unsigned x) {
        while (x >= this->p.size()) {
            this->p.push_back(std::numeric_limits<unsigned>::max());
        }

        while (x >= this->rank.size()) {
            this->rank.push_back(0);
        }

        this->p[x] = x;
        this->rank[x] = 0;
    }

    unsigned find_set(unsigned x) {
        if (x != this->p[x]) {
            this->p[x] = this->find_set(this->p[x]);
        }

        return this->p[x];
    }

    void union_sets(unsigned x, unsigned y) {
        this->link_sets(this->find_set(x), this->find_set(y));
    }
};

std::vector<std::pair<long, std::pair<unsigned, unsigned> > > kruskal(unsigned p, unsigned s, std::vector<std::pair<long, std::pair<unsigned, unsigned> > > & E) {
    std::vector<std::pair<long, std::pair<unsigned, unsigned>>> A;
    disjoint_sets S(p);

    for (unsigned v = 0; v < p; v++) {
        S.make_set(v);
    }

    std::sort(E.begin(), E.end());

    for (unsigned i = 0; i < E.size() && A.size() + s < p; i++) {
        if (S.find_set(E[i].second.first) != S.find_set(E[i].second.second)) {
            A.push_back(E[i]);
            S.union_sets(E[i].second.first, E[i].second.second);
        }
    }

    return A;
}

int main() {
    unsigned n, s, p, i, j, k;
    std::vector<unsigned> x, y;
    std::vector<std::pair<long, std::pair<unsigned, unsigned> > > E;
    double ans;

    while (std::cin >> n) {
        while (n--) {
            std::cin >> s >> p;
            
            k = 0;
            ans = 0;
            x.resize(p);
            y.resize(p);
            E.resize((p * (p - 1)) / 2);

            for (i = 0; i < p; i++) {
                std::cin >> x[i] >> y[i];
            }

            for (i = 0; i < p; i++) {
                for (j = i + 1; j < p; j++) {
                    E[k++] = std::make_pair((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]), std::make_pair(i, j));
                }
            }

            for (const auto & e : kruskal(p, s, E)) {
                if (ans < e.first) {
                    ans = e.first;
                }
            }

            std::cout << std::setprecision(2) << std::fixed << sqrt(ans) << std::endl;
        }
    }

    return 0;
}
