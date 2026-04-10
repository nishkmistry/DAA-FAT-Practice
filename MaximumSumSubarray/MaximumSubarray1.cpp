#include<iostream>
#include<vector>
#include<climits>
using namespace std;
struct SubarrayData{
    int sum, start, end;
};
SubarrayData MaxCrossingSum(vector<int> &num, int l, int m, int h){
    int s = 0, lms = INT_MIN, rms = INT_MIN, lm, rm;
    for(int i=m; i>=l; i--){
        s = s + num[i];
        if(s > lms){
            lms = s;
            lm = i;
        }
    }
s = 0;
    for(int i=m+1; i<=h; i++){
        s = s + num[i];
        if(s > rms){
            rms = s;
            rm = i;
        }
    }
    return {lms + rms, lm, rm};
}
SubarrayData MaxSubarray(vector<int> &num, int l, int h){
    if(l == h){
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
    cout << "Enter number of the elements in the array: ";
    cin >> n;
    vector<int> a(n, 0);
    cout << "Enter the array: ";
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    SubarrayData result = MaxSubarray(a, 0, n-1);
    cout << "Max Sum: " << result.sum << endl;
    cout << "Array : ";
    for(int i=result.start; i<=result.end; i++){
        cout << a[i] << " ";
    }
    return 0;
}