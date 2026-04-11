#include<iostream>
using namespace std;
int N;
int board[100][100];
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
void solvenqueen(int r){
    if(r == N){
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
        for(int c=0; c<N; c++){
            if(isSafe(r, c)){
                board[r][c] = 1;
                solvenqueen(r+1);
                board[r][c] = 0;
            }
        }
    }
}
int main(){
    cin >> N;
    solvenqueen(0);
    return 0;
}