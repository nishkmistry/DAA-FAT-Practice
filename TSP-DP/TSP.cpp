#include <bits/stdc++.h>
#include <climits>
using namespace std;

int n;
vector<vector<int>> dist;
vector<vector<int>> dp;
vector<vector<int>> parent;

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1)
        return dist[pos][0];

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            if (newAns < ans) {
                ans = newAns;
                parent[mask][pos] = city;
            }
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    cin >> n;

    dist.resize(n, vector<int>(n));
    dp.resize(1 << n, vector<int>(n, -1));
    parent.resize(1 << n, vector<int>(n, -1));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];

    int cost = tsp(1, 0);

    vector<int> path;
    int mask = 1, pos = 0;
    path.push_back(0);

    while (true) {
        int nxt = parent[mask][pos];
        if (nxt == -1) break;
        path.push_back(nxt);
        mask |= (1 << nxt);
        pos = nxt;
    }

    path.push_back(0);

    cout << cost << endl;

    for (int x : path)
        cout << x << " ";

    return 0;
}