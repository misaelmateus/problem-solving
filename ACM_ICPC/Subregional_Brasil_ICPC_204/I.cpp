#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
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
 int intpow(int a, int n){
    int res = 1, pot = a;
     
    while(n){
        if(n & 1)
            res *= pot;
        pot *= pot;
        n >>= 1;
    }
    return res;  
}
//Funcao phi de Euler
//Quantidade de numeros menores que n tais que mdc(x, n) = 1
int phi(vector<prime_pot>& fat){
    int res = 1;
    vector<prime_pot>::iterator it;
    for(it = fat.begin(); it != fat.end(); it++){
        res *=  intpow(it->first, it->second - 1)*(it->first - 1);
    }
    return res;
}

int P;
int mdc(int  a, int b, int *x, int *y) {
  int xx, yy, d;
  if(b==0) {
    *x=1; *y=0;
    return a;
  }
 
  d = mdc(b, a%b, &xx, &yy);
  *x = yy;
  *y = xx - a/b*yy;
  return d;
}
 
 
int inv(int a){
  int x,y,d;
  d = mdc(a,P,&x,&y);
 
  if(x<0){
    x = x+P;
  }
 
  return x;
 
 
}

//exponenciacao logaritmica
int pot(int a, int n){
    int res = 1, pot = a;
     
    while(n){
        if(n & 1)
            res = ((long long)res*pot) % P;
        pot = ((long long)pot * pot) % P;
        n >>= 1;
    }
    return res;  
}

int main(){
	sieve();
	int N, E, C;
	scanf("%d %d %d", &N, &E, &C);
	vector<prime_pot> fat;
	fact(N, fat);
	int ph = phi(fat);
	P = ph;
	int D = inv(E);
	P = N;
	int M = pot(C, D);

	printf("%d\n", M);
}	