//   Author : Misael Mateus 
//   Submission date: 2016-11-21 14:19:58
#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define ld long double

using namespace std;
int main(){
    ios::sync_with_stdio( false );
    int n, k, s, t, x;
    cin >> n >> k >> s >> t;
    x = 2*s - t;
    if(x < 0) x = 0;
    ii car[n];
    for(int i = 0; i < n; i++)
        cin >> car[i].first >> car[i].second;
    
    int g[k+1];
    for(int i = 0; i < k; i++)
        cin >> g[i];
    
    sort(g, g+k);
    int ult = 0;
    
    for(int i = 0; i < k; i++){
        int aux = g[i];
        g[i] = g[i] - ult, ult = aux;
    }
    g[k] = s - ult;

    int ini = 0, fim = (2*s + 1);
    while(fim - ini > 1){
        int middle = (ini + fim)/2;
        int cont = 0;
        for(int i = 0; i < k+1; i++)
        {
            if(middle < g[i]){
                cont = -1;
                break;
            }
            cont += min(middle - g[i], g[i]);
        }
        
        if(cont == -1 || cont < x)
            ini = middle;
        else
            fim = middle;
    }
    int ans = 1000000010;
    for(int i = 0; i < n; i++)
    {
        if(car[i].second >= fim)
            ans = min(ans, car[i].first);
    }
    
    if(ans == 1000000010 || fim == 2*s+1)
        cout << -1 << endl;
    else
        cout << ans << endl;
}#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define ld long double

using namespace std;
int main(){
    ios::sync_with_stdio( false );
    int n, k, s, t, x;
    cin >> n >> k >> s >> t;
    x = 2*s - t;
    if(x < 0) x = 0;
    ii car[n];
    for(int i = 0; i < n; i++)
        cin >> car[i].first >> car[i].second;
    
    int g[k+1];
    for(int i = 0; i < k; i++)
        cin >> g[i];
    
    sort(g, g+k);
    int ult = 0;
    
    for(int i = 0; i < k; i++){
        int aux = g[i];
        g[i] = g[i] - ult, ult = aux;
    }
    g[k] = s - ult;

    int ini = 0, fim = (2*s + 1);
    while(fim - ini > 1){
        int middle = (ini + fim)/2;
        int cont = 0;
        for(int i = 0; i < k+1; i++)
        {
            if(middle < g[i]){
                cont = -1;
                break;
            }
            cont += min(middle - g[i], g[i]);
        }
        
        if(cont == -1 || cont < x)
            ini = middle;
        else
            fim = middle;
    }
    int ans = 1000000010;
    for(int i = 0; i < n; i++)
    {
        if(car[i].second >= fim)
            ans = min(ans, car[i].first);
    }
    
    if(ans == 1000000010 || fim == 2*s+1)
        cout << -1 << endl;
    else
        cout << ans << endl;
}#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define ld long double

using namespace std;
int main(){
    ios::sync_with_stdio( false );
    int n, k, s, t, x;
    cin >> n >> k >> s >> t;
    x = 2*s - t;
    if(x < 0) x = 0;
    ii car[n];
    for(int i = 0; i < n; i++)
        cin >> car[i].first >> car[i].second;
    
    int g[k+1];
    for(int i = 0; i < k; i++)
        cin >> g[i];
    
    sort(g, g+k);
    int ult = 0;
    
    for(int i = 0; i < k; i++){
        int aux = g[i];
        g[i] = g[i] - ult, ult = aux;
    }
    g[k] = s - ult;

    int ini = 0, fim = (2*s + 1);
    while(fim - ini > 1){
        int middle = (ini + fim)/2;
        int cont = 0;
        for(int i = 0; i < k+1; i++)
        {
            if(middle < g[i]){
                cont = -1;
                break;
            }
            cont += min(middle - g[i], g[i]);
        }
        
        if(cont == -1 || cont < x)
            ini = middle;
        else
            fim = middle;
    }
    int ans = 1000000010;
    for(int i = 0; i < n; i++)
    {
        if(car[i].second >= fim)
            ans = min(ans, car[i].first);
    }
    
    if(ans == 1000000010 || fim == 2*s+1)
        cout << -1 << endl;
    else
        cout << ans << endl;
}#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define ld long double

using namespace std;
int main(){
    ios::sync_with_stdio( false );
    int n, k, s, t, x;
    cin >> n >> k >> s >> t;
    x = 2*s - t;
    if(x < 0) x = 0;
    ii car[n];
    for(int i = 0; i < n; i++)
        cin >> car[i].first >> car[i].second;
    
    int g[k+1];
    for(int i = 0; i < k; i++)
        cin >> g[i];
    
    sort(g, g+k);
    int ult = 0;
    
    for(int i = 0; i < k; i++){
        int aux = g[i];
        g[i] = g[i] - ult, ult = aux;
    }
    g[k] = s - ult;

    int ini = 0, fim = (2*s + 1);
    while(fim - ini > 1){
        int middle = (ini + fim)/2;
        int cont = 0;
        for(int i = 0; i < k+1; i++)
        {
            if(middle < g[i]){
                cont = -1;
                break;
            }
            cont += min(middle - g[i], g[i]);
        }
        
        if(cont == -1 || cont < x)
            ini = middle;
        else
            fim = middle;
    }
    int ans = 1000000010;
    for(int i = 0; i < n; i++)
    {
        if(car[i].second >= fim)
            ans = min(ans, car[i].first);
    }
    
    if(ans == 1000000010 || fim == 2*s+1)
        cout << -1 << endl;
    else
        cout << ans << endl;
}