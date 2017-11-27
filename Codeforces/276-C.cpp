//   Author : Misael Mateus 
//   Submission date: 2016-05-04 15:44:25
#include<bits/stdc++.h>
#define ll long long
#define MAXN 401000
ll tree[MAXN], N, C[MAXN];
ll read(ll x)
{
    ll soma = 0;
    while(x > 0)
    {
        soma += tree[x];
        x -= (x & -x);
    }
    return soma;
}
void update(ll x, ll val)
{
    while(x <= N)
    {
        tree[x] += val;
        x += (x & -x);
    }
}
using namespace std;
int main()
{
    ll n, q;
    scanf("%I64d %I64d", &N, &q);

    for(ll i = 0; i < N; i++)
        scanf("%I64d", &C[i]);
    sort(C, C+N);

    for(ll i = 0; i < q; i++)
    {
        ll l, r;
        scanf("%I64d %I64d", &l, &r);
        update(r+1, -1);
        update(l, 1);
    }
    ll M[N];
    for(ll i = 0; i < N; i++)
        M[i] = read(i+1);
    sort(M, M+N);
    ll soma = 0LL;
    for(int i = 0; i < N; i++)
    {
        soma += M[i]*C[i];
    }
    printf("%I64d", soma);

    return 0;

}
