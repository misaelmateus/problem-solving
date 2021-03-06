//   Author : Misael Mateus 
//   Submission date: 2017-03-23 20:20:46
#include<bits/stdc++.h>
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
 
template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }
 
const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }
 
typedef long long int64;
typedef unsigned long long uint64;
 
using namespace std;
 
int main( int argc, char* argv[] ){
     
    ios::sync_with_stdio( false );
    int n, m;
    cin >> n >> m;
    int cont = 0;
    for(int i = 0; i < m; i++){
    	int flag = 1;
    	map<int, bool> mapa;
    	int t;
    	cin >> t;
    	while(t--)
    	{
    		int a;
    		cin >> a;
    		if(mapa[-a]){
    			flag = 0;
    		}
    		mapa[a] = 1;
    	}
    	cont += flag;
    }

    if(cont == 0)
    	cout << "NO" << "\n";
    else cout << "YES" << "\n";
    return 0;
}