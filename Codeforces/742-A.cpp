//   Author : Misael Mateus 
//   Submission date: 2016-12-06 19:53:42
#include<bits/stdc++.h>
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define BIGNUM 100000000


#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
 
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
typedef long double ld;
 
using namespace std;

int pot(int a, int n){
    a = a % 10;
    if(n == 1)
        return a;
    int resp = pot(a, n/2);
    resp = resp*resp;
    if(n%2)
        resp *= a;
    resp %= 10;
    return resp;
}
int main(  ){
     ios::sync_with_stdio( false );
     int n;
     cin >> n;
     if(n == 0)
        cout << 1 << endl;
     else cout << pot(8, n);
}