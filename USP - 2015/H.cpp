#include<bits/stdc++.h>
#define MAXN 1110
using namespace std;

int N, M;   // N - # of vertexes on X,  M - # of vertexes on Y
vector< int > gr[MAXN];  // gr[u] -- edges from u in X to v in Y
bool seen[MAXN];        
int m[MAXN], m1[MAXN];   // with whom it's matched
 
int dfs( int u ){
    if( u < 0 ) return 1;
    if( seen[u] ) return 0;
    seen[u] = true;
    for( int i = 0, sz = gr[u].size(); i < sz; i++ ){
        if( dfs( m1[ gr[u][i] ] ) ){
            m[u] = gr[u][i];
            m1[ gr[u][i] ] = u;
            return 1;
        }
    }
    return 0;
}
 
int dfsExp( int u ){
    for( int i = 0; i < N; i++ ) seen[i] = false;
    return dfs( u );
}
 
int bipMatch(){
    for( int i = 0; i < N; i++ ) m[i] = -1;
    for( int i = 0; i < M; i++ ) m1[i] = -1;
    int aug, ans = 0;
    do{
        aug = 0;
        bool first = true;
        for( int i = 0; i < N; i++ ) if( m[i] < 0 ){
            if( first ) aug += dfsExp( i );
            else aug += dfs( i );
            first = false;
        }
        ans += aug;
    } while( aug );
    return ans;
}
 
vector<int> gr1[MAXN];
int mark[MAXN];

int dfs(int i, int p){
	mark[i] = p+1;
	for(int j = 0; j < gr1[i].size(); j++){
		int u = gr1[i][j];
		if(!mark[u]){
			dfs(u, p^1);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);	
	int T;
	cin >> T;
	while(T--){
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < n; i++) gr[i].clear(), gr1[i].clear(), mark[i] = 0;
		N = n, M = n;
		for(int i = 0; i < m; i++){
			int a, b;
			cin >> a >> b;
			a--, b--;
			gr1[a].push_back(b);
			gr1[b].push_back(a);
		}
		dfs(0, 0);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < gr1[i].size(); j++){
				int u = gr1[i][j];
				int a = i, b = u;
				if(mark[a] != 1) swap(a, b);
				gr[a].push_back(b);
			}
		int ans = bipMatch();
		ans = ans + (n - 2*ans);
		cout << ans << endl;
	}

	return 0;
}