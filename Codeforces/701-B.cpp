//   Author : Misael Mateus 
//   Submission date: 2016-11-19 00:50:18
#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>

using namespace std;
int main(){
    ios::sync_with_stdio( false );
    
    ll n, m;
    cin >> n >> m;
    int line[n+1], col[n+1];
    ll contL = 0LL, contC = 0LL;
    memset(line, 0, sizeof(line));
    memset(col, 0, sizeof(col));
    ll ans = n*n;
    
    for(ll i = 0; i < m; i++){
        ll x, y;
        cin >> x >> y;
        
        if(!col[y]){
            col[y] = 1;
            ans -= n - contL;
            contC++;
        }
        if(!line[x]){
            line[x] = 1;
            ans -= n - contC;
            contL++;
        }
        
        cout << ans << " ";
    }
    
    cout << endl;
    return 0;
}#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>

using namespace std;
int main(){
    ios::sync_with_stdio( false );
    
    ll n, m;
    cin >> n >> m;
    int line[n+1], col[n+1];
    ll contL = 0LL, contC = 0LL;
    memset(line, 0, sizeof(line));
    memset(col, 0, sizeof(col));
    ll ans = n*n;
    
    for(ll i = 0; i < m; i++){
        ll x, y;
        cin >> x >> y;
        
        if(!col[y]){
            col[y] = 1;
            ans -= n - contL;
            contC++;
        }
        if(!line[x]){
            line[x] = 1;
            ans -= n - contC;
            contL++;
        }
        
        cout << ans << " ";
    }
    
    cout << endl;
    return 0;
}#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>

using namespace std;
int main(){
    ios::sync_with_stdio( false );
    
    ll n, m;
    cin >> n >> m;
    int line[n+1], col[n+1];
    ll contL = 0LL, contC = 0LL;
    memset(line, 0, sizeof(line));
    memset(col, 0, sizeof(col));
    ll ans = n*n;
    
    for(ll i = 0; i < m; i++){
        ll x, y;
        cin >> x >> y;
        
        if(!col[y]){
            col[y] = 1;
            ans -= n - contL;
            contC++;
        }
        if(!line[x]){
            line[x] = 1;
            ans -= n - contC;
            contL++;
        }
        
        cout << ans << " ";
    }
    
    cout << endl;
    return 0;
}#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>

using namespace std;
int main(){
    ios::sync_with_stdio( false );
    
    ll n, m;
    cin >> n >> m;
    int line[n+1], col[n+1];
    ll contL = 0LL, contC = 0LL;
    memset(line, 0, sizeof(line));
    memset(col, 0, sizeof(col));
    ll ans = n*n;
    
    for(ll i = 0; i < m; i++){
        ll x, y;
        cin >> x >> y;
        
        if(!col[y]){
            col[y] = 1;
            ans -= n - contL;
            contC++;
        }
        if(!line[x]){
            line[x] = 1;
            ans -= n - contC;
            contL++;
        }
        
        cout << ans << " ";
    }
    
    cout << endl;
    return 0;
}