#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void lcs(string x, string y){
    int m = x.length(), n = y.length();
    vector<vector<int>> l(m+1, vector<int>(n+1, 0));
    for(int i=1; i<m+1; i++){
        for(int j=1; j<=n; j++){
            if(x[i-1] == y[j-1]){
                l[i][j] = l[i-1][j-1] + 1;
            }
            else{
                l[i][j] = max(l[i][j-1], l[i-1][j]);
            }
        }
    }
    int index = l[m][n], i = m, j = n;
    string lcsstr(index, '\0');
    while(i>0 && j>0){
        if(x[i-1] == y[j-1]){
            lcsstr[index-1] = x[i-1];
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
    cout << "Length of a string: " << l[m][n] << endl << "LCS : " << lcsstr;
    return;
}
int main(){
    string x, y;
    cout << "Enter string 1: ";
    cin >> x;
    cout << "Enter string 2: ";
    cin >> y;
    lcs(x, y);
    return 0;
}