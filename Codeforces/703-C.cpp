//   Author : Misael Mateus 
//   Submission date: 2016-08-04 22:05:04
#include<bits/stdc++.h>
#define ld long double
#define ii pair<long double, long double>
#define mp make_pair
const double EPS = 1e-9;
inline int SGN( ld a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( ld a, ld b ){ return SGN(a - b); }
using namespace std;
int main(){
    int n, w;
    ld v, u;
    cin >> n >> w >> v >> u;
    ii pos[n];
    ii men = mp( (ld)(1 << 30), (ld)(1 << 30) );
    int i_men = -1;
    int resp = 1;
    
    for(int i = 0; i < n; i++){
        ld a, b;
        cin >> a >> b;
        pos[i] = mp(a, b);
        if(CMP(b* v, a * u) == 1)
            resp = 0;
        if(CMP(b, men.second) == -1 || ( (CMP(b, men.second) == 0) && (CMP(a, men.first)== -1) ) ){
            men = pos[i];
            i_men = i;
        }
    }
    if(resp){
        cout<< fixed << setprecision(8) << (ld)(w / u);
        return 0;
    }
    ld t = 0.;
    int i = (i_men + 1)%n;
    ld y = (u * men.first) / v;
    ld x = men.first;
    t += men.first / v;
    if(CMP(y, men.second) == 1)
        y = men.second;
    while(1){
        if(CMP(x, pos[i].first) >= 0)
            break;
        
        ld t2 = (pos[i].first - x)/v;
        y += t2 * u;
        if(CMP(y, pos[i].second) == 1)
            y = pos[i].second;
        x = pos[i].first;
        t += t2;
        i++;
        if(i == n)
            i = 0;
    }
    
    t += (w - y) / u;
    cout << fixed << setprecision(8) << t << endl;
}