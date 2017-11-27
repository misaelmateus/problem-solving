//   Author : Misael Mateus 
//   Submission date: 2016-10-27 17:59:01
#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
using namespace std;

bool cmp(ii a, ii b){ return a.first > b.first; }
int main(){
    int n;
    cin >> n;
    ll t, w;
    ii p[n-1];
    cin >> t >> w;
    for(int i = 0; i < n-1; i++)
        cin >> p[i].first >> p[i].second;
    sort(p, p+n-1, cmp);
    int i = 0;
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    for(; i < n-1 && p[i].first > t; i++){
            pq.push(p[i].second - p[i].first + 1LL);
    }
    int men = i;
    int cont = 0;
    while(!pq.empty()){
        ll resp = pq.top();
        pq.pop();
        if(t < resp)
            continue;
        t -= resp;
        cont++;
        for(; i < n-1 && p[i].first > t; i++)
            pq.push(p[i].second - p[i].first + 1LL);
        men = min(men, i - cont);
    }
    
    cout << men + 1 << endl;
    
}