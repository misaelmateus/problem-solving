//   Author : Misael Mateus 
//   Submission date: 2016-11-23 22:06:15
#include<bits/stdc++.h>
#define ll long long
#define MAXN 200010
using namespace std;
vector< pair<int, ll> > gr[MAXN];
vector< ll > v;
vector< ll> ans1;
vector<ll> ans;
int dfs2(int i){
    ll a = 0;
    for(int j = 0; j < gr[i].size(); j++){
        a += dfs2(gr[i][j].first); 
    }
    ans[i] = a;
    a += ans1[i];
    return a;
}
void dfs(int i, vector<ll>& dist, vector<int>& b, ll cur){
    dist.push_back(cur);
    b.push_back(i);
    
    vector<ll>::iterator it = lower_bound(dist.begin(), dist.end(), cur-v[i]);
    int l = (int)(it - dist.begin());
    ans1[b[l]]--;
    ans1[i]++;
    for(int j = 0; j < gr[i].size(); j++){
        dfs(gr[i][j].first, dist, b, cur+gr[i][j].second);
    }
    
    b.pop_back();
    dist.pop_back();
}
int main(){
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    v = vector<ll>(n+1);
    ans1 = vector<ll>(n+1, 0LL);
    ans = vector<ll>(n+1, 0LL);
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    
    for(int i = 1; i <= n-1; i++){
        int a;
        ll b;
        cin >> a >> b;
        gr[a].push_back({i+1, b});
    }
    vector<ll> dist;
    vector<int> b;
    dfs(1, dist, b, 0LL);
    dfs2(1);
    
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}#include<bits/stdc++.h>
#define ll long long
#define MAXN 200010
using namespace std;
vector< pair<int, ll> > gr[MAXN];
vector< ll > v;
vector< ll> ans1;
vector<ll> ans;
int dfs2(int i){
    ll a = 0;
    for(int j = 0; j < gr[i].size(); j++){
        a += dfs2(gr[i][j].first); 
    }
    ans[i] = a;
    a += ans1[i];
    return a;
}
void dfs(int i, vector<ll>& dist, vector<int>& b, ll cur){
    dist.push_back(cur);
    b.push_back(i);
    
    vector<ll>::iterator it = lower_bound(dist.begin(), dist.end(), cur-v[i]);
    int l = (int)(it - dist.begin());
    ans1[b[l]]--;
    ans1[i]++;
    for(int j = 0; j < gr[i].size(); j++){
        dfs(gr[i][j].first, dist, b, cur+gr[i][j].second);
    }
    
    b.pop_back();
    dist.pop_back();
}
int main(){
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    v = vector<ll>(n+1);
    ans1 = vector<ll>(n+1, 0LL);
    ans = vector<ll>(n+1, 0LL);
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    
    for(int i = 1; i <= n-1; i++){
        int a;
        ll b;
        cin >> a >> b;
        gr[a].push_back({i+1, b});
    }
    vector<ll> dist;
    vector<int> b;
    dfs(1, dist, b, 0LL);
    dfs2(1);
    
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}#include<bits/stdc++.h>
#define ll long long
#define MAXN 200010
using namespace std;
vector< pair<int, ll> > gr[MAXN];
vector< ll > v;
vector< ll> ans1;
vector<ll> ans;
int dfs2(int i){
    ll a = 0;
    for(int j = 0; j < gr[i].size(); j++){
        a += dfs2(gr[i][j].first); 
    }
    ans[i] = a;
    a += ans1[i];
    return a;
}
void dfs(int i, vector<ll>& dist, vector<int>& b, ll cur){
    dist.push_back(cur);
    b.push_back(i);
    
    vector<ll>::iterator it = lower_bound(dist.begin(), dist.end(), cur-v[i]);
    int l = (int)(it - dist.begin());
    ans1[b[l]]--;
    ans1[i]++;
    for(int j = 0; j < gr[i].size(); j++){
        dfs(gr[i][j].first, dist, b, cur+gr[i][j].second);
    }
    
    b.pop_back();
    dist.pop_back();
}
int main(){
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    v = vector<ll>(n+1);
    ans1 = vector<ll>(n+1, 0LL);
    ans = vector<ll>(n+1, 0LL);
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    
    for(int i = 1; i <= n-1; i++){
        int a;
        ll b;
        cin >> a >> b;
        gr[a].push_back({i+1, b});
    }
    vector<ll> dist;
    vector<int> b;
    dfs(1, dist, b, 0LL);
    dfs2(1);
    
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}#include<bits/stdc++.h>
#define ll long long
#define MAXN 200010
using namespace std;
vector< pair<int, ll> > gr[MAXN];
vector< ll > v;
vector< ll> ans1;
vector<ll> ans;
int dfs2(int i){
    ll a = 0;
    for(int j = 0; j < gr[i].size(); j++){
        a += dfs2(gr[i][j].first); 
    }
    ans[i] = a;
    a += ans1[i];
    return a;
}
void dfs(int i, vector<ll>& dist, vector<int>& b, ll cur){
    dist.push_back(cur);
    b.push_back(i);
    
    vector<ll>::iterator it = lower_bound(dist.begin(), dist.end(), cur-v[i]);
    int l = (int)(it - dist.begin());
    ans1[b[l]]--;
    ans1[i]++;
    for(int j = 0; j < gr[i].size(); j++){
        dfs(gr[i][j].first, dist, b, cur+gr[i][j].second);
    }
    
    b.pop_back();
    dist.pop_back();
}
int main(){
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    v = vector<ll>(n+1);
    ans1 = vector<ll>(n+1, 0LL);
    ans = vector<ll>(n+1, 0LL);
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    
    for(int i = 1; i <= n-1; i++){
        int a;
        ll b;
        cin >> a >> b;
        gr[a].push_back({i+1, b});
    }
    vector<ll> dist;
    vector<int> b;
    dfs(1, dist, b, 0LL);
    dfs2(1);
    
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}