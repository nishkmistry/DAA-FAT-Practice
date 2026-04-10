#include<iostream>
#include<vector>
#include<climits>
using namespace std;
struct SubarrayData{
    int sum, start, end;
};
SubarrayData MaxCrossingSum(vector<int> &num, int l, int m, int h){
    int s = 0, ls = INT_MIN, rs = INT_MIN, li, ri;
    for(int i=m; i>=l; i--){
        s = s + num[i];
        if(s > ls){
            ls = s;
            li = i;
        }
    }
    s = 0;
    for(int i=m+1; i<=h; i++){
        s = s + num[i];
        if(s > rs){
            rs = s;
            ri = i;
        }
    }
    return {rs + ls, li, ri};
}
SubarrayData MaxSubarray(vector<int> &num, int l, int h){
    if (l == h){
        return {num[l], l, l};
    }
    else{
        int m = l + (h-l) / 2;
        SubarrayData left = MaxSubarray(num, l, m), right = MaxSubarray(num, m+1, h), cross = MaxCrossingSum(num, l, m, h);
        if(left.sum > right.sum && left.sum > cross.sum){
            return left;
        }
        else if(right.sum > cross.sum){
            return right;
        }
        else{
            return cross;
        }
    }
}
int main(){
    int n;
    cout << "Size of the array: ";
    cin >> n;
    vector<int> num(n, 0);
    cout << "Array: ";
    for(int i=0; i<n; i++){
        cin >> num[i];
    }
    SubarrayData result = MaxSubarray(num, 0, n-1);
    cout << "Sum: " << result.sum;
    cout << endl << "Array : ";
    for(int i=result.start; i<=result.end; i++){
        cout << num[i] << " ";
    }
    return 0;
}