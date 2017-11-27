//   Author : Misael Mateus 
//   Submission date: 2017-01-18 21:30:52
#include<bits/stdc++.h>
#define ll long long
#define MAXR 1000100
#define LOGR 21
#define L 1000000007LL

 
using namespace std;
ll f[MAXR][LOGR];


//aqui que dtermina o limite dos primos
int isPrime[MAXR];

 
void sieve() {
   isPrime[1] = 1;
   for(int i = 2; i < MAXR; i++){
       
       if(!isPrime[i])
        for(int j = i; j < MAXR; j += i)
            isPrime[j] = i;
   }

}
 

void precalc(){
    for(int i = 0; i < MAXR; i++) f[i][0] = 1LL;
    for(int i = 0; i < LOGR; i++) f[0][i] = 2LL;
    for(int i = 1; i < MAXR; i++)
        for(int j = 1; j < LOGR; j++)
            f[i][j] = (f[i-1][j] + f[i][j-1]) % L;
}
int main(){
    
    sieve(); precalc();
    
    int q;
    scanf("%d", &q);
    
    
    while(q--){
        int r, n;
        scanf("%d %d", &r, &n);
        if(n == 1){
            printf("1\n");
            continue;
        }
        
        
        ll ans = 1;
        while(n != 1){
            
            int d = isPrime[n];
            
            int cnt = 0;
            while(n % d == 0){ n /= d; cnt++; }
            ans = (ans * f[r][cnt] ) % L;
        }
        printf("%I64d\n", ans);
        
    }
}