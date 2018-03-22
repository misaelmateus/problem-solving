#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std ;
 
ll resto(ll a){
    ll r = a % mod;
    while(r < 0)
        r += mod;
    return r;
}
void multiply(long long F[2][2], long long M[2][2])
{
  long long x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  long long y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  long long z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  long long w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
  
  F[0][0] = x%mod;
  F[0][1] = y%mod;
  F[1][0] = z%mod;
  F[1][1] = w%mod;
}
  
void power(long long F[2][2], int n)
{
  if( n == 0 || n == 1)
      return;
  long long M[2][2] = {{1,1},{1,0}};
  
  power(F, n/2);
  multiply(F, F);
  
  if (n%2 != 0)
     multiply(F, M);
}
 
long long fib(int n)
{
  long long F[2][2] = {{1,1},{1,0}};
  if (n == 0)
      return 0;
  power( F, n-1);
  
  return F[0][0];
}


int main(){
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        ll resp = 0LL;
        ll a = 0LL, b = 0LL;
        
        ll num;
        cin >> num;
        a = fib(num);
        b = fib(num-1);
        resp += a;
        
        for(int i = 1; i < n; i++){
            cin >> num;
            ll A, B;
            A = resto(b*fib(num) + a*fib(num+1));
            B = resto(b*fib(num-1) + a*fib(num));
            a = A + fib(num);
            b = B + fib(num-1);
            resp = resto(resp + a) ;
        }
        
        cout << resp << endl;
    }
}
