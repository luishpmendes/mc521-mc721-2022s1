#include <iostream>
 
int main() {
    unsigned t, n, ans;
    std::string enemy, ally;

	for (std::cin >> t; t; t--) {
        std::cin >> n >> enemy >> ally;

        ans = 0;

		for (int i = 0; i < n; i++) {
            if (ally[i] == '1') {
			    if (enemy[i] == '0' || (i > 0 && enemy[i - 1] == '1')) {
                    ans++;
                } else if (i < n - 1 && enemy[i + 1] == '1') {
                    ans++;
                    enemy[i + 1] = '2';
                }
            }
        }

		std::cout << ans << std::endl;
	}
	return 0;
}
