//   Author : Misael Mateus 
//   Submission date: 2017-03-18 22:40:22
#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
 
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
 
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
 
#define PB push_back
#define MP make_pair

#define MAXN 200100 
template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }
 
const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }
 
typedef long long ll;
typedef unsigned long long ull;
 
using namespace std;

ll r[MAXN][6];
ll R[MAXN][6];
vector<int> gr[MAXN];
int n, k;
int p[MAXN];
int mark[MAXN];
ll cont[MAXN];
ll dist[MAXN];
queue<int> q;
stack<int> q1;
ll f(int i, int j){
	if(j <= 0){
	    if(j + k > 0)
	        return (ll)cont[i] + r[i][j+k];
	    else 
	        return (ll)cont[i]*2LL + r[i][j+2*k];
		
	}
	return r[i][j];
}
ll f1(int i, int j){
	if(j <= 0)
		return n-2LL + R[i][j + k];
	return R[i][j];
}

ll dfs(int u){
	for(int i = 0; i < gr[u].size(); i++){
		int next = gr[u][i];
		if(p[u] != next){
			dist[next] = 1LL + dist[u];
			p[next] = u;
			cont[u] += 1LL + dfs(next);
		}
	}
	q.push(u);
	q1.push(u);
	return cont[u];
}

int main( ){
    
    scanf("%d %d", &n, &k);
	int a, b;
    for(int i = 0; i < n-1; i++){
    	scanf("%d %d", &a, &b);
    	gr[a].push_back(b);
    	gr[b].push_back(a);
    }
    p[1] = -1;
    dfs(1);

    
    while(!q.empty()){
    	int now = q.front();
    	q.pop();

    	for(int i = 0; i < gr[now].size(); i++){
    		int child = gr[now][i];
    		if(child != p[now]){
    			for(int j = 1; j <= k; j++){
    				r[now][j] += f(child, j-1) + 1;
    			}
    		}
    	}
   
    }


    ll ans = 0LL;
    while(!q1.empty()){
    	int i = q1.top();
    	q1.pop();
	    for(int j = 1; j <= k; j++){
	    	R[i][j] = r[i][j];
	    	if(p[i] != -1){
	    		R[i][j] += f1(p[i], j-1) - f(i, j-2);
    		}
    	}
    	
    	ans += (ll)R[i][k];
    }
    
    ans /= 2LL;
    printf("%lld\n", ans);
    return 0;
}