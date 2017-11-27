//   Author : Misael Mateus 
//   Submission date: 2017-03-13 16:15:58
// segment tree to get sum in interval, but can be modified to other goals

#include<bits/stdc++.h>
#define MAX 800000
#define ll long long
using namespace std;
 
ll tree[MAX][5];


void update(ll i, ll j, ll l, ll r, ll n, ll k, int p)
{
    if(l >= i && r <= j)
    {
        tree[n][p] = max(tree[n][p], k); // update current
        return ;
    }
    if(r < i || l > j)
        return ;
    
    ll middle = (l + r) / 2;
    update(i, j, l, middle, 2*n, k, p);
    update(i, j, middle + 1, r, 2*n + 1, k, p);
    
    tree[n][p] = max(tree[2*n][p] , tree[2*n + 1][p]); // update current
 
}
ll query(ll i, ll j, ll l, ll r, ll n, ll p)
{
    if(r < i || l > j)
        return 0;
    if(l >= i && r <= j)
        return (ll) tree[n][p];

    ll middle = (l + r) / 2;
    return max(query(i, j, l, middle, 2*n, p), query(i, j, middle + 1, r, 2*n + 1, p) ); // return according to the sons
}


int main(){
    ios::sync_with_stdio( false );
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ll num;
            cin >> num;
            update(i+1, i+1, 1, n, 1, num, j);
        }
    }

    int ans = 0;
    int best[m];
    memset(best, 0,  sizeof(best));
    int i = 0, j = 0;
    while(j < n && i < n){
        if(i > j){
            j++;
            continue;
        }
        ll cont = 0LL;
        int curr[m];
        for(int l = 0; l < m; l++){
            curr[l] = query(i+1, j+1, 1, n, 1, l);
            cont += curr[l];
        }
        if(cont <= k){
            if(ans < j - i + 1){
                ans = j - i+1;
                for(int j = 0; j < m; j++)
                    best[j] = curr[j];
            }

            j++;

        }
        else
            i++;
    }
    
    for(int i = 0; i < m; i++)
        cout << best[i] << " ";
    cout << endl;
}
