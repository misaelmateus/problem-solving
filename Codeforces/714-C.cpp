//   Author : Misael Mateus 
//   Submission date: 2016-09-13 22:36:22
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll conv(ll n){
    ll cont = 1LL;
    ll resp = 0LL;
    while(n > 0){
        if( n % 2LL == 1LL )
            resp += cont;
        cont *= 10L;
        n /= 10LL;
    }
    return resp;
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    char c;
    map<ll, int> mapa;
    cin >> t;
    while(t--){
        cin.ignore();
        ll aux;
        cin >> c >> aux;
        aux = conv(aux);
        if(c == '-')
            mapa[aux]--;
        else if(c == '+')
            mapa[aux]++;
        else
        {
            cout << mapa[aux] << endl;
        }
    }
}