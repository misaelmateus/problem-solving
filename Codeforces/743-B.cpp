//   Author : Misael Mateus 
//   Submission date: 2016-12-14 19:49:12
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll f(ll a, ll b, ll k){
    if((a+b)/2LL == k) return 0LL;
    
    ll middle = (a + b)/2LL;
    
    
    if(middle < k)
        return f(middle, b, k) + 1LL;
    else
        return f(a, middle, k) + 1LL;
}
int main(){
    ll n, k;
    cin >> n >> k;
    
    ll a = 0LL;
    ll b = 0LL;
    ll cont = 1LL;
    for(ll i = 0; i < n; i++){
        b += cont;
        cont *= 2LL;
    }
    b++;
    
    cout << (n - f(a, b, k));
    
    return 0;

}