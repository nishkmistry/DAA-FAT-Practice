#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

long long k(long long x, long long y){
    if(x<10 || y<10){
        return x*y;
    }
    else{
        string sx = to_string(x), sy = to_string(y);
        int n = max(sx.size(), sy.size()), half = n/2;
        long long pow10 = 1;
        for(int i=0; i<half; i++){
            pow10 *= 10;
        }
        long long a = x/pow10, b = x%pow10, c = y/pow10, d = y%pow10, p1=k(a,c), p2=k(b, d), p3=k(a+b, c+d);
        return p1*(pow10*pow10) + (p3-p1-p2) * pow10 + p2;
    }
}

bool runTests(){
    vector<pair<long long, long long>> testCases = {
        {5, 3},
        {10, 20},
        {123, 456},
 