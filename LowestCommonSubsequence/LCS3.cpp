#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
void lcs(string x, string y){
    int m = x.length(), n = y.length();
    vector<vector<int>> l(m+1, vector<int>(n+1, 0));
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(x[i-1] == y[j-1]){
                l[i][j] = l[i-1][j-1] + 1;
            }
            else{
                l[i][j] = max(l[i-1][j], l[i][j-1]);
            }
        }
    }
    int index = l[m][n], i = m, j = n;
    string ls(index, '\0');
    while(i>0 && j>0){
        if(x[i-1] == y[j-1]){
            ls[index-1] = x[i-1];
            index--;
            i--;
            j--;
        }
        else if(l[i-1][j] > l[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout << "Length of LCS: " << l[m][n] << endl << "LCS: " << ls << endl;
    return;
}
int main(){
    string x, t;
    cout << "Enter String 1: ";
    cin >> x;
    cout << "Enter String 2: ";
    cin >> t;
    lcs(x, t);
    return 0;
}