#include<iostream>
#include<vector>
#include<climits>
using namespace std;
struct SubarrayData{
    int sum, start, end;
};
SubarrayData MaxCrossingSum(const vector<int> &num, int l, int h, int m){
    int sum = 0, ls = INT_MIN, rs = INT_MIN, li, ri;
    for(int i=m; i>=l; i--){
        sum = num[i] + sum;
        if(sum > ls){
            ls = sum;
            li = i;
        }
    }
    sum = 0;
    
    for(int i=m+1; i<=h; i++){
        sum = num[i] + sum;
        if(sum > rs){
            rs = sum;
            ri = i;
        }
    }
    return {ls + rs, li, ri};
}
SubarrayData MaxSubarray(const vector<int> &num, int l, int h){
    if(l == h){
        return {num[l], l, l};
    }
    else{
        int m = l + (h-l)/2;
        SubarrayData left = MaxSubarray(num, l, m), right = MaxSubarray(num, m+1, h), cross = MaxCrossingSum(num, l, h, m);
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
    cout << "Enter n: ";
    cin >> n;
    vector<int> num(n, 0);
    cout << "Array : ";
    for(int i=0; i<n; i++){
        cin >> num[i];
    }
    SubarrayData result = MaxSubarray(num, 0, n-1);
    cout << "Max Sum: " << result.sum << endl << "Subarray :" ;
    for(int i=result.start; i<result.end+1; i++){
        cout << num[i] << " ";
    }
    return 0;
}