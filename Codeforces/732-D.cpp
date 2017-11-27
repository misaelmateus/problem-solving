//   Author : Misael Mateus 
//   Submission date: 2016-10-17 21:06:20
#include<bits/stdc++.h>
#define MAXN 100100
using namespace std;
int d[MAXN];
int a[MAXN];
int n, m;

bool ver(int f){
    int mark[m];
    memset(mark, 0, sizeof(mark));
    
    int quant = 0;
    for(int i = f-1; i >= 0; i--){
        if(d[i] && !mark[ d[i]-1 ])
            quant += a[d[i]-1], mark[d[i]-1] = 1;
        else
            quant--;
        if(quant < 0)
            quant = 0;
    }
    
    for(int i = 0; i < m; i++)
        if(!mark[i])
            quant = 1;
    return (quant == 0);
}
int main(){
    ios::sync_with_stdio( false );
    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
        cin >> d[i];
    
    for(int i = 0; i < m; i++)
        cin >> a[i];
        
    int ini = 0, fim = n;
    while(fim - ini > 1){
        int middle = (ini + fim)/2;
        if(ver(middle))
            fim = middle;
        else
            ini = middle;
    }
    if(!ver(fim))
        cout << -1 << endl;
    else
        cout << fim << endl;
        
    return 0;
}