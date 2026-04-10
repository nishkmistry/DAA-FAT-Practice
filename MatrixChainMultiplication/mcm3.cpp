#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void pp(int i, int j, const vector<vector<int>> &bracket, char &n){
    if(i == j)
    {
        cout << n++;
        return;
    }
    else{
        cout << "(";
        pp(i, bracket[i][j], bracket, n);
        pp(bracket[i][j] + 1, j, bracket, n);
        cout << ")";
        return;
    }
}
void mcm(const vector<int> &p){
    int n = p.size();
    vector<vector<int>> m(n, vector<int>(n, 0)), bracket(n, vector<int>(n, 0));
    for(int i=2; i<n; i++){
        for(int j=1; j<n+1-i; j++){
            int k = j+i - 1;
            m[j][k] = INT_MAX;
            for(int l=j; l<k; l++){
                int q = m[j][l] + m[l+1][k] + p[j-1] * p[l] * p[k];
                if(q < m[j][k]){
                    m[j][k] = q;
                    bracket[j][k] = l;
                }
            }
        }
    }
    cout << "Minimum Multiplication required: " << m[1][n-1] << endl << "Optimal Parenthesization: ";
    char a = 'A';
    pp(1, n-1, bracket, a);
    return;
}
int main(){
    vector<int> d = {40, 20, 30, 10, 30};;
    mcm(d);
    return 0;
}