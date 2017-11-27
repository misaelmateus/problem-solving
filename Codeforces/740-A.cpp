//   Author : Misael Mateus 
//   Submission date: 2016-11-23 22:00:56
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n, a, b, c;
    cin >> n >> a >> b >> c;
    if(2*a < b)
        b = 2*a;
    if(3*a < c)
        c = 3*a;
    if(a + b < c)
        c = a+b;
    if(n%4 == 3){
        cout << min(a, min(b+c, 3LL*c));
    }
    if(n%4 == 2){
        cout << min(b, min(2LL*a, 2LL*c));
    }
    if(n%4 == 1){
        cout << min(c, min(3LL*a, b+a));
    }
    if(n%4 == 0)
        cout << 0;
    cout << endl;
    
    return 0;
}