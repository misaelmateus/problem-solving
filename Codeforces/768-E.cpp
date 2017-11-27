//   Author : Misael Mateus 
//   Submission date: 2017-02-20 22:25:48
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
	
	int v[64];
	v[0] = 0;
	v[1] = 1;
	v[2] = 1;
	int ult = 1;
	for(int i = 1; (i*(i+1))/2 <= 61; i++){
		for(int j = (i*(i+1))/2; j <= 61; j++)
			v[j] = i;
	}

	int n;
	scanf("%d", &n);

	int ans = 0, aux;

	for(int i = 0; i < n; i++){
		scanf("%d", &aux);

		ans ^= v[aux];

	}
	
	if(ans != 0)
		printf("NO\n");
	else printf("YES\n");


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

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }


using namespace std;
int main(){
	
	int v[64];
	v[0] = 0;
	v[1] = 1;
	v[2] = 1;
	int ult = 1;
	for(int i = 1; (i*(i+1))/2 <= 61; i++){
		for(int j = (i*(i+1))/2; j <= 61; j++)
			v[j] = i;
	}

	int n;
	scanf("%d", &n);

	int ans = 0, aux;

	for(int i = 0; i < n; i++){
		scanf("%d", &aux);

		ans ^= v[aux];

	}
	
	if(ans != 0)
		printf("NO\n");
	else printf("YES\n");


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

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }


using namespace std;
int main(){
	
	int v[64];
	v[0] = 0;
	v[1] = 1;
	v[2] = 1;
	int ult = 1;
	for(int i = 1; (i*(i+1))/2 <= 61; i++){
		for(int j = (i*(i+1))/2; j <= 61; j++)
			v[j] = i;
	}

	int n;
	scanf("%d", &n);

	int ans = 0, aux;

	for(int i = 0; i < n; i++){
		scanf("%d", &aux);

		ans ^= v[aux];

	}
	
	if(ans != 0)
		printf("NO\n");
	else printf("YES\n");


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

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }


using namespace std;
int main(){
	
	int v[64];
	v[0] = 0;
	v[1] = 1;
	v[2] = 1;
	int ult = 1;
	for(int i = 1; (i*(i+1))/2 <= 61; i++){
		for(int j = (i*(i+1))/2; j <= 61; j++)
			v[j] = i;
	}

	int n;
	scanf("%d", &n);

	int ans = 0, aux;

	for(int i = 0; i < n; i++){
		scanf("%d", &aux);

		ans ^= v[aux];

	}
	
	if(ans != 0)
		printf("NO\n");
	else printf("YES\n");


	return 0;
}