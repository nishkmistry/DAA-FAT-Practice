#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Item {
    int v, w, idx;
};
int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter capacity: ";
    cin >> W;
    vector<Item> items(n);
    cout << "Enter (value weight): " << endl;
    for (int i = 0; i < n; i++) {
        cin >> items[i].v >> items[i].w;
        items[i].idx = i + 1;
    }
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int cap = 0; cap <= W; cap++) {
            if (items[i - 1].w <= cap) {
                dp[i][cap] = max(dp[i - 1][cap], dp[i - 1][cap - items[i - 1].w] + items[i - 1].v);
            } else {
                dp[i][cap] = dp[i - 1][cap];
            }
        }
    }
    cout << "\nMaximum value: " << dp[n][W] << endl;
    int cap = W;
    vector<int> chosen;
    for (int i = n; i > 0; i--) {
        if (dp[i][cap] != dp[i - 1][cap]) {
            chosen.push_back(items[i - 1].idx);
            cap -= items[i - 1].w;
        }
    }
    reverse(chosen.begin(), chosen.end());
    cout << "Selected item indices (1-based): ";
    if (chosen.empty()) {
        cout << "None";
    } else {
        for (int i = 0; i < chosen.size(); i++) {
            if (i) cout << ", ";
            cout << chosen[i];
        }
    }
    cout << endl;
    return 0;
}