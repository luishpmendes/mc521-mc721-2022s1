#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

void solve(long long l, long long r, const std::vector<long long> & a, std::set<long long> & prettiness) {
    long long sum = 0, i, mid, pos;

    for (i = l; i <= r; i++) {
        sum += a[i];
    }

    prettiness.insert(sum);

    mid = (a[l] + a[r]) / 2;
    pos = -1;

    for (i = l; i <= r; i++) {
        if (a[i] <= mid) {
            pos = i;
        } else {
            break;
        }
    }

    if (pos != -1 && pos != r) {
        solve(l, pos, a, prettiness);
        solve(pos + 1, r, a, prettiness);
    }
}

int main() {
    long long t, n, q, p;
    std::vector<long long> a;
    std::set<long long> prettiness;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n >> q;
            a.resize(n);
            prettiness.clear();

            for (long long & x : a) {
                std::cin >> x;
            }

            std::sort(a.begin(), a.end());

            solve(0, n - 1, a, prettiness);

            while (q--) {
                std::cin >> p;

                if (prettiness.find(p) != prettiness.end()) {
                    std::cout << "Yes" << std::endl;
                } else {
                    std::cout << "No" << std::endl;
                }
            }
        }
    }

    return 0;
}
