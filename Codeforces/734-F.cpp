//   Author : Misael Mateus 
//   Submission date: 2016-11-18 21:45:31
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio( false );
    ll n;
    cin >> n;
    
    ll a[n], b[n], c[n], d[n];
    ll sum = 0LL;
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 0; i < n; i++){
        cin >> c[i];
        d[i] = b[i] + c[i];
        sum += d[i];
    }
    
    for(int i = 0; i < n; i++){
        a[i] = (2LL*n*d[i] - sum)/(2LL*n*n);
        if(a[i] < 0){
            cout << -1 << endl;
            return 0;
        }
    }
    ll B[n], C[n], Sum[50];
    memset(B, 0, sizeof(B));
    memset(C, 0, sizeof(C));
    memset(Sum, 0, sizeof(Sum));
    for(int i = 0; i < 50; i++){
        for(int j = 0; j < n; j++)
            Sum[i] += (a[j] & (1LL << i));
        for(int j = 0; j < n; j++){
            if(a[j] & (1LL << i))
                B[j] += Sum[i];
            if(a[j] & (1LL << i))
                C[j] += n*(1LL << i);
            else
                C[j] += Sum[i];
        }
    }
    
    for(int i = 0; i < n; i++)
        if(b[i] != B[i] || c[i] != C[i]){
            cout << -1 << endl;
            return 0;
        }
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    
    return 0;
}#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio( false );
    ll n;
    cin >> n;
    
    ll a[n], b[n], c[n], d[n];
    ll sum = 0LL;
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 0; i < n; i++){
        cin >> c[i];
        d[i] = b[i] + c[i];
        sum += d[i];
    }
    
    for(int i = 0; i < n; i++){
        a[i] = (2LL*n*d[i] - sum)/(2LL*n*n);
        if(a[i] < 0){
            cout << -1 << endl;
            return 0;
        }
    }
    ll B[n], C[n], Sum[50];
    memset(B, 0, sizeof(B));
    memset(C, 0, sizeof(C));
    memset(Sum, 0, sizeof(Sum));
    for(int i = 0; i < 50; i++){
        for(int j = 0; j < n; j++)
            Sum[i] += (a[j] & (1LL << i));
        for(int j = 0; j < n; j++){
            if(a[j] & (1LL << i))
                B[j] += Sum[i];
            if(a[j] & (1LL << i))
                C[j] += n*(1LL << i);
            else
                C[j] += Sum[i];
        }
    }
    
    for(int i = 0; i < n; i++)
        if(b[i] != B[i] || c[i] != C[i]){
            cout << -1 << endl;
            return 0;
        }
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    
    return 0;
}#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio( false );
    ll n;
    cin >> n;
    
    ll a[n], b[n], c[n], d[n];
    ll sum = 0LL;
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 0; i < n; i++){
        cin >> c[i];
        d[i] = b[i] + c[i];
        sum += d[i];
    }
    
    for(int i = 0; i < n; i++){
        a[i] = (2LL*n*d[i] - sum)/(2LL*n*n);
        if(a[i] < 0){
            cout << -1 << endl;
            return 0;
        }
    }
    ll B[n], C[n], Sum[50];
    memset(B, 0, sizeof(B));
    memset(C, 0, sizeof(C));
    memset(Sum, 0, sizeof(Sum));
    for(int i = 0; i < 50; i++){
        for(int j = 0; j < n; j++)
            Sum[i] += (a[j] & (1LL << i));
        for(int j = 0; j < n; j++){
            if(a[j] & (1LL << i))
                B[j] += Sum[i];
            if(a[j] & (1LL << i))
                C[j] += n*(1LL << i);
            else
                C[j] += Sum[i];
        }
    }
    
    for(int i = 0; i < n; i++)
        if(b[i] != B[i] || c[i] != C[i]){
            cout << -1 << endl;
            return 0;
        }
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    
    return 0;
}#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio( false );
    ll n;
    cin >> n;
    
    ll a[n], b[n], c[n], d[n];
    ll sum = 0LL;
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 0; i < n; i++){
        cin >> c[i];
        d[i] = b[i] + c[i];
        sum += d[i];
    }
    
    for(int i = 0; i < n; i++){
        a[i] = (2LL*n*d[i] - sum)/(2LL*n*n);
        if(a[i] < 0){
            cout << -1 << endl;
            return 0;
        }
    }
    ll B[n], C[n], Sum[50];
    memset(B, 0, sizeof(B));
    memset(C, 0, sizeof(C));
    memset(Sum, 0, sizeof(Sum));
    for(int i = 0; i < 50; i++){
        for(int j = 0; j < n; j++)
            Sum[i] += (a[j] & (1LL << i));
        for(int j = 0; j < n; j++){
            if(a[j] & (1LL << i))
                B[j] += Sum[i];
            if(a[j] & (1LL << i))
                C[j] += n*(1LL << i);
            else
                C[j] += Sum[i];
        }
    }
    
    for(int i = 0; i < n; i++)
        if(b[i] != B[i] || c[i] != C[i]){
            cout << -1 << endl;
            return 0;
        }
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    
    return 0;
}