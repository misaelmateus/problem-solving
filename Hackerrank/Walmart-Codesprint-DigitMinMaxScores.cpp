#include <bits/stdc++.h>
#define ll long long
#define FAT 10LL
using namespace std;
vector<ll> a, c, b;
int t;

ll pow1(ll a, ll b){
    if(b == 0LL)
        return 1LL;
    ll r = 1LL;
    if(b % 2LL == 1LL) r = a;
    r *= pow1(a*a, b/2LL);
    return r;
}



ll f2(int i, vector<ll> n, int f){
    if(i < 0LL)
        return 1LL;
    ll result = 0LL;
    if(n[i] != -1LL){
        ll n1 = n[i] * 100LL + n[i-1]*10LL + n[i-2];
        ll b1 = b[i] * 100LL + b[i-1]*10LL + b[i-2];
        if(n1 > b1)
            return 0LL;

        if(n1 == b1)
            return f2(i-3, n, 1);
        else return pow1(FAT, (ll)i-2LL);
    }
    else{
        if(f == 0)
            result += (b[i])*pow1(FAT, (ll)(i) - 3LL);
        else
            result += (b[i])*pow1(FAT, (ll)(i));
        result += f2((i-1), n, f);
        return result;
    }
}


ll f3(int i, vector<ll> n, int f){
    int cont = 0;
    int j;
    for(j = i; j >= 0; j--){
        if(n[j] != -1)
            break;
        if(b[j] != 0)
            cont++;
    }
    
    if(cont == 0)
        return f2(j, n, f);
    return pow1(FAT, (ll)(j-2));
}


int main() {
    ll A, B;
    cin >> A >> B;
    a = vector<ll>(13, 0LL);
    c = vector<ll>(13, 0LL);
    A--;
    for(t = 0; A || B; t++){
        a[t] = A%10LL, c[t] = B%10LL;
        A /= 10LL, B /= 10LL;
    }
    t--;
    ll sum = 0LL;
    for(int i = 1; i < t; i++){
        for(ll l = 0LL; l <= 9LL; l++){
            for(ll m = 0LL; m <= 9LL; m++){
                for(ll n = 0LL; n <= 9LL; n++){
                    vector<ll> v(13, -1LL);
                    v[i] = l;
                    v[i-1] = m;
                    
                    v[i+1] = n;
                    
                    if((l > m && l > n ) || (l < m && l < n)){
                        b = c;
                        sum += f2(t, v, 0);
                        if(n == 0)
                            sum -= f3(t, v, 0);
                        b = a;
                        sum -= f2(t, v, 0);
                        if(n == 0)
                            sum += f3(t, v, 0);
                    }
                }
            }
        }
    }
    
    cout << sum << endl;
        
    
    
    return 0;
}
