//   Author : Misael Mateus 
//   Submission date: 2016-09-13 22:33:23
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    
    ll resp = 0LL;
    if(b < c || d < a)
        printf("0\n");
    else{
        if(a >= c && b <= d)
            resp = b - a + 1LL;
        else if(a < c && d < b)
            resp = d - c + 1LL;
        else if(b >= c && d >= b)
            resp = b - c + 1LL;
        else    
            resp = d - a + 1LL;
        if(k >= a && k <= b && k >= c && k <= d)
            resp--;
        cout << resp << endl;
    }
    
    return 0;
}