//   Author : Misael Mateus 
//   Submission date: 2017-02-22 21:29:52
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

	int n, k, x;
	cin >> n >> k >> x;
	
	vector<int> v(1043, 0), v1;
	vector<int> quant(1043, 0);
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		v[num]++;
	}
	for(int i = 1; i <= 1043; i++)
		quant[i] = quant[i-1]+v[i-1];


	for(int j = 0; j < k; j++){
		v1 = v;		
			
		for(int i = 0; i <= 1043; i++){
			if(!v[i])  continue;
			int next = i^x, q;
			if( quant[i] % 2 ) 
				 q = (v[i])/2;
			else q = (v[i] + 1)/2;
			
			v1[i] -= q;
			v1[next] += q;

		}
		
		v = v1;
		for(int i = 1; i <= 1043; i++)
			quant[i] = quant[i-1]+v[i-1];
	}
	int mi = 10000, ma = 0;

	for(int i = 0; i <= 1043; i++)
		if(v[i]) mi = min(mi, i), ma = max(ma, i);	
	cout << ma << " " << mi << endl;
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

	int n, k, x;
	cin >> n >> k >> x;
	
	vector<int> v(1043, 0), v1;
	vector<int> quant(1043, 0);
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		v[num]++;
	}
	for(int i = 1; i <= 1043; i++)
		quant[i] = quant[i-1]+v[i-1];


	for(int j = 0; j < k; j++){
		v1 = v;		
			
		for(int i = 0; i <= 1043; i++){
			if(!v[i])  continue;
			int next = i^x, q;
			if( quant[i] % 2 ) 
				 q = (v[i])/2;
			else q = (v[i] + 1)/2;
			
			v1[i] -= q;
			v1[next] += q;

		}
		
		v = v1;
		for(int i = 1; i <= 1043; i++)
			quant[i] = quant[i-1]+v[i-1];
	}
	int mi = 10000, ma = 0;

	for(int i = 0; i <= 1043; i++)
		if(v[i]) mi = min(mi, i), ma = max(ma, i);	
	cout << ma << " " << mi << endl;
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

	int n, k, x;
	cin >> n >> k >> x;
	
	vector<int> v(1043, 0), v1;
	vector<int> quant(1043, 0);
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		v[num]++;
	}
	for(int i = 1; i <= 1043; i++)
		quant[i] = quant[i-1]+v[i-1];


	for(int j = 0; j < k; j++){
		v1 = v;		
			
		for(int i = 0; i <= 1043; i++){
			if(!v[i])  continue;
			int next = i^x, q;
			if( quant[i] % 2 ) 
				 q = (v[i])/2;
			else q = (v[i] + 1)/2;
			
			v1[i] -= q;
			v1[next] += q;

		}
		
		v = v1;
		for(int i = 1; i <= 1043; i++)
			quant[i] = quant[i-1]+v[i-1];
	}
	int mi = 10000, ma = 0;

	for(int i = 0; i <= 1043; i++)
		if(v[i]) mi = min(mi, i), ma = max(ma, i);	
	cout << ma << " " << mi << endl;
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

	int n, k, x;
	cin >> n >> k >> x;
	
	vector<int> v(1043, 0), v1;
	vector<int> quant(1043, 0);
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		v[num]++;
	}
	for(int i = 1; i <= 1043; i++)
		quant[i] = quant[i-1]+v[i-1];


	for(int j = 0; j < k; j++){
		v1 = v;		
			
		for(int i = 0; i <= 1043; i++){
			if(!v[i])  continue;
			int next = i^x, q;
			if( quant[i] % 2 ) 
				 q = (v[i])/2;
			else q = (v[i] + 1)/2;
			
			v1[i] -= q;
			v1[next] += q;

		}
		
		v = v1;
		for(int i = 1; i <= 1043; i++)
			quant[i] = quant[i-1]+v[i-1];
	}
	int mi = 10000, ma = 0;

	for(int i = 0; i <= 1043; i++)
		if(v[i]) mi = min(mi, i), ma = max(ma, i);	
	cout << ma << " " << mi << endl;
}