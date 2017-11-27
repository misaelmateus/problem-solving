//   Author : Misael Mateus 
//   Submission date: 2016-11-17 15:16:35
#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define MAXN 100100
using namespace std;

vector< ii > gr[MAXN];

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int u, v;
        ll l;
        cin >> u >> v >> l;
        u--; v--;
        gr[u].push_back({l, v});
        gr[v].push_back({l, u});
    }
    vector<int> is(n, 0);
    
    for(int i = 0; i < k; i++){
        int aux;
        cin >> aux;
        aux--;
        is[aux] = 1;
    }
    ll men = 1000010000;    
    for(int i = 0; i < n; i++){
        if(is[i])
            continue;
        
        for(int j = 0; j < gr[i].size(); j++)
            if(is[gr[i][j].second])
                men = min(men, gr[i][j].first);
    }
    
    if(k == n || men == 1000010000 )
        cout << -1 << endl;
    else
        cout << men << endl;
    
    return 0;
}#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define MAXN 100100
using namespace std;

vector< ii > gr[MAXN];

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int u, v;
        ll l;
        cin >> u >> v >> l;
        u--; v--;
        gr[u].push_back({l, v});
        gr[v].push_back({l, u});
    }
    vector<int> is(n, 0);
    
    for(int i = 0; i < k; i++){
        int aux;
        cin >> aux;
        aux--;
        is[aux] = 1;
    }
    ll men = 1000010000;    
    for(int i = 0; i < n; i++){
        if(is[i])
            continue;
        
        for(int j = 0; j < gr[i].size(); j++)
            if(is[gr[i][j].second])
                men = min(men, gr[i][j].first);
    }
    
    if(k == n || men == 1000010000 )
        cout << -1 << endl;
    else
        cout << men << endl;
    
    return 0;
}#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define MAXN 100100
using namespace std;

vector< ii > gr[MAXN];

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int u, v;
        ll l;
        cin >> u >> v >> l;
        u--; v--;
        gr[u].push_back({l, v});
        gr[v].push_back({l, u});
    }
    vector<int> is(n, 0);
    
    for(int i = 0; i < k; i++){
        int aux;
        cin >> aux;
        aux--;
        is[aux] = 1;
    }
    ll men = 1000010000;    
    for(int i = 0; i < n; i++){
        if(is[i])
            continue;
        
        for(int j = 0; j < gr[i].size(); j++)
            if(is[gr[i][j].second])
                men = min(men, gr[i][j].first);
    }
    
    if(k == n || men == 1000010000 )
        cout << -1 << endl;
    else
        cout << men << endl;
    
    return 0;
}#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define MAXN 100100
using namespace std;

vector< ii > gr[MAXN];

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int u, v;
        ll l;
        cin >> u >> v >> l;
        u--; v--;
        gr[u].push_back({l, v});
        gr[v].push_back({l, u});
    }
    vector<int> is(n, 0);
    
    for(int i = 0; i < k; i++){
        int aux;
        cin >> aux;
        aux--;
        is[aux] = 1;
    }
    ll men = 1000010000;    
    for(int i = 0; i < n; i++){
        if(is[i])
            continue;
        
        for(int j = 0; j < gr[i].size(); j++)
            if(is[gr[i][j].second])
                men = min(men, gr[i][j].first);
    }
    
    if(k == n || men == 1000010000 )
        cout << -1 << endl;
    else
        cout << men << endl;
    
    return 0;
}