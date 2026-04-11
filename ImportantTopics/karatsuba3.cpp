#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
long long karatsuba(long long x, long long y){
    if(x<10 || y<10){
        return x*y;
    }
    else{
        string sx = to_string(x), sy = to_string(y);
        int n = max(sx.size(), sy.size()), half = n/2;
        long long p10 = 1;
        for(int i=0; i<half; i++){
            p10 *= 10;
        }
        long long a = x / p10, b = x % p10, c = y / p10, d= y % p10, p1 = karatsuba(a, c), p2 = karatsuba(b, d), p3 = karatsuba(a+b, c+d);
        return p1 * p10 * p10 + (p3 - p2 - p1) * p10 + p2;
    }
}
int main(){
    long long x, y;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    cout << "Result: " << karatsuba(x,y);
    return 0;
}