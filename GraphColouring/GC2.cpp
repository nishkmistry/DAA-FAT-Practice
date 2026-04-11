#include<iostream>
#include<vector>
using namespace std;
bool isSafe(const vector<vector<int>>& graph, const vector<int>& color, int c, int v){
    int l = graph.size();
    for(int i=0; i<l; i++){
        if(graph[v][i] == 1 && c == color[i]){
            return false;
        }
    }
    return true;
}
bool graphcolouringUtil(int m, int v, const vector<vector<int>>& graph, vector<int>& color){
    int l = graph.size();
    if(v == l){
        return true;
    }
    else{
        for(int c=1; c<m+1; c++){
            if(isSafe(graph, color, c, v)){
                color[v] = c;
                if(graphcolouringUtil(m, v+1, graph, color)){
                    return true;
                }
                color[v] = 0;
            }
        }
        return false;
    }

}
void solvegraphcolouring(const vector<vector<int>>& graph, int m){
    int l = graph.size();
    vector<int> v(l, 0);
    if(graphcolouringUtil(m, 0, graph, v)){
        cout << "The solution exists !" << endl << "The assigned colors: " << endl;
        for(int i=0; i<l; i++){
            cout << "Vertex " << i << " --> " << "Color " << v[i] << endl;
        }
    }
}
int main(){
    vector<vector<int>> graph = {
        {0, 1, 0, 1},
        {1, 0, 1, 1},
        {0, 1, 0, 1},
        {1, 1, 1, 0}
    };
    int m = 3;
    solvegraphcolouring(graph, m);
    return 0;
}