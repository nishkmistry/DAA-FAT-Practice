#include<iostream>
using namespace std;
#define MAX 100
int board[MAX][MAX];
int N;
bool isSafe(int r, int c){
    for(int i=0; i<r; i++){
        if(board[i][c]){
            return false;
        }
    }
    for(int i=r-1, j=c-1; i>=0 && j>=0; i--, j--){
        if(board[i][j]){
            return false;
        }
    }    
    for(int i=r-1, j=c+1; i>=0 && j<N; i--, j++){
        if(board[i][j]){
            return false;
        }
    }
    return true;
}
void SolveNQueen(int row){
    if(row == N){
        cout << "Solution: " << endl;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    else{
        for(int i=0; i<N; i++){
            if(isSafe(row, i)){
                board[row][i] = 1;
                SolveNQueen(row+1);
                board[row][i] = 0;
            }
        }
    }
    return;
}
int main(){
    
    cout << "Enter :";
    cin >> N;
    SolveNQueen(0);
    return 0;
}