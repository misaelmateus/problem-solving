//   Author : Misael Mateus 
//   Submission date: 2016-10-03 17:28:14
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int v[n];
    int b[m+1];
    int c[n+1];

    int f = 0;
    
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    c[0] = m;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(v[i] > m)
            f++;
        else{
            b[v[i]]++;
            c[ b[v[i]] - 1 ]--;
            c[ b[v[i]] ]++;
        }
    }


    
    int t = 0;
    while(1){
        int men = 1000000;
        for(int i = 0; i <= n; i++)
            if(c[i]){
                men = i;
                break;
            }
        int q = f;
        for(int i = men+2; i <= n; i++){
            if(q += c[i]*(i - men - 1));
        }
        if(q < c[men])
            break;
        t++;
        int ma, me;
        if(f > 0){
            int p;
            for(int i = 0; i < n; i++)
                if(v[i] > m)
                    p = i;
            for(int i = 1; i <= m; i++)
                if(b[i] == men){
                    me = i;
                    break;
                }
            
            v[p] = me;
            c[b[me]]--;
            b[me]++;
            c[b[me]]++;
            f--;
        }   
        else{
            for(int i = 1; i <= m; i++)
                if(b[i] == men){
                    me = i;
                    break;
                }
            int x;
            for(int i = n; i >= 1; i--)
                if(c[i]){
                    x = i;
                    break;
                }
            for(int i = m; i > 0; i--)
                if(b[i] == x){
                    ma = i;
                    break;
                }
            
            c[b[ma]]--;
            b[ma]--;
            c[b[ma]]++;
            
            for(int i = 0; i < n; i++)
                if(v[i] == ma){
                    ma = i;
                    break;
                }
            c[b[me]]--;
            b[me]++;
            c[b[me]]++;
            v[ma] = me;
            
        }
    }
    int ma = 100000000;
    for(int i = 1; i <= m; i++)
        if(ma > b[i])
            ma = b[i];
    cout << ma << " " << t << endl;
    for(int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
    
    
}