//   Author : Misael Mateus 
//   Submission date: 2016-11-16 17:08:37
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int x0, y0;
    cin >> x0 >> y0;
    
    int c1, c2, c3, c4, d1, d2, d3, d4;
    c1 = c2 = c3 = c4 = d1 = d2 = d3 = d4 = 2000000100;
    
    vector<int> x(n), y(n);
    vector<char> c(n);
    
    for(int i = 0; i < n; i++){
        cin >> c[i] >> x[i] >> y[i];
        x[i] -= x0, y[i] -= y0;
        if(!x[i] || !y[i]){
            if(x[i] > 0)
                c1 = min(c1, x[i]);
            if(y[i] > 0)
                c2 = min(c2, y[i]);
            if(x[i] < 0)
                c3 = min(c3, -x[i]);
            if(y[i] < 0)
                c4 = min(c4, -y[i]);
        }
        if(abs(x[i]) == abs(y[i])){
             if(x[i] > 0){
                 if(y[i] < 0)
                    d1 = min(d1, abs(x[i]));
                else
                    d2 = min(d2, abs(x[i]));
             }
             else
             {
                 if(y[i] > 0)
                    d3 = min(d3, abs(x[i]));
                else
                    d4 = min(d4, abs(x[i]));
             }
        }
    }
    for(int i = 0; i < n; i++){
        if((c[i] == 'Q' || c[i] == 'R') && (!x[i] || !y[i])){
            if( (x[i] > 0 && x[i] <= c1) || (y[i] > 0 && y[i] <= c2) ||
                (x[i] < 0  && -x[i] <= c3) || (y[i] < 0 && -y[i] <= c4)
              )
            {
                cout << "YES"  << endl;
                return 0;
            }
    
        }
        if((c[i] == 'Q' || c[i] == 'B') && abs(x[i]) == abs(y[i])){
            int r = 0;
             if(x[i] > 0){
                 if(y[i] < 0 && abs(x[i]) <= d1)
                    r = 1;
                else if(y[i] > 0 && abs(x[i]) <= d2)
                    r = 1;
             }
             else
             {
                 if(y[i] > 0 && abs(x[i]) <= d3)
                    r = 1;
                else if(y[i] < 0 && abs(x[i]) <= d4)
                    r = 1;
             }
             if(r)
             {
                 cout << "YES" << endl;
                 return 0;
             }
        }
    }
    
    cout << "NO" << endl;
    return 0;
}