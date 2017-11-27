//   Author : Misael Mateus 
//   Submission date: 2016-07-25 20:24:32
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    string s;
    cin >> s;

    map<char, int> mapa;
    for(int i = 0; i < s.size(); i++)
        mapa[s[i] ] += 1;

    ll total = 0LL;

    for(char letra = 'a'; letra <= 'z'; letra++)
        total += (ll)mapa[letra]*(ll)mapa[letra];

    for(char letra = '0'; letra <= '9'; letra++)
        total += (ll)mapa[letra]* (ll)mapa[letra];

    cout << total;

    return 0;
}
