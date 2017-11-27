//   Author : Misael Mateus 
//   Submission date: 2016-10-31 20:03:14
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
#define ii pair<int, int>
using namespace std;
 
int main(  ){
     ios::sync_with_stdio( false );
    map<ii, pair<ii, ii> > mapa;
    
    int n;
    cin >> n;
    int A[n], B[n], C[n];
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a > b){int aux = a; a = b; b = aux; }
        if(b > c){int aux = b; b = c; c = aux; }
        if(a > b){int aux = a; a = b; b = aux; }
        A[i] = a, B[i] = b, C[i] = c;
        
        if(mapa[{a,b}].first.first < c)
            mapa[{a, b}].second = mapa[{a, b}].first, mapa[{a, b}].first = {c, i};
        else if(mapa[{a,b}].second.first < c)
            mapa[{a,b}].second = {c, i};
            
        if(mapa[{a,c}].first.first < b)
            mapa[{a, c}].second = mapa[{a, c}].first, mapa[{a, c}].first = {b, i};
        else if(mapa[{a,c}].second.first < b)
            mapa[{a,c}].second = {b, i};
            
        if(mapa[{b, c}].first.first < a)
            mapa[{b, c}].second = mapa[{b, c}].first, mapa[{b, c}].first = {a, i};
        else if(mapa[{b, c}].second.first < a)
            mapa[{b, c}].second = {a, i};
            
    }
    int index1 = 0, men1 = A[0];
    for(int i = 1; i < n; i++)
        if(A[i] > men1) men1 = A[i], index1 = i;
        
    int index[2], men = 0;
    for(int i = 0; i < n; i++){
        int a = A[i], b = B[i], c = C[i];
        if(mapa[{b, c}].first.first == a)
        {
            if(mapa[{b, c}].second.first != 0)
                if(min(A[i] + mapa[{b, c}].second.first, min(b, c) ) > men )
                    index[0] = i, index[1] = mapa[{b, c}].second.second, men = min(A[i] + mapa[{b, c}].second.first, min(b, c) );
            
        }
        else if(mapa[{b, c}].first.first != 0){
            if(min(A[i] + mapa[{b, c}].first.first, min(b, c) ) > men )
                index[0] = i, index[1] = mapa[{b, c}].first.second, men = min(A[i] + mapa[{b, c}].first.first, min(b, c) );
        }
    }
    
    if(men1 >= men)
        cout << 1 << endl << index1+1 << endl;
    else
        cout << 2 << endl << index[0]+1 << " " << index[1]+1 << endl;
    
}   