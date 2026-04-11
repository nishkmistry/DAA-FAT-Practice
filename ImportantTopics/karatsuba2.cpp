#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
long long k(long long x, long long y){
    if(x*y < 100){
        return x*y;
    }
    else{
        string sx = to_string(x), sy = to_string(y);
        int n = max(sx.size(), sy.size());
        int h = n/2;
        long long p10 = 1;
        for(int i=0; i<h; i++){
            p10 = p10 * 10;
        }
        long long a = x / p10, b = x % p10, c = y / p10, d = y % p10, p1 = k(a, c), p2 = k(b, d), p3 = k(a+b, c+d);
        return p1 * p10 * p10 + p2 + (p3-p2-p1) * p10;
    }
}
int main(){
    cout << k(123456789, 987654321);
    return 0;
}