//   Author : Misael Mateus 
//   Submission date: 2016-08-29 17:30:45
#include<bits/stdc++.h>
#define ll long long 
#define ii pair<int, int>
using namespace std;
int main(){
    int n;
    cin >> n;
    ll m[n][n];
    int i0, j0;
    for(int i = 0; i < n; i++){
        
        for(int j = 0; j < n; j++){
            cin >> m[i][j];
            if(m[i][j] == 0)
                i0 = i, j0 = j;
        }
    }
    
    if(n == 1){
        cout << "1" << endl;
        return 0;
    }
    ll soma = -1LL;
    for(int i = 0; i < n; i++){
        if(i == i0)
            continue;
        ll sum_atual = 0LL;
        for(int j = 0; j < n; j++)
            sum_atual += (ll)(m[i][j]);
        if(soma == -1LL)
            soma = sum_atual;
        else if(soma != sum_atual){
            printf("-1\n");
            return 0;
        }
    }
    
    ll sum_atual = 0LL;
    for(int j = 0; j < n; j++)
        sum_atual += (ll)m[i0][j];
    
    m[i0][j0] = ( soma - sum_atual);
    if(m[i0][j0] <= 0LL){
        printf("-1\n");
        return 0;
    }
    
    for(int j = 0; j < n; j++){
        sum_atual = 0LL;
        for(int i = 0; i < n; i++)
            sum_atual += (ll)m[i][j];
        if(sum_atual != soma)
        {
            printf("-1\n");
            return 0;
        }
    }
    sum_atual = 0LL;
    ll sum2 = 0LL;
    for(int i = 0; i < n; i++)
        sum_atual += (ll)m[i][i], sum2 += (ll)m[i][n - i - 1];
    if(sum_atual != soma || sum2 != soma)
    {
        printf("-1\n");
        return 0;
    }
    
    cout << m[i0][j0] << endl;
}