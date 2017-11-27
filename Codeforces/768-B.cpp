//   Author : Misael Mateus 
//   Submission date: 2017-02-20 22:24:31
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

vector<ll> pos;
vector<ll> s1;

ll ini(ll n){
	ll ult = 1LL;
	
	while(n > 1 ){
		ult = ult*2LL + 1LL;
		n /= 2LL;
	}
	return ult;

}

ll sum(ll p, ll ini, ll fim, ll i, ll j){	
	
	if(i >= ini && j <= fim)
		return p;
	if(i > fim || j < ini)
		return 0LL;
	ll middle = (i + j) >> 1;
	
	return (int)(middle >= ini && middle <= fim) * (p % 2LL) + sum(p/2LL, ini, fim, i, middle-1) + sum(p/2LL, ini, fim, middle + 1, j);
	
}
int main(){
	ios::sync_with_stdio( false );
	ll n, l , r;
	cin >> n >> l >> r;
	ll tam = ini(n);
	cout << sum(n, l, r, 1LL, tam) << endl;
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

vector<ll> pos;
vector<ll> s1;

ll ini(ll n){
	ll ult = 1LL;
	
	while(n > 1 ){
		ult = ult*2LL + 1LL;
		n /= 2LL;
	}
	return ult;

}

ll sum(ll p, ll ini, ll fim, ll i, ll j){	
	
	if(i >= ini && j <= fim)
		return p;
	if(i > fim || j < ini)
		return 0LL;
	ll middle = (i + j) >> 1;
	
	return (int)(middle >= ini && middle <= fim) * (p % 2LL) + sum(p/2LL, ini, fim, i, middle-1) + sum(p/2LL, ini, fim, middle + 1, j);
	
}
int main(){
	ios::sync_with_stdio( false );
	ll n, l , r;
	cin >> n >> l >> r;
	ll tam = ini(n);
	cout << sum(n, l, r, 1LL, tam) << endl;
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

vector<ll> pos;
vector<ll> s1;

ll ini(ll n){
	ll ult = 1LL;
	
	while(n > 1 ){
		ult = ult*2LL + 1LL;
		n /= 2LL;
	}
	return ult;

}

ll sum(ll p, ll ini, ll fim, ll i, ll j){	
	
	if(i >= ini && j <= fim)
		return p;
	if(i > fim || j < ini)
		return 0LL;
	ll middle = (i + j) >> 1;
	
	return (int)(middle >= ini && middle <= fim) * (p % 2LL) + sum(p/2LL, ini, fim, i, middle-1) + sum(p/2LL, ini, fim, middle + 1, j);
	
}
int main(){
	ios::sync_with_stdio( false );
	ll n, l , r;
	cin >> n >> l >> r;
	ll tam = ini(n);
	cout << sum(n, l, r, 1LL, tam) << endl;
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

vector<ll> pos;
vector<ll> s1;

ll ini(ll n){
	ll ult = 1LL;
	
	while(n > 1 ){
		ult = ult*2LL + 1LL;
		n /= 2LL;
	}
	return ult;

}

ll sum(ll p, ll ini, ll fim, ll i, ll j){	
	
	if(i >= ini && j <= fim)
		return p;
	if(i > fim || j < ini)
		return 0LL;
	ll middle = (i + j) >> 1;
	
	return (int)(middle >= ini && middle <= fim) * (p % 2LL) + sum(p/2LL, ini, fim, i, middle-1) + sum(p/2LL, ini, fim, middle + 1, j);
	
}
int main(){
	ios::sync_with_stdio( false );
	ll n, l , r;
	cin >> n >> l >> r;
	ll tam = ini(n);
	cout << sum(n, l, r, 1LL, tam) << endl;
}