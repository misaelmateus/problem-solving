//   Author : Misael Mateus 
//   Submission date: 2016-10-01 19:24:25
#include<bits/stdc++.h>
#define ll long long
#define MAXN 100100
using namespace std;
ll tree[MAXN];

void update(int x, ll k){
    while(x < MAXN){
        tree[x] += k;
        x += (x & -x);
    }
}

ll sum(int x){
    ll resp = 0LL;
    while(x > 0){
        resp += tree[x];
        x -= (x & -x);
    }
    
    return resp;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        ll aux;
        cin >> aux;
        update(i, aux);
        
    }
    
    set<int> u;
    multiset<ll> somas;
    
    u.insert(n+1);
    u.insert(0);
    somas.insert(-sum(n));
    for(int i = 1; i <= n; i++){
        int aux;
        cin >> aux;
        set<int>::iterator it1, it2;
        it1 = u.upper_bound(aux);
        int b = *it1;
        it1--;
        int a = *it1;
          
        
        ll X = sum(b-1), Y = sum(a);
        ll c = X - Y;
        ll d = sum(aux - 1) - Y;
        ll e = X - sum(aux);
        
        multiset<ll>::iterator it = somas.find(-c);
        
        somas.erase(it);
        somas.insert(-d);
        somas.insert(-e);
        u.insert(aux);
        
        it = somas.begin();
        cout << -(*it) << endl;
    }
}#include<bits/stdc++.h>
#define ll long long
#define MAXN 100100
using namespace std;
ll tree[MAXN];

void update(int x, ll k){
    while(x < MAXN){
        tree[x] += k;
        x += (x & -x);
    }
}

ll sum(int x){
    ll resp = 0LL;
    while(x > 0){
        resp += tree[x];
        x -= (x & -x);
    }
    
    return resp;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        ll aux;
        cin >> aux;
        update(i, aux);
        
    }
    
    set<int> u;
    multiset<ll> somas;
    
    u.insert(n+1);
    u.insert(0);
    somas.insert(-sum(n));
    for(int i = 1; i <= n; i++){
        int aux;
        cin >> aux;
        set<int>::iterator it1, it2;
        it1 = u.upper_bound(aux);
        int b = *it1;
        it1--;
        int a = *it1;
          
        
        ll X = sum(b-1), Y = sum(a);
        ll c = X - Y;
        ll d = sum(aux - 1) - Y;
        ll e = X - sum(aux);
        
        multiset<ll>::iterator it = somas.find(-c);
        
        somas.erase(it);
        somas.insert(-d);
        somas.insert(-e);
        u.insert(aux);
        
        it = somas.begin();
        cout << -(*it) << endl;
    }
}#include<bits/stdc++.h>
#define ll long long
#define MAXN 100100
using namespace std;
ll tree[MAXN];

void update(int x, ll k){
    while(x < MAXN){
        tree[x] += k;
        x += (x & -x);
    }
}

ll sum(int x){
    ll resp = 0LL;
    while(x > 0){
        resp += tree[x];
        x -= (x & -x);
    }
    
    return resp;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        ll aux;
        cin >> aux;
        update(i, aux);
        
    }
    
    set<int> u;
    multiset<ll> somas;
    
    u.insert(n+1);
    u.insert(0);
    somas.insert(-sum(n));
    for(int i = 1; i <= n; i++){
        int aux;
        cin >> aux;
        set<int>::iterator it1, it2;
        it1 = u.upper_bound(aux);
        int b = *it1;
        it1--;
        int a = *it1;
          
        
        ll X = sum(b-1), Y = sum(a);
        ll c = X - Y;
        ll d = sum(aux - 1) - Y;
        ll e = X - sum(aux);
        
        multiset<ll>::iterator it = somas.find(-c);
        
        somas.erase(it);
        somas.insert(-d);
        somas.insert(-e);
        u.insert(aux);
        
        it = somas.begin();
        cout << -(*it) << endl;
    }
}#include<bits/stdc++.h>
#define ll long long
#define MAXN 100100
using namespace std;
ll tree[MAXN];

void update(int x, ll k){
    while(x < MAXN){
        tree[x] += k;
        x += (x & -x);
    }
}

ll sum(int x){
    ll resp = 0LL;
    while(x > 0){
        resp += tree[x];
        x -= (x & -x);
    }
    
    return resp;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        ll aux;
        cin >> aux;
        update(i, aux);
        
    }
    
    set<int> u;
    multiset<ll> somas;
    
    u.insert(n+1);
    u.insert(0);
    somas.insert(-sum(n));
    for(int i = 1; i <= n; i++){
        int aux;
        cin >> aux;
        set<int>::iterator it1, it2;
        it1 = u.upper_bound(aux);
        int b = *it1;
        it1--;
        int a = *it1;
          
        
        ll X = sum(b-1), Y = sum(a);
        ll c = X - Y;
        ll d = sum(aux - 1) - Y;
        ll e = X - sum(aux);
        
        multiset<ll>::iterator it = somas.find(-c);
        
        somas.erase(it);
        somas.insert(-d);
        somas.insert(-e);
        u.insert(aux);
        
        it = somas.begin();
        cout << -(*it) << endl;
    }
}