#include<bits/stdc++.h>
using namespace std;
/* Maximum Bipartite Matching (Minimum Vertex Cover) on unweighted graph */
#define MAXN 1111
 
int N, M;   // N - # of vertexes on X,  M - # of vertexes on Y
vector< int > gr[MAXN];  // gr[u] -- edges from u in X to v in Y
bool seen[MAXN];        
int m[MAXN], m1[MAXN];   // with whom it's matched
 
int dfs( int u ){
    if( u < 0 ) return 1;
    if( seen[u] ) return 0;
    seen[u] = true;
    for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
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

vector<int> elem[MAXN];
int n, q;


int test(int z){
	N = n*z, M = q;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < z; j++) gr[i*z + j] = elem[i];
	}

	return (bipMatch() == n*z);
}

int ans2(){
	N = n, M = q;
	for(int i = 0; i < n; i++)
		gr[i] = elem[i];
	return bipMatch();
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> q;
	set<int> s;
	for(int i = 0; i < n; i++){
		s.clear();
		int t, x;
		cin >> t;
		while(t--) {
			cin >> x;
			x--;
			s.insert(x);
		}
		for(auto &u : s){
			elem[i].push_back(u);
		}
	}

	int i = 0, j = q / n + 1;
	while(j - i > 1){
		int middle = (i + j) >> 1;
		if(test(middle))
			i = middle;
		else j = middle;
	}

	if(i == 0)
		cout << "NO " << ans2() << endl;
	else cout << "YES " << i << endl;
	return 0;
}