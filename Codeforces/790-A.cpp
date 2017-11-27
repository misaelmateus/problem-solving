//   Author : Misael Mateus 
//   Submission date: 2017-03-18 20:54:53
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
int v[100];
bool flag[100];
vector<string> names;

void generate(string s){
	if(names.size() > 70)
		return ;
	for(char c = 'a'; c <= 'z'; c++){
		names.push_back(s + c);
	}
	for(char c = 'a'; c <= 'z'; c++){
		generate(s + c);
	}
}
int main( ){
    ios::sync_with_stdio( false );
    int n, k;
    cin >> n >> k;
    string aux;
    int cont = 1;
    for(int i = 1; i <= k-1; i++)
    	v[i] = cont++;
    for(int i = 1; i <= n - k + 1; i++){
    	string s;
    	cin >> s;
    	if(s == "NO")
    		v[i+k-1] = v[i];
    	else
    		v[i+k-1] = cont++;
    }
    generate("");
    for(int i = 1; i <= n; i++){
    	string s = names[v[i]];
    	s[0] = (char)((int)(s[0] - 'a' + 'A'));
    	cout << s << " ";
    }
    return 0;
}#include <bits/stdc++.h>
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
 
typedef long long ll;
typedef unsigned long long ull;
 
using namespace std;
int v[100];
bool flag[100];
vector<string> names;

void generate(string s){
	if(names.size() > 70)
		return ;
	for(char c = 'a'; c <= 'z'; c++){
		names.push_back(s + c);
	}
	for(char c = 'a'; c <= 'z'; c++){
		generate(s + c);
	}
}
int main( ){
    ios::sync_with_stdio( false );
    int n, k;
    cin >> n >> k;
    string aux;
    int cont = 1;
    for(int i = 1; i <= k-1; i++)
    	v[i] = cont++;
    for(int i = 1; i <= n - k + 1; i++){
    	string s;
    	cin >> s;
    	if(s == "NO")
    		v[i+k-1] = v[i];
    	else
    		v[i+k-1] = cont++;
    }
    generate("");
    for(int i = 1; i <= n; i++){
    	string s = names[v[i]];
    	s[0] = (char)((int)(s[0] - 'a' + 'A'));
    	cout << s << " ";
    }
    return 0;
}#include <bits/stdc++.h>
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
 
typedef long long ll;
typedef unsigned long long ull;
 
using namespace std;
int v[100];
bool flag[100];
vector<string> names;

void generate(string s){
	if(names.size() > 70)
		return ;
	for(char c = 'a'; c <= 'z'; c++){
		names.push_back(s + c);
	}
	for(char c = 'a'; c <= 'z'; c++){
		generate(s + c);
	}
}
int main( ){
    ios::sync_with_stdio( false );
    int n, k;
    cin >> n >> k;
    string aux;
    int cont = 1;
    for(int i = 1; i <= k-1; i++)
    	v[i] = cont++;
    for(int i = 1; i <= n - k + 1; i++){
    	string s;
    	cin >> s;
    	if(s == "NO")
    		v[i+k-1] = v[i];
    	else
    		v[i+k-1] = cont++;
    }
    generate("");
    for(int i = 1; i <= n; i++){
    	string s = names[v[i]];
    	s[0] = (char)((int)(s[0] - 'a' + 'A'));
    	cout << s << " ";
    }
    return 0;
}#include <bits/stdc++.h>
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
 
typedef long long ll;
typedef unsigned long long ull;
 
using namespace std;
int v[100];
bool flag[100];
vector<string> names;

void generate(string s){
	if(names.size() > 70)
		return ;
	for(char c = 'a'; c <= 'z'; c++){
		names.push_back(s + c);
	}
	for(char c = 'a'; c <= 'z'; c++){
		generate(s + c);
	}
}
int main( ){
    ios::sync_with_stdio( false );
    int n, k;
    cin >> n >> k;
    string aux;
    int cont = 1;
    for(int i = 1; i <= k-1; i++)
    	v[i] = cont++;
    for(int i = 1; i <= n - k + 1; i++){
    	string s;
    	cin >> s;
    	if(s == "NO")
    		v[i+k-1] = v[i];
    	else
    		v[i+k-1] = cont++;
    }
    generate("");
    for(int i = 1; i <= n; i++){
    	string s = names[v[i]];
    	s[0] = (char)((int)(s[0] - 'a' + 'A'));
    	cout << s << " ";
    }
    return 0;
}