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
        {9999, 9999},
        {1, 1},
        {0, 100},
        {100, 0},
        {1234, 5678},
        {99, 99},
        {12345, 67890}
    };
    
    int passed = 0, failed = 0;
    
    cout << "\n========== KARATSUBA TEST SUITE ==========\n";
    cout << "Testing Karatsuba multiplication against standard multiplication:\n\n";
    
    for(auto& test : testCases){
        long long num1 = test.first;
        long long num2 = test.second;
        long long expected = num1 * num2;
        long long result = k(num1, num2);
        
        bool testPassed = (result == expected);
        
        cout << "Test: " << num1 << " × " << num2;
        cout << " | Expected: " << expected;
        cout << " | Got: " << result;
        
        if(testPassed){
            cout << " | ✓ PASSED";
            passed++;
        }
        else{
            cout << " | ✗ FAILED";
            failed++;
        }
        cout << "\n";
    }
    
    cout << "\n========== TEST SUMMARY ==========\n";
    cout << "Total Tests: " << testCases.size() << "\n";
    cout << "Passed: " << passed << "\n";
    cout << "Failed: " << failed << "\n";
    cout << "Success Rate: " << (passed * 100 / testCases.size()) << "%\n";
    cout << "====================================\n\n";
    
    return failed == 0;
}

int main(){
    int choice;
    
    cout << "========== KARATSUBA MULTIPLICATION ==========\n";
    cout << "1. Run Self-Tests\n";
    cout << "2. Manual Calculation\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;
    
    if(choice == 1){
        bool allTestsPassed = runTests();
        cout << (allTestsPassed ? "All tests passed! ✓\n" : "Some tests failed! ✗\n");
    }
    else if(choice == 2){
        long long num1, num2;
        cout << "\nEnter number 1: ";
        cin >> num1;
        cout << "Enter number 2: ";
        cin >> num2;
        cout << "Product (Karatsuba): " << k(num1, num2) << "\n";
        cout << "Product (Standard): " << (num1 * num2) << "\n";
    }
    else{
        cout << "Invalid choice!\n";
    }
    
    return 0;
}