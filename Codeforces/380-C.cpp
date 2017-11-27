//   Author : Misael Mateus 
//   Submission date: 2017-03-28 16:55:45
#include<bits/stdc++.h>
#define MAX 5000100
#define ll int

using namespace std;
 
ll tree[MAX];
ll value[MAX/4];
char s[MAX/4];

void update(ll i, ll j, ll l, ll r, ll n, ll k)
{
    if(l >= i && r <= j)
    {
        tree[n] = min(tree[n], k);
        return ;
    }
    if(r < i || l > j)
        return ;
    
    ll middle = (l + r) / 2;
    update(i, j, l, middle, 2*n, k);
    update(i, j, middle + 1, r, 2*n + 1, k);
    
    tree[n] = min(tree[2*n], tree[2*n + 1]); // update current
 
}
ll query(ll i, ll j, ll l, ll r, ll n)
{
    if(r < i || l > j)
        return MAX;
    if(l >= i && r <= j)
        return (ll) tree[n];

    ll middle = (l + r) / 2;
    return min(query(i, j, l, middle, 2*n), query(i, j, middle + 1, r, 2*n + 1)); // return according to the sons
}
int main()
{
    for(int i = 0; i < MAX; i++)
        tree[i] = MAX;
    scanf("%s", s);
    int t = strlen(s);
    int v = 0;
    for(int i = 0; i < t; i++){
        v += (-1)*(s[i] == ')') + (s[i] == '(');
        update(i+1, i+1, 1, t, 1, v);
        value[i+1] = v;
    }

    int q;
    int a, b, ult;
    scanf("%d", &q);

    while(q--){
        scanf("%d %d", &a, &b);
        int resp = b - a + 1 + min(0, 2*query(a, b, 1, t, 1) - 2*value[a-1])  - value[b] + value[a-1];
        printf("%d\n", resp);
    }
}
