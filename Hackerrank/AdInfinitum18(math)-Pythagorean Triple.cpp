#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;


int main() {
    ll x;
    cin >> x;
    ll a, b, c;
    if(x % 2 == 1){
        x = x/2;
        a = 2*x + 1;
        b = 2*(x+1)*x;
        c = (x+1)*(x+1) + x*x;
    }
    else{
        x = x/2;
        a = x*x-1;
        b = 2*x;
        c= x*x+1;
    }
    cout << a << " " << b << " " << c << endl;
    return 0;
}
