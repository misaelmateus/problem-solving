#include <bits/stdc++.h>
#define MAXN 100010
#define ll long long
using namespace std;

#define ii pair<int, int>

struct Query{
	int l, r;
    int i;
};
int S; //the max integer number which is less than sqrt(N);
bool cmp(Query A, Query B)
{
  if (A.l / S != B.l / S) return A.l / S < B.l / S;
  return A.r > B.r;
}
int dir[MAXN], esq[MAXN];
int v[MAXN];
Query query[MAXN];
ll ans[MAXN];
ll add_dir(int l, int r){
    int i = max(esq[r+1], l-1);
    return r - i + 1;
}

ll add_esq(int l, int r){
    int i = min(dir[l-1], r+1);
    return i - l + 1;
}   

int ult[MAXN*10];
int main() {
    memset(ult, -1, sizeof(ult));
    int n;
    int q;
    
    scanf("%d %d", &n, &q);
    S = sqrt(n);
    vector<int> A(n);
    for(int A_i = 0; A_i < n; A_i++){
       scanf("%d", &A[A_i]);
        esq[A_i] = ult[A[A_i]];
        if(A_i)
            esq[A_i] = max(esq[A_i], esq[A_i-1]);
        ult[A[A_i]] = A_i;
    }
    memset(ult, -1, sizeof(ult));
    for(int A_i = n-1; A_i >= 0; A_i--){
        dir[A_i] = ult[A[A_i]];
        ult[A[A_i]] = A_i;
        if(dir[A_i] == -1) dir[A_i] = n+1;
        if(A_i < n-1)
            dir[A_i] = min(dir[A_i], dir[A_i+1]);
    }
    
    for(int a0 = 0; a0 < q; a0++){
        scanf("%d %d", &query[a0].l, &query[a0].r);
        query[a0].i = a0;
        // Write Your Code Here
    }
    sort(query, query + q, cmp);
    
    int i = 0, j = 0;
    ll val = 1LL;
    for(int a = 0; a < q; a++){
        int l = query[a].l , r = query[a].r;
        l--, r--;
        while(j < r){
            val += add_dir(i, j);
            j++;
        }
        while(i < l){
            val -= add_esq(i+1, j);
            i++;
        }
        while(i > l){
            val += add_esq(i, j);
            i--;
        }
        while(j > r){
            val -= add_dir(i, j-1);
            j--;
        }
        ans[query[a].i] = val;
    }
    for(int i = 0; i < q; i++)
        printf("%lld\n", ans[i]);
    return 0;
}
