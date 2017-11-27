//   Author : Misael Mateus 
//   Submission date: 2016-08-11 22:01:35
#include<bits/stdc++.h>
#define ld long double
const ld EPS = 1e-11;
inline int SGN( ld a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( ld a, ld b ){ return SGN(a - b); }
using namespace std;
int main(){
    ld M = 100000000.;
    ld x, y;
    cin >> x >> y;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        ld xi, yi, vi;
        cin >> xi >> yi >> vi;
        ld atual = sqrt((xi - x)*(xi - x) + (yi - y)*(yi - y)) / vi;
        if(atual < M + EPS)
            M = atual;
    }
    
    cout << fixed << setprecision(9) << M << endl;
}