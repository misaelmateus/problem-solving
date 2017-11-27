//   Author : Misael Mateus 
//   Submission date: 2017-02-20 22:18:37
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)

#define PB push_back
#define MP make_pair

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }


using namespace std;
int main(){
	ios::sync_with_stdio( false );

	int n;
	cin >> n;
	map<int, int> mapa;
	FOR(i, 1, n){
		int aux;
		cin >> aux;
		mapa[aux]++;
	}
	auto it = mapa.begin();
	int resp = 0;
	for(it++; it != mapa.end(); it++){
		resp += it->second;
	}
	it = mapa.end();
	it--;
	if(it != mapa.begin())
		resp -= it->second;
	cout << resp << endl;
}#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)

#define PB push_back
#define MP make_pair

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }


using namespace std;
int main(){
	ios::sync_with_stdio( false );

	int n;
	cin >> n;
	map<int, int> mapa;
	FOR(i, 1, n){
		int aux;
		cin >> aux;
		mapa[aux]++;
	}
	auto it = mapa.begin();
	int resp = 0;
	for(it++; it != mapa.end(); it++){
		resp += it->second;
	}
	it = mapa.end();
	it--;
	if(it != mapa.begin())
		resp -= it->second;
	cout << resp << endl;
}#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)

#define PB push_back
#define MP make_pair

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }


using namespace std;
int main(){
	ios::sync_with_stdio( false );

	int n;
	cin >> n;
	map<int, int> mapa;
	FOR(i, 1, n){
		int aux;
		cin >> aux;
		mapa[aux]++;
	}
	auto it = mapa.begin();
	int resp = 0;
	for(it++; it != mapa.end(); it++){
		resp += it->second;
	}
	it = mapa.end();
	it--;
	if(it != mapa.begin())
		resp -= it->second;
	cout << resp << endl;
}#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)

#define PB push_back
#define MP make_pair

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }


using namespace std;
int main(){
	ios::sync_with_stdio( false );

	int n;
	cin >> n;
	map<int, int> mapa;
	FOR(i, 1, n){
		int aux;
		cin >> aux;
		mapa[aux]++;
	}
	auto it = mapa.begin();
	int resp = 0;
	for(it++; it != mapa.end(); it++){
		resp += it->second;
	}
	it = mapa.end();
	it--;
	if(it != mapa.begin())
		resp -= it->second;
	cout << resp << endl;
}