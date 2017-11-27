//   Author : Misael Mateus 
//   Submission date: 2017-01-13 16:57:36
#include<bits/stdc++.h>

#define L 1000000007LL

#define ll long long

using namespace std;

int main(){

    int n, m;

    cin >> n >> m;

    

    multiset<int> p[m+1];

    

    for(int i = 0; i < n; i++){

        int quant;

        cin >> quant;

        while(quant--){

            int j;

            cin >> j;

            p[j].insert(i);

        }

    }

    map<multiset<int>, int> mapa;

    for(int i = 1; i <= m; i++)

        mapa[p[i]]++;

    ll ans = 1LL;

    for(auto it = mapa.begin(); it != mapa.end(); it++){

        for(ll i = 2LL; i <= (ll)(*it).second; i++)

            ans = (ans*i)%L;

    }

    

    cout << ans << endl;

}