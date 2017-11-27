//   Author : Misael Mateus 
//   Submission date: 2016-08-12 20:26:05
#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll, ll> mapa;
set<ll> v;
int main()
{
    v.insert(0LL);
    mapa[0] = 1;
    
    ll q;
    cin >> q;
    
    while(q--){
        char c;
        ll n;
        cin >> c >> n;
        if(c == '+')
        {
            if(!mapa[n])
                v.insert(n);
            mapa[n] += 1;

        }
        if(c == '-')
        {
            mapa[n] -= 1;
            if(!mapa[n])
                v.erase(n);

        }
        if(c == '?'){
            set<ll>::iterator a, b;
            a = v.begin(), b = v.end();
            b--;
            ll j = 31LL; 
            ll num = 0LL;
            while(*a != *b && j >= 0){
                ll aux = n & (1LL << j);
                if(!aux){
                    set<ll>::iterator itlow;
                    itlow = v.lower_bound(num + (1LL << j) );
                    
                    if(itlow == v.end() || *itlow < *a || *itlow > *b);
                    else{
                        a = itlow;
                        num += (1LL << j);
                    }
                }
                if(aux){
                    set<ll>::iterator itlow;
                    itlow = v.lower_bound(num + (1LL << j));
                    if(itlow == v.end() || *itlow < *a || *itlow > *b);
                    else if(*itlow == *a)
                        num += (1LL << j);
                    else{
                        b = itlow;
                        b--;
                    }
                }
                
                j--;
            }
            cout << (n ^ (*a) ) << endl;
        }
    }
}