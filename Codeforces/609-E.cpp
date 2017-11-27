//   Author : Misael Mateus 
//   Submission date: 2016-11-03 17:50:33
#include<bits/stdc++.h>

#define MAXN 200100
#define ll long long
#define MAXL 19
using namespace std;
vector<ll> posto, p ;
vector<pair< ll, pair<ll, ll> > >  arestas ;
vector<pair<ll, ll> > gr[MAXN];
ll nivel[MAXN];
ll pai[MAXN];
ll custo[MAXN];
ll ancestral[MAXN][MAXL];
ll max_weight[MAXN][MAXL];

void bfs(){
    memset(pai, -1, sizeof(pai));
    pai[1] = 0;
    custo[1] = 0LL;
    queue<ll> q;
    q.push(1);
    
    while(!q.empty()){
        ll atual = q.front();
        q.pop();
        for(ll i = 0; i < gr[atual].size(); i++){
            if(pai[gr[atual][i].second] == -1)
                pai[gr[atual][i].second] = atual, custo[gr[atual][i].second] = gr[atual][i].first, q.push(gr[atual][i].second), nivel[gr[atual][i].second] = nivel[atual] + 1;
        }
    }
}


ll lca(ll a, ll b){
    if(nivel[a] < nivel[b])
        swap( a, b ) ;
    for(ll i = MAXL-1 ; i >= 0 ; i--)
        if( nivel[a] - (1 << i) >= nivel[b] )
            a = ancestral[a][i] ;
    if( a == b )
        return b ;
    for ( ll i = MAXL-1 ; i >= 0 ; i-- ){
        if( ancestral[a][i] != -1 && ancestral[a][i] != ancestral[b][i] )
            a = ancestral[a][i], b = ancestral[b][i] ;
    }
    return ancestral[a][0] ;
}
 
ll m ;
ll find( ll x ) 
{
    if ( p[x] != x ) 
        p[x] = find( p[x] );
    return p[x];
}
 
bool unio( ll a, ll b ) 
{
    
    a = find(a) ;
    b = find(b) ;
    if ( a == b ) 
        return false ;
     
    if ( posto[a] >= posto[b] ) 
    {
        p[b] = a ;
        if (posto[a] == posto[b]) 
            posto[a]++ ;
    }
    else
        p[a] = b ;
    return true ;
}
ll  kruskal() 
{
    sort( arestas.begin() , arestas.end() ) ;
    ll resp = 0LL;
    for ( ll i = 0 ; i < m; i++ )
    {
        if ( unio( arestas[i].second.first, arestas[i].second.second ) ) 
            gr[arestas[i].second.first].push_back({arestas[i].first, arestas[i].second.second}),
            gr[arestas[i].second.second].push_back({arestas[i].first, arestas[i].second.first}),
            resp += arestas[i].first;
    }
    
    return resp;
}
int main()
{
    ios::sync_with_stdio( false );
    ll n;
    cin >> n >> m;
    posto = vector<ll> (n+1, 0 ) ;
    p = vector<ll> (n+1) ;
    arestas = vector<pair< ll, pair<ll, ll> > > (m) ;
    vector<pair< ll, pair<ll, ll> > >  arestas1 ;
    for ( ll i = 1; i <= n ; i++ )
        p[i] = i ;
        
    for(ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        arestas[i] = {c, {a, b} };
    }
    arestas1 = arestas;
    nivel[1] = 0;
    ll resp = kruskal();
    bfs();
    
    memset(ancestral, -1, sizeof(ancestral));
    memset(max_weight, -1, sizeof(max_weight));
    for (ll i = 1; i <= n ; ++i)
        ancestral[i][0] = pai[i] ;
 
    for (ll j = 1 ; j < MAXL ; j++)
        for (ll i = 1 ; i <= n ; ++i)
            if( ancestral[i][j-1] != -1 && ancestral[ancestral[i][j-1]][j-1] != -1)
                ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1] ;
                
    for(ll i = 1; i <= n; i++)
        max_weight[i][0] = custo[i];
    for (ll j = 1 ; j < MAXL ; j++)
        for (ll i = 1 ; i <= n ; ++i)
            if( ancestral[i][j-1] != -1 && ancestral[ancestral[i][j-1]][j-1] != -1 )
                max_weight[i][j] = max(max_weight[i][j-1], max_weight[ancestral[i][j-1]][j-1]) ;
    
    
    for(ll i = 0; i < m; i++){
        ll x = arestas1[i].second.first;
        ll y = arestas1[i].second.second;
        ll c = arestas1[i].first;
        
        ll u = lca(x, y);
        
        ll ans = 0LL;
        
        for(ll j = MAXL - 1; j >= 0; j--)
            if(nivel[x] - (1 << j) >= nivel[u])
                ans = max(ans, max_weight[x][j]), x = ancestral[x][j];
        
        for(ll j = MAXL - 1; j >= 0; j--)
            if(nivel[y] - (1 << j) >= nivel[u])
                ans = max(ans, max_weight[y][j]), y = ancestral[y][j];
        
        cout <<  resp -ans + c << endl;
    }
    

} 