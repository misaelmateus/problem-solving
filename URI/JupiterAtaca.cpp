#include<bits/stdc++.h>
#define MAXN 100010
#define ll long long
using namespace std;
ll P;
int mult[MAXN], inv_mult[MAXN];
int f[MAXN];
int tree[MAXN];
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

int query(int k){
  int ans =0;
  while(k > 0){
    ans = (ans + tree[k]) % P;
    k -= (k & -k);
  }
  return ans;
}

int query(int a, int b){
  int ans = query(b) - query(a-1);
  ans = (ans + P) % P;
  ans = ((ll)ans * inv_mult[b]) % P;
  return ans;
}
int update(int k, int val){
  while(k < MAXN){
    tree[k] = ((tree[k] + val) % P + P) % P;
    k += (k & -k);
  }
}

int main(){
  int B, N, L, inv_B;
  while(scanf("%d %lld %d %d", &B, &P, &L, &N) && N){ 
    memset(tree, 0, sizeof(tree));
    memset(f, 0, sizeof(f));
    mult[L] = inv_mult[L] = 1;
    for(int i = L-1; i >= 0; i--){
      mult[i] = ((ll) mult[i+1] * B) % P;
      inv_mult[i] = ((ll) inv_mult[i+1] * inv(B)) % P;
    }

    while(N--){
      char c;
      int a, b;
      scanf(" %c %d %d", &c, &a, &b);
      if(c == 'E'){
        update(a, -f[a]);
        f[a] = ((ll)b*mult[a]) % P;
        //cout << f[a] << endl;
        update(a, +f[a]);
      }
      else{
        printf("%d\n", query(a, b));
      }
    }
    printf("-\n");
  }
  return 0;
}