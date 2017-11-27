//   Author : Misael Mateus 
//   Submission date: 2017-02-23 20:32:05
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
#define MAXN 100010
const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

int prime[MAXN];


using namespace std;
int main(){
	ios::sync_with_stdio( false );

	int n;
	cin >> n;
	if(n == 1){
		cout << 1 << "\n";
		cout << 1 << "\n";
		return 0;
	}
	if(n == 2){
		cout << 1 << "\n";
		cout << "1 1" << "\n";
		return 0;
	}
	for(int i = 2; i < MAXN; i++){
		if(prime[i])
			continue;
		for(int j = 2*i; j < MAXN; j += i)
			prime[j] = 1;
	}
	cout << 2 << "\n";
	for(int i = 2; i <= n+1; i++){
		cout << prime[i] + 1 << " ";
	}
	cout << "\n";

	return 0;
}