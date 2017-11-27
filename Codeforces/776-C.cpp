//   Author : Misael Mateus 
//   Submission date: 2017-02-23 20:35:23
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

#define MAX 1000000000000000LL
const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }


using namespace std;
int main(){
	ios::sync_with_stdio( false );
	map<ll, ll> cont;
	ll n;
	ll k;
	cin >> n >> k;
	
	cont[0] = 1LL;
	ll ans = 0LL;
	vector<ll> v;

	v.push_back(1LL);
	if(k == -1)
		v.push_back(-1LL);
	ll aux = k;
	if(k != 1LL && k != -1LL)
		while(aux < MAX && aux > -MAX){
			v.push_back(aux);
			aux *= k;
		}
	ll sum = 0LL;
	for(int i = 0; i < n; i++){
		ll num;
		cin >> num;
		sum += num;
		for(int j = 0; j < v.size(); j++){
			ans += cont[sum - v[j]];
		}
		cont[sum]++;
	}

	cout << ans << endl;

	return 0;
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

#define MAX 1000000000000000LL
const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }


using namespace std;
int main(){
	ios::sync_with_stdio( false );
	map<ll, ll> cont;
	ll n;
	ll k;
	cin >> n >> k;
	
	cont[0] = 1LL;
	ll ans = 0LL;
	vector<ll> v;

	v.push_back(1LL);
	if(k == -1)
		v.push_back(-1LL);
	ll aux = k;
	if(k != 1LL && k != -1LL)
		while(aux < MAX && aux > -MAX){
			v.push_back(aux);
			aux *= k;
		}
	ll sum = 0LL;
	for(int i = 0; i < n; i++){
		ll num;
		cin >> num;
		sum += num;
		for(int j = 0; j < v.size(); j++){
			ans += cont[sum - v[j]];
		}
		cont[sum]++;
	}

	cout << ans << endl;

	return 0;
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

#define MAX 1000000000000000LL
const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }


using namespace std;
int main(){
	ios::sync_with_stdio( false );
	map<ll, ll> cont;
	ll n;
	ll k;
	cin >> n >> k;
	
	cont[0] = 1LL;
	ll ans = 0LL;
	vector<ll> v;

	v.push_back(1LL);
	if(k == -1)
		v.push_back(-1LL);
	ll aux = k;
	if(k != 1LL && k != -1LL)
		while(aux < MAX && aux > -MAX){
			v.push_back(aux);
			aux *= k;
		}
	ll sum = 0LL;
	for(int i = 0; i < n; i++){
		ll num;
		cin >> num;
		sum += num;
		for(int j = 0; j < v.size(); j++){
			ans += cont[sum - v[j]];
		}
		cont[sum]++;
	}

	cout << ans << endl;

	return 0;
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

#define MAX 1000000000000000LL
const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }


using namespace std;
int main(){
	ios::sync_with_stdio( false );
	map<ll, ll> cont;
	ll n;
	ll k;
	cin >> n >> k;
	
	cont[0] = 1LL;
	ll ans = 0LL;
	vector<ll> v;

	v.push_back(1LL);
	if(k == -1)
		v.push_back(-1LL);
	ll aux = k;
	if(k != 1LL && k != -1LL)
		while(aux < MAX && aux > -MAX){
			v.push_back(aux);
			aux *= k;
		}
	ll sum = 0LL;
	for(int i = 0; i < n; i++){
		ll num;
		cin >> num;
		sum += num;
		for(int j = 0; j < v.size(); j++){
			ans += cont[sum - v[j]];
		}
		cont[sum]++;
	}

	cout << ans << endl;

	return 0;
}