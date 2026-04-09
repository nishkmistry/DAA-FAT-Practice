#include<vector>
#include<algorithm>
#include<climits>
#include<iostream>
using namespace std;
struct SubarrayData{
    int sum, start, end;
};
SubarrayData MaxCrossingSum(vector<int> &num, int l, int m, int h){
    int s = 0, left_max_sum = INT_MIN, right_max_sum = INT_MIN, left_max, right_max;
    for(int i=m; i>=l; i--){
        s = num[i] + s;
        if(s > left_max_sum){
            left_max_sum = s;
            left_max = i;
        }
    }
    s = 0;
    for(int i=m+1; i<=h; i++){
        s = num[i] + s;
        if(s > right_max_sum){
            right_max_sum = s;
            right_max = i;
        }
    }
    return {left_max_sum+right_max_sum, left_max, right_max};
}
SubarrayData MaxSubarraySum(vector<int> &num, int l, int h){
    if(l == h){
        return {num[l], l, l};
    }
    else{
        int m = l + (h-l) / 2;
        SubarrayData left = MaxSubarraySum(num, l, m), right = MaxSubarraySum(num, m+1, h), bridge = MaxCrossingSum(num, l, m, h);
        if(left.sum > right.sum && left.sum > bridge.sum){
            return left;
        }
        else if(right.sum > left.sum && right.sum > bridge.sum){
            return right;
        }
        else{
            return bridge;
        }
    }
}
int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> a(n, 0);
    cout << "Enter the array: ";
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    SubarrayData result =  MaxSubarraySum(a, 0, n-1);
    cout << "Max Sum: " << result.sum << endl;
    cout << "The array starts from " << result.start << " and ends at " << result.end << "." << endl;
    cout << "Subarray: ";
    for(int i=result.start; i<=result.end; i++){
        cout << a[i] << " ";
    }
    return 0;
}