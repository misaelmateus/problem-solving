#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
using namespace std;
vector<ll> posto, pai ;
vector<pair< ll, pair<ll, ll> > >  arestas ;
vector<ll> gr[MAXN];

ll m ;
ll find( ll x ) 
{
    if ( pai[x] != x ) 
        pai[x] = find( pai[x] );
    return pai[x];
}
 
bool unio( ll a, ll b ) 
{
    a = find(a) ;
    b = find(b) ;
    if ( a == b ) 
        return false ;
     
    if ( posto[a] >= posto[b] ) 
    {
        pai[b] = a ;
        if (posto[a] == posto[b]) 
            posto[a]++ ;
    }
    else
        pai[a] = b ;
    return true ;
}
ll  kruskal() 
{
    ll p = 0LL ;
    sort( arestas.begin() , arestas.end() ) ;
    for ( ll i = 0 ; i < m; i++ )
    {
        if ( unio( arestas[i].second.first, arestas[i].second.second ) ){
            gr[arestas[i].second.first].push_back(arestas[i].second.second);
            gr[arestas[i].second.second].push_back(arestas[i].second.first);
            
            p += arestas[i].first ;
        }
    }
    return p ;
}

int mark[MAXN];

void dfs(int u, int p){
    mark[u] = 1;
    for(int i = 0; i < gr[u].size(); i++){
        if(gr[u][i] != p && !mark[gr[u][i]])
            dfs(gr[u][i], u);
    }
}
int main()
{
    ll q;
    cin >> q;
    while(q--){
        ll n, croad, clib;
        cin >> n >> m >> clib >> croad;
        memset(mark, 0, sizeof(mark));
        for(int i = 0; i <= n; i++) gr[i].clear();
        posto = vector<ll> (n+1, 0 ) ;
        pai = vector<ll> (n+1) ;
        arestas = vector<pair< ll, pair<ll, ll> > > (m) ;
        for ( ll i = 0; i <= n ; i++ )
            pai[i] = i ;
        
        for(ll i = 0; i < m; i++){
            ll a, b;
            cin >> a >> b;
            arestas[i] = {croad, {a, b} };
        }
        
        if(croad > clib)
            cout << clib*n << endl;
        else{
            ll ans = kruskal();
            
            for(int i = 1; i <= n; i++)
                if(!mark[i])
                {
                    dfs(i, -1);
                    ans += clib;
                }
            cout << ans << endl;
        }
    }
}