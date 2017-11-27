//   Author : Misael Mateus 
//   Submission date: 2017-01-12 22:12:02
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#define pb push_back
#define mp make_pair
 
//Fatorizacao - Funcao phi - Funcao sigma
  
using namespace std;
 
typedef pair<int, int> prime_pot;
typedef long long int64;
 
//aqui que dtermina o limite dos primos
const unsigned MAX = 1000/60, MAX_S = sqrt(MAX/60);
 
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
int main(){
     ios::sync_with_stdio( false );
    sieve();
    

    map<int, int> mapa;
    int n;
    cin >> n;
    int ans = 1;
    while(n--){
        int num;
        cin >> num;
        vector<prime_pot> fat;
        fact(num, fat);
        for(int i = 0; i < fat.size(); i++){
            mapa[fat[i].first]++;
            ans = max(ans, mapa[fat[i].first]);
        }
    }
    
    cout << ans << endl;
    
}#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#define pb push_back
#define mp make_pair
 
//Fatorizacao - Funcao phi - Funcao sigma
  
using namespace std;
 
typedef pair<int, int> prime_pot;
typedef long long int64;
 
//aqui que dtermina o limite dos primos
const unsigned MAX = 1000/60, MAX_S = sqrt(MAX/60);
 
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
int main(){
     ios::sync_with_stdio( false );
    sieve();
    

    map<int, int> mapa;
    int n;
    cin >> n;
    int ans = 1;
    while(n--){
        int num;
        cin >> num;
        vector<prime_pot> fat;
        fact(num, fat);
        for(int i = 0; i < fat.size(); i++){
            mapa[fat[i].first]++;
            ans = max(ans, mapa[fat[i].first]);
        }
    }
    
    cout << ans << endl;
    
}#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#define pb push_back
#define mp make_pair
 
//Fatorizacao - Funcao phi - Funcao sigma
  
using namespace std;
 
typedef pair<int, int> prime_pot;
typedef long long int64;
 
//aqui que dtermina o limite dos primos
const unsigned MAX = 1000/60, MAX_S = sqrt(MAX/60);
 
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
int main(){
     ios::sync_with_stdio( false );
    sieve();
    

    map<int, int> mapa;
    int n;
    cin >> n;
    int ans = 1;
    while(n--){
        int num;
        cin >> num;
        vector<prime_pot> fat;
        fact(num, fat);
        for(int i = 0; i < fat.size(); i++){
            mapa[fat[i].first]++;
            ans = max(ans, mapa[fat[i].first]);
        }
    }
    
    cout << ans << endl;
    
}#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#define pb push_back
#define mp make_pair
 
//Fatorizacao - Funcao phi - Funcao sigma
  
using namespace std;
 
typedef pair<int, int> prime_pot;
typedef long long int64;
 
//aqui que dtermina o limite dos primos
const unsigned MAX = 1000/60, MAX_S = sqrt(MAX/60);
 
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
int main(){
     ios::sync_with_stdio( false );
    sieve();
    

    map<int, int> mapa;
    int n;
    cin >> n;
    int ans = 1;
    while(n--){
        int num;
        cin >> num;
        vector<prime_pot> fat;
        fact(num, fat);
        for(int i = 0; i < fat.size(); i++){
            mapa[fat[i].first]++;
            ans = max(ans, mapa[fat[i].first]);
        }
    }
    
    cout << ans << endl;
    
}