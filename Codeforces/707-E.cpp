//   Author : Misael Mateus 
//   Submission date: 2016-11-18 23:09:12
#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define MAXN 2010
using namespace std;
ll tree[2010][2010];
ll ready(int x, int y){
    ll ans = 0LL;
    while(y > 0LL){
        ans += tree[x][y];
        y -= (y & -y);
    }
    return ans;
}
ll read(int x, int y){
    ll ans = 0LL;
    while(x > 0LL){
        ans += ready(x, y);
        x -= (x & -x);
    }
    
    return ans;
}
void updatey(int x, int y, ll k){
    while(y < MAXN){
        tree[x][y] += k;
        y += (y & -y);
    }
}
void update(int x, int y, ll k){
    while(x < MAXN){
        updatey(x, y, k);
        x += (x & -x);
    }
}
int main(){
    ios::sync_with_stdio( false );
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    
    vector<pair< ii, ll> > group[k];
    
    for(int i = 0; i < k; i++){
        int len;
        scanf("%d", &len);
        for(int j = 0; j < len; j++){
            int x, y;
            int w;
            scanf("%d %d %d", &x, &y, &w);
            group[i].push_back({{x, y}, (ll)(w)});
        }
    }
    
    int q;
    scanf("%d", &q);
    vector< pair< ii, ii > > ask;
    vector< vector<bool> > state;
    
    vector<bool> current(k, 1);
    char s[10];
    
    for(int i = 0; i < q; i++){
        scanf(" %s", &s);
        if(s[0] == 'S'){
            int j;
            scanf("%d", &j);
            if(current[j-1])
                current[j-1] = false;
            else
                current[j-1] = true;
        }
        else{
            ii p1, p2;
            scanf("%d %d %d %d", &p1.first, &p1.second, &p2.first, &p2.second);
            ask.push_back({p1, p2});
            state.push_back(current);
        }
    }
    
    vector<ll> ans(ask.size(), 0LL);
    
    for(int i = 0; i < k; i++){
        for(int j = 0; j < group[i].size(); j++){
            int x = group[i][j].first.first, y = group[i][j].first.second;
            ll w = group[i][j].second;
            
            update(x, y, w);
        }
        
        for(int j = 0; j < ask.size(); j++){
            if(!state[j][i])
                continue;
            int x1 = ask[j].first.first, y1 = ask[j].first.second;
            int x2 = ask[j].second.first, y2 = ask[j].second.second;
            
            ans[j] += read(x2, y2) - read(x1-1, y2) - read(x2, y1-1) + read(x1-1, y1-1);
            
        }
        for(int j = 0; j < group[i].size(); j++){
            int x = group[i][j].first.first, y = group[i][j].first.second;
            ll w = group[i][j].second;
            update(x, y, -w);
        }
    }
    
    
    for(int i = 0; i < ask.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define MAXN 2010
using namespace std;
ll tree[2010][2010];
ll ready(int x, int y){
    ll ans = 0LL;
    while(y > 0LL){
        ans += tree[x][y];
        y -= (y & -y);
    }
    return ans;
}
ll read(int x, int y){
    ll ans = 0LL;
    while(x > 0LL){
        ans += ready(x, y);
        x -= (x & -x);
    }
    
    return ans;
}
void updatey(int x, int y, ll k){
    while(y < MAXN){
        tree[x][y] += k;
        y += (y & -y);
    }
}
void update(int x, int y, ll k){
    while(x < MAXN){
        updatey(x, y, k);
        x += (x & -x);
    }
}
int main(){
    ios::sync_with_stdio( false );
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    
    vector<pair< ii, ll> > group[k];
    
    for(int i = 0; i < k; i++){
        int len;
        scanf("%d", &len);
        for(int j = 0; j < len; j++){
            int x, y;
            int w;
            scanf("%d %d %d", &x, &y, &w);
            group[i].push_back({{x, y}, (ll)(w)});
        }
    }
    
    int q;
    scanf("%d", &q);
    vector< pair< ii, ii > > ask;
    vector< vector<bool> > state;
    
    vector<bool> current(k, 1);
    char s[10];
    
    for(int i = 0; i < q; i++){
        scanf(" %s", &s);
        if(s[0] == 'S'){
            int j;
            scanf("%d", &j);
            if(current[j-1])
                current[j-1] = false;
            else
                current[j-1] = true;
        }
        else{
            ii p1, p2;
            scanf("%d %d %d %d", &p1.first, &p1.second, &p2.first, &p2.second);
            ask.push_back({p1, p2});
            state.push_back(current);
        }
    }
    
    vector<ll> ans(ask.size(), 0LL);
    
    for(int i = 0; i < k; i++){
        for(int j = 0; j < group[i].size(); j++){
            int x = group[i][j].first.first, y = group[i][j].first.second;
            ll w = group[i][j].second;
            
            update(x, y, w);
        }
        
        for(int j = 0; j < ask.size(); j++){
            if(!state[j][i])
                continue;
            int x1 = ask[j].first.first, y1 = ask[j].first.second;
            int x2 = ask[j].second.first, y2 = ask[j].second.second;
            
            ans[j] += read(x2, y2) - read(x1-1, y2) - read(x2, y1-1) + read(x1-1, y1-1);
            
        }
        for(int j = 0; j < group[i].size(); j++){
            int x = group[i][j].first.first, y = group[i][j].first.second;
            ll w = group[i][j].second;
            update(x, y, -w);
        }
    }
    
    
    for(int i = 0; i < ask.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define MAXN 2010
using namespace std;
ll tree[2010][2010];
ll ready(int x, int y){
    ll ans = 0LL;
    while(y > 0LL){
        ans += tree[x][y];
        y -= (y & -y);
    }
    return ans;
}
ll read(int x, int y){
    ll ans = 0LL;
    while(x > 0LL){
        ans += ready(x, y);
        x -= (x & -x);
    }
    
    return ans;
}
void updatey(int x, int y, ll k){
    while(y < MAXN){
        tree[x][y] += k;
        y += (y & -y);
    }
}
void update(int x, int y, ll k){
    while(x < MAXN){
        updatey(x, y, k);
        x += (x & -x);
    }
}
int main(){
    ios::sync_with_stdio( false );
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    
    vector<pair< ii, ll> > group[k];
    
    for(int i = 0; i < k; i++){
        int len;
        scanf("%d", &len);
        for(int j = 0; j < len; j++){
            int x, y;
            int w;
            scanf("%d %d %d", &x, &y, &w);
            group[i].push_back({{x, y}, (ll)(w)});
        }
    }
    
    int q;
    scanf("%d", &q);
    vector< pair< ii, ii > > ask;
    vector< vector<bool> > state;
    
    vector<bool> current(k, 1);
    char s[10];
    
    for(int i = 0; i < q; i++){
        scanf(" %s", &s);
        if(s[0] == 'S'){
            int j;
            scanf("%d", &j);
            if(current[j-1])
                current[j-1] = false;
            else
                current[j-1] = true;
        }
        else{
            ii p1, p2;
            scanf("%d %d %d %d", &p1.first, &p1.second, &p2.first, &p2.second);
            ask.push_back({p1, p2});
            state.push_back(current);
        }
    }
    
    vector<ll> ans(ask.size(), 0LL);
    
    for(int i = 0; i < k; i++){
        for(int j = 0; j < group[i].size(); j++){
            int x = group[i][j].first.first, y = group[i][j].first.second;
            ll w = group[i][j].second;
            
            update(x, y, w);
        }
        
        for(int j = 0; j < ask.size(); j++){
            if(!state[j][i])
                continue;
            int x1 = ask[j].first.first, y1 = ask[j].first.second;
            int x2 = ask[j].second.first, y2 = ask[j].second.second;
            
            ans[j] += read(x2, y2) - read(x1-1, y2) - read(x2, y1-1) + read(x1-1, y1-1);
            
        }
        for(int j = 0; j < group[i].size(); j++){
            int x = group[i][j].first.first, y = group[i][j].first.second;
            ll w = group[i][j].second;
            update(x, y, -w);
        }
    }
    
    
    for(int i = 0; i < ask.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define MAXN 2010
using namespace std;
ll tree[2010][2010];
ll ready(int x, int y){
    ll ans = 0LL;
    while(y > 0LL){
        ans += tree[x][y];
        y -= (y & -y);
    }
    return ans;
}
ll read(int x, int y){
    ll ans = 0LL;
    while(x > 0LL){
        ans += ready(x, y);
        x -= (x & -x);
    }
    
    return ans;
}
void updatey(int x, int y, ll k){
    while(y < MAXN){
        tree[x][y] += k;
        y += (y & -y);
    }
}
void update(int x, int y, ll k){
    while(x < MAXN){
        updatey(x, y, k);
        x += (x & -x);
    }
}
int main(){
    ios::sync_with_stdio( false );
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    
    vector<pair< ii, ll> > group[k];
    
    for(int i = 0; i < k; i++){
        int len;
        scanf("%d", &len);
        for(int j = 0; j < len; j++){
            int x, y;
            int w;
            scanf("%d %d %d", &x, &y, &w);
            group[i].push_back({{x, y}, (ll)(w)});
        }
    }
    
    int q;
    scanf("%d", &q);
    vector< pair< ii, ii > > ask;
    vector< vector<bool> > state;
    
    vector<bool> current(k, 1);
    char s[10];
    
    for(int i = 0; i < q; i++){
        scanf(" %s", &s);
        if(s[0] == 'S'){
            int j;
            scanf("%d", &j);
            if(current[j-1])
                current[j-1] = false;
            else
                current[j-1] = true;
        }
        else{
            ii p1, p2;
            scanf("%d %d %d %d", &p1.first, &p1.second, &p2.first, &p2.second);
            ask.push_back({p1, p2});
            state.push_back(current);
        }
    }
    
    vector<ll> ans(ask.size(), 0LL);
    
    for(int i = 0; i < k; i++){
        for(int j = 0; j < group[i].size(); j++){
            int x = group[i][j].first.first, y = group[i][j].first.second;
            ll w = group[i][j].second;
            
            update(x, y, w);
        }
        
        for(int j = 0; j < ask.size(); j++){
            if(!state[j][i])
                continue;
            int x1 = ask[j].first.first, y1 = ask[j].first.second;
            int x2 = ask[j].second.first, y2 = ask[j].second.second;
            
            ans[j] += read(x2, y2) - read(x1-1, y2) - read(x2, y1-1) + read(x1-1, y1-1);
            
        }
        for(int j = 0; j < group[i].size(); j++){
            int x = group[i][j].first.first, y = group[i][j].first.second;
            ll w = group[i][j].second;
            update(x, y, -w);
        }
    }
    
    
    for(int i = 0; i < ask.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}