//   Author : Misael Mateus 
//   Submission date: 2016-12-30 20:42:54
#include<bits/stdc++.h>
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define BIGNUM 400000000


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
 
int main(  ){
     ios::sync_with_stdio( false );
     int n;
     cin >> n;
 
     int k1 = -BIGNUM, k2 = BIGNUM;
     int A, B;
     cin >> A >> B;
     int ult = A;
     if(B == 1)
        k2 = 0;
     else
        k1 = 0;
     for(int i = 1; i < n; i++){
         int a, b;
         cin >> a >> b;
         if(b == 1){
             k2 = MIN(k2, A);
         }
         else
            k1 = MAX(k1, A);
        A += a;
     }
     
     int X, Y;
     X = 1900 - k2;
     Y = 1900 - k1;
     if(X >= Y)
        cout << "Impossible" << endl;
    else if(k1 == -BIGNUM)
        cout << "Infinity" << endl;
    else cout << 1900 - k1 - 1 + A;
 
}