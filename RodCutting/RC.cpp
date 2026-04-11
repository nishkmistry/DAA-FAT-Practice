#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int cutRod(const std::vector<int>& prices, int n) {
    std::vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int max_val = INT_MIN;
        for (int j = 0; j < i; j++) {
            max_val = std::max(max_val, prices[j] + dp[i - j - 1]);
        }
        dp[i] = max_val;
    }

    return dp[n];
}

int main() {
    std::vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;
    std::cout << "Maximum Revenue: " << cutRod(prices, n) << std::endl;
    return 0;
}