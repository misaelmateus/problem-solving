//   Author : Misael Mateus 
//   Submission date: 2016-08-04 21:51:52
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    ll c[n];
    int v[k], is[n];
    memset(is, 0, sizeof(is));
    ll sum = 0LL, sum2 = 0LL, S = 0LL, resp = 0LL;
    for(int i = 0; i < n; i++){
        cin >> c[i];
        sum += c[i];
    }
    for(int i = 0; i < k; i++){
        cin >> v[i];
        v[i]--;
        is[v[i]] = 1;
        sum2 += c[v[i]];
    }
    
    for(int i = 0; i < n-1; i++){
        if(!is[i] && !is[i+1])
            S += c[i] * c[i+1];
    }
    if(!is[0] && !is[n-1])
        S += c[0] * c[n-1];
    resp += S;
    ll resp2 = 0LL;
    for(int i = 0; i < k; i++){
        resp += c[v[i]]*sum;
        resp2 += (c[v[i]]*(sum2 + c[v[i]]));
    }
    resp -= resp2 / 2LL;
    cout << resp << endl;
    
}