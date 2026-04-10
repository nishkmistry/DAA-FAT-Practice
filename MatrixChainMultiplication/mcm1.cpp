#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void printparenthesis(int i, int h,const vector<vector<int>>& bracket, char& m){
    if(i == h){
        cout << m++;
        return;
    }
    else{
        cout << "(";
        printparenthesis(i, bracket[i][h], bracket, m);
        printparenthesis(bracket[i][h]+ 1, h, bracket, m);
        cout << ")";
        return;
    }
}
void mcm(const vector<int>& p){
    int n = p.size();
    vector<vector<int>> m(n, vector<int>(n, 0)), bracket(n, vector<int>(n, 0));
    for(int i=2; i<n; i++){
        for(int j=1; j<n+1-i; j++){
            int k = j+i-1;
            m[j][k] = INT_MAX;
            for(int l=j; l<k; l++){
                int q = m[j][l] + m[l+1][k] + (p[j-1] * p[k] * p[l]);
                if(q < m[j][k]){
                    m[j][k] = q;
                    bracket[j][k] = l;
                }
            }
        }
    }
    cout << "Minimum Multiplication Required: " << m[1][n-1] << endl;
    char ma= 'A';
    cout << "Optimal Parenthesization: ";
    printparenthesis(1, n-1, bracket, ma);
    return;
}
int main(){
    vector<int> d = {40, 20, 30, 10, 30};;
    mcm(d);
    return 0;
}