#include<iostream>
#include<vector>
using namespace std;
bool isSafe(const vector<vector<int>> &graph, const vector<int> color, int c, int v){
    int l = graph.size();
    for(int i=0; i<l; i++){
        if(graph[v][i] == 1 && color[i] == c){
            return false;
        }
    }
    return true;
}
bool graphcolouringutil(const vector<vector<int>> &graph, vector<int>& color, int v, int m){
    int l = graph.size();
    if(l == v){
        return true;
    }
    else{
        for(int c=1; c<=m; c++){
            if(isSafe(graph, color, c, v)){
                color[v] = c;
                if(graphcolouringutil(graph, color, v+1, m)){
                    return true;
                }
                color[v] = 0;
            }
        }
        return false;
    }
}
void graphcolouringsolver(const vector<vector<int>> &graph, int m){
    int l = graph.size();
    vector<int> color(l, 0);
    if(!graphcolouringutil(graph, color, 0, m)){
        cout << "No solution exist:" << endl;
    }
    cout << "Solution exist: " << endl;
    for(int i=0; i<l; i++){
        cout << "Vertex " << i << " --> " << "Color " << color[i] << endl;
    }
    return;
}
int main(){
    vector<vector<int>> graph = {
        {0, 1, 0, 1},
        {1, 0, 1, 1},
        {0, 1, 0, 1},
        {1, 1, 1, 0}
    };
    int m = 3;
    graphcolouringsolver(graph, m);
    return 0;
}