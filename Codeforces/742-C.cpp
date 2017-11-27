//   Author : Misael Mateus 
//   Submission date: 2016-12-06 19:51:34
#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll mdc(ll a, ll b) 
{  
 if(b == 0LL)  
  return a;  
 else  
  return mdc(b,a%b); 
} 
ll mmc(ll a, ll b){
    return (a*b)/mdc(a, b);
}
vector<int> mark;
vector<int> p;
int fim;
ll cont,  resp;
ll dfs(int a){
    mark[a] = 1;
    cont++;
    if(mark[p[a]] == 0)
        dfs(p[a]);
    else if(mark[p[a]] == 1)
        fim = p[a];
    else 
        fim = -1;
}
int main(){
    resp = 1LL;
    int n;
    cin >> n;
    
    p = vector<int>(n+1);
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    
    for(int i = 1; i <= n; i++){
        cont = 0LL;
        mark = vector<int>(n+1, 0);
        dfs(i);
        if(fim != i){
            cout << -1 << endl;
            return 0;
        }
        if(cont % 2LL == 0LL)
            resp = mmc(resp, cont/2LL);
        else resp = mmc(resp, cont);
    }
    
    
    cout << resp << endl;
    return 0;
}