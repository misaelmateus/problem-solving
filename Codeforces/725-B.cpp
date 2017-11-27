//   Author : Misael Mateus 
//   Submission date: 2016-10-22 20:51:11
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll ord(char a){
    if(a <= 'f' && a >= 'd')
        return (ll)('f' - a + 1);
    else
        return (ll)(6LL - (ll)('c' - a));
}

ll ver(ll n){
    if( ((n + 1LL)/2LL)%2== 1)
        return 0LL;
    return 1LL;
}
int main(){
    ll n;
    char c;
    cin >> n >> c;
    ll r = ((n-1LL)/4LL)*12LL + 6LL*(ll)(n % 2LL == 0LL) + (n - 1LL - 2LL*ver(n)) + ord(c);
    
    cout << r << endl;
}