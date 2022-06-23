#include <algorithm>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

class disjoint_sets {
    private:

    // This disjoint sets' representative of each element.
    std::vector<unsigned> p;

    // This disjoint sets' rank of each element.
    std::vector<unsigned> rank;

    // Links the set that has x as representative with the set that has y as representative.
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
    // Constructs a new disjoint sets.
    disjoint_sets(unsigned n) : p(n, std::numeric_limits<unsigned>::max()), rank(n, 0) {}

    // Constructs a new empty disjoint sets.
    disjoint_sets() : disjoint_sets::disjoint_sets(0) {}

    // Verifies whether there is a set containing x.
    bool has_set(unsigned x) const {
        return (x < this->p.size() && this->p[x] < std::numeric_limits<unsigned>::max());
    }

    // Creates a new set whose only member (and thus representative) is x.
    // Since the sets are disjoint, we require that x not already be in some other set.
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

    // Returns the representative of the (unique) set containing x.
    unsigned find_set(unsigned x) {
        if (x != this->p[x]) {
            this->p[x] = this->find_set(this->p[x]);
        }

        return this->p[x];
    }

    // Unites the dynamic sets that contain x and y into a new set that is the union of these two sets.
    void union_sets(unsigned x, unsigned y) {
        this->link_sets(this->find_set(x), this->find_set(y));
    }
};

std::vector<std::pair<unsigned, std::pair<unsigned, unsigned>>> kruskal(unsigned n, std::vector<std::pair<unsigned, std::pair<unsigned, unsigned>>> & E) {
    std::vector<std::pair<unsigned, std::pair<unsigned, unsigned>>> A; // A ← ∅
    disjoint_sets S(n);

    for (unsigned v = 0; v < n; v++) {
        S.make_set(v);
    }

    // sort the edges of E into nondecreasing order by weight w
    std::sort(E.begin(), E.end());

    // for each edge (u, v) ∈ E, taken in nondecreasing order by weight
    for (const auto & e : E) {
        if (S.find_set(e.second.first) != S.find_set(e.second.second)) {
            A.push_back(e);
            S.union_sets(e.second.first, e.second.second);
        }
    }

    return A;
}

int main() {
    unsigned n, m, ans;
    std::vector<std::pair<unsigned, std::pair<unsigned, unsigned>>> E;

    while (std::cin >> n >> m && (n || m)) {
        ans = 0;
        E.resize(m);

        for (auto & e : E) {
            std::cin >> e.second.first >> e.second.second >> e.first;
            ans += e.first;
        }

        for (auto & e : kruskal(n, E)) {
            ans -= e.first;
        }

        std::cout << ans << std::endl;
    }

    return 0;
}
