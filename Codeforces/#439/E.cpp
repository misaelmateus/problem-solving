#include<bits/stdc++.h>
#define MAX 2600
#define P 1073741823
#define ii pair<int, int>
#define ll long long
using namespace std;
ll tree[MAX][MAX];

void updatey(int x, int y, ll val)
{
    while(y < MAX)
    {
        tree[x][y] += val;
        y += (y & -y);
    }
}
void update(int x, int y, ll val)
{
    while(x < MAX)
    {
        updatey(x, y, val);
        x += (x & -x);
    }
}
 
ll ready(int x, int y)
{
    ll custo = 0;
    while(y > 0)
    {
        custo += tree[x][y];
        y -= (y & -y);
    }
    return custo;
}
ll read(int x, int y)
{
    ll custo = 0;
    while(x > 0)
    {
        custo += ready(x, y);
        x -= (x & -x);
    }
 
    return custo;
}
map<pair<ii, ii>, ll > mapa;
int main(){

    int n, m, q, t, a1, b1, a2, b2;
    scanf("%d %d %d", &n, &m, &q);

    for(int k = 0; k < q; k++){
        scanf("%d %d %d %d %d", &t, &a1, &b1, &a2, &b2);
            if(t == 1){
            ll val = (rand() << 30) + (rand() << 15) + rand();
            mapa[{{a1, b1}, {a2, b2}}] = val;
            update(a1, b1, val);
            update(a2+1, b2+1, val);
            update(a2+1, b1, -val);
            update(a1, b2+1, -val);
        }
        else if(t == 3){
            if(read(a1, b1) == read(a2, b2))
                printf("Yes\n");
            else printf("No\n");
        }
        else{
            ll val = mapa[{{a1, b1}, {a2, b2}}];
            mapa[{{a1, b1}, {a2, b2}}] = 0;
            update(a1, b1, -val);
            update(a2+1, b2+1, -val);
            update(a2+1, b1, val);
            update(a1, b2+1, val);
        }
    }
}