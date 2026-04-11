#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1e9

void floydWarshall(int V, vector<vector<int>>& dist) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int V = 4;
    vector<vector<int>> dist = {
        {0, 5, (int)INF, 10},
        {(int)INF, 0, 3, (int)INF},
        {(int)INF, (int)INF, 0, 1},
        {(int)INF, (int)INF, (int)INF, 0}
    };

    floydWarshall(V, dist);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << "   ";
        }
        cout << endl;
    }

    return 0;
}