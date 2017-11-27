//   Author : Misael Mateus 
//   Submission date: 2016-09-17 19:29:25
#include<bits/stdc++.h>
#define INF 1000LL
#define pb push_back
#define mp make_pair
#define ll long long
#define ld double
using namespace std;

typedef pair<int, int> prime_pot;
typedef long long int64;
 
//aqui que dtermina o limite dos primos
const unsigned MAX = 20001000/60, MAX_S = sqrt(MAX/60);
 
unsigned w[16] = {1, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 49, 53, 59};
unsigned short composite[MAX];
vector<int> primes;
 
void sieve() {
   unsigned mod[16][16], di[16][16], num;
   for(int i = 0; i < 16; i++)
       for(int j = 0; j < 16; j++) {
           di[i][j] = (w[i]*w[j])/60;
           mod[i][j] = lower_bound(w, w + 16, (w[i]*w[j])%60) - w;
       }
 
   primes.push_back(2); primes.push_back(3); primes.push_back(5);
 
   for(unsigned i = 0; i < MAX; i++)
       for(int j = (i==0); j < 16; j++) {
           if(composite[i] & (1<<j)) continue;
           primes.push_back(num = 60*i + w[j]);
 
           if(i > MAX_S) continue;
           for(unsigned k = i, done = false; !done; k++)
               for(int l = (k==0); l < 16 && !done; l++) {
                   unsigned mult = k*num + i*w[l] + di[j][l];
                   if(mult >= MAX) done = true;
                   else composite[mult] |= 1<<mod[j][l];
               }
       }
}
 
//Fatorizacao do numero em fatores primos
void fact(int n, vector<prime_pot>& fat){
    if(n == 1){
        fat.pb(mp(1, 0));
        return;
    }
    int limit = (int)sqrt(n) + 1;
    prime_pot p;
    for(int i = 0; primes[i] <= limit; i++){
        if((n % primes[i]) == 0){
            p = mp(primes[i], 0);
            while((n % primes[i]) == 0){
                p.second++;
                n /= primes[i];
            }
            fat.pb(p);
            if(n == 1)
                return;
        }
    }
 
    if(n != 1)
        fat.pb(mp(n, 1));
}

int main()
{
    sieve();
    ll n;
    cin >> n;
    ll j = 2LL;
    for(ll k = 1LL; k < n+1; k++){
        vector<prime_pot> pot;
        fact((int)k, pot);
        ll a = 1LL;
        for(int i = 0; i < pot.size(); i++)
            if(pot[i].second % 2)
                a *= (ll)pot[i].first;
        
       
        
        ll p = (k+1)*(k+1) * (ll) a - (j/k);
        ld b = ((ld)j+(ld)k*(ld)p);
        ld c = (ld)sqrt(b);
        if((ll)(c + 0.00001) != (ll)c)
            c = c+ 0.00001;
        j = (ll)c;
        
        cout << p << endl;
        
        //cout << "j: " << j << endl << endl;
        
    }
}