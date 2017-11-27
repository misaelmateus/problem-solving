//   Author : Misael Mateus 
//   Submission date: 2016-09-25 01:08:51
#include<bits/stdc++.h>
#define ii pair<int, int>
#define INF 1000000000
using namespace std;
int main(){
    ios::sync_with_stdio( false );
    int n, m;
    cin >> n >> m;
    vector<int> v(n, INF);
    vector<int> M(n, 0);
    vector<pair< ii, ii> > op(m);
    bool resp = true;
    
    for(int i = 0; i < m; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        b--, c--;
        op[i] = { {a, b}, {c, d} };
        if(a == 1){
            for(int i = b; i <= c; i++)
                M[i] += d;
        }
        else{
            int flag = 0;
            for(int i = b; i <= c; i++){
                if(v[i] + M[i] >= d)
                    flag = 1, v[i] = d - M[i];
            }
            if(!flag)
                resp = false;
        }
    }
    vector<int> r = v;
    for(int i = 0; i < m; i++){
        int a = op[i].first.first;
        int b = op[i].first.second;
        int c = op[i].second.first;
        int d = op[i].second.second;
        
        if(a == 1)
            for(int i = b; i <= c; i++)
                r[i] += d;
        else
        {
            int Max = -INF;
            for(int i = b; i <= c; i++)
                Max = max(Max, r[i]);
            if(Max != d)
                resp = 0;
        }
    }
    if(resp){
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
            if(i)
                cout << " ";
            cout << v[i];
        
        }
    }
    else    
        cout << "NO" << endl;
    return 0;
}