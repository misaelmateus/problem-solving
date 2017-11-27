//   Author : Misael Mateus 
//   Submission date: 2016-10-17 20:55:29
#include<bits/stdc++.h>
using namespace std;
#define vi vector<ll>
#define ll long long
vi ini[3] = { {0LL, 0LL, 0LL}, {1LL, 0LL, 0LL}, {1LL, 1LL, 0LL} };
vi fim[3] = { {0LL, 1LL, 1LL}, {0LL, 0LL, 1LL}, {0LL, 0LL, 0LL} };

vi sum(vi a, vi b){
    for(int i = 0; i < a.size(); i++)
        a[i] += b[i];
        
    return a;
}
int main(){
    vector<ll> resp(3);
    for(int i = 0; i < 3; i++)
        cin >> resp[i];
    ll fin = -1LL;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++){
            vi a = sum( sum(resp, ini[i]), fim[j]);
            ll max = a[0];
            if(a[1] > max)
                max = a[1];
            if(a[2] > max)
                max = a[2];
                
            ll c = 0;
            for(int l = 0; l < 3; l++)
                c += max - a[l];
            if(fin == -1LL || c < fin)
                fin = c;
        }
        
    cout << fin << endl;
}#include<bits/stdc++.h>
using namespace std;
#define vi vector<ll>
#define ll long long
vi ini[3] = { {0LL, 0LL, 0LL}, {1LL, 0LL, 0LL}, {1LL, 1LL, 0LL} };
vi fim[3] = { {0LL, 1LL, 1LL}, {0LL, 0LL, 1LL}, {0LL, 0LL, 0LL} };

vi sum(vi a, vi b){
    for(int i = 0; i < a.size(); i++)
        a[i] += b[i];
        
    return a;
}
int main(){
    vector<ll> resp(3);
    for(int i = 0; i < 3; i++)
        cin >> resp[i];
    ll fin = -1LL;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++){
            vi a = sum( sum(resp, ini[i]), fim[j]);
            ll max = a[0];
            if(a[1] > max)
                max = a[1];
            if(a[2] > max)
                max = a[2];
                
            ll c = 0;
            for(int l = 0; l < 3; l++)
                c += max - a[l];
            if(fin == -1LL || c < fin)
                fin = c;
        }
        
    cout << fin << endl;
}#include<bits/stdc++.h>
using namespace std;
#define vi vector<ll>
#define ll long long
vi ini[3] = { {0LL, 0LL, 0LL}, {1LL, 0LL, 0LL}, {1LL, 1LL, 0LL} };
vi fim[3] = { {0LL, 1LL, 1LL}, {0LL, 0LL, 1LL}, {0LL, 0LL, 0LL} };

vi sum(vi a, vi b){
    for(int i = 0; i < a.size(); i++)
        a[i] += b[i];
        
    return a;
}
int main(){
    vector<ll> resp(3);
    for(int i = 0; i < 3; i++)
        cin >> resp[i];
    ll fin = -1LL;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++){
            vi a = sum( sum(resp, ini[i]), fim[j]);
            ll max = a[0];
            if(a[1] > max)
                max = a[1];
            if(a[2] > max)
                max = a[2];
                
            ll c = 0;
            for(int l = 0; l < 3; l++)
                c += max - a[l];
            if(fin == -1LL || c < fin)
                fin = c;
        }
        
    cout << fin << endl;
}#include<bits/stdc++.h>
using namespace std;
#define vi vector<ll>
#define ll long long
vi ini[3] = { {0LL, 0LL, 0LL}, {1LL, 0LL, 0LL}, {1LL, 1LL, 0LL} };
vi fim[3] = { {0LL, 1LL, 1LL}, {0LL, 0LL, 1LL}, {0LL, 0LL, 0LL} };

vi sum(vi a, vi b){
    for(int i = 0; i < a.size(); i++)
        a[i] += b[i];
        
    return a;
}
int main(){
    vector<ll> resp(3);
    for(int i = 0; i < 3; i++)
        cin >> resp[i];
    ll fin = -1LL;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++){
            vi a = sum( sum(resp, ini[i]), fim[j]);
            ll max = a[0];
            if(a[1] > max)
                max = a[1];
            if(a[2] > max)
                max = a[2];
                
            ll c = 0;
            for(int l = 0; l < 3; l++)
                c += max - a[l];
            if(fin == -1LL || c < fin)
                fin = c;
        }
        
    cout << fin << endl;
}