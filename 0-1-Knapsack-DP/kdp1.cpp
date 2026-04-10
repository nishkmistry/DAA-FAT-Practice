#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter capacity: ";
    cin >> W;
    struct Item{
        int w, v;
        double r;
    };
    int zerovaluesum;
    vector<Item> items;
    cout << "Enter (w v):";
    for(int i=0; i<n; i++){
        int w, v;
        cin >> w >> v;
        if(w == 0){
            zerovaluesum = v + zerovaluesum;
        }
        else{
            items.push_back({w, v, (double)v/(double)w});
        }
    }
    int rem = W;
    double fracTotal = (double) zerovaluesum;
    vector<int> dp(W+1, 0);
    for(auto &it : items){
        int wt = it.w, val = it.v;
        for(int cap = W; cap >= wt; cap--){
            dp[cap] = max(dp[cap], dp[cap - wt] + val);
        }
    }
    int bestdp = dp[W] + zerovaluesum;
    cout << "Maximum value: " << bestdp << endl;
    return 0;
}