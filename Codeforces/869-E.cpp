//   Author : Misael Mateus 
//   Submission date: 2017-10-06 19:46:47
#include<bits/stdc++.h>
#define MAX 2600
#define P 1073741823
#define ii pair<int, int>
#define ll long long
using namespace std;
ll tree[MAX][MAX][2];

void updatey(int x, int y, ll val, int k)
{
    while(y < MAX)
    {
        tree[x][y][k] += val;
        y += (y & -y);
    }
}
void update(int x, int y, ll val, int k)
{
    while(x < MAX)
    {
        updatey(x, y, val, k);
        x += (x & -x);
    }
}
 
ll ready(int x, int y, int k)
{
    ll custo = 0;
    while(y > 0)
    {
        custo += tree[x][y][k];
        y -= (y & -y);
    }
    return custo;
}
ll read(int x, int y, int k)
{
    ll custo = 0;
    while(x > 0)
    {
        custo += ready(x, y, k);
        x -= (x & -x);
    }
 
    return custo;
}
map<pair<ii, ii>, pair<ll, ll> > mapa;
int main(){
    int n, m, q, t, a1, b1, a2, b2;
    scanf("%d %d %d", &n, &m, &q);
    srand(time(NULL));

    for(int k = 0; k < q; k++){
        scanf("%d %d %d %d %d", &t, &a1, &b1, &a2, &b2);
            if(t == 1){
            ll val1 = ((ll)(rand()) << 30 + (rand()) << 15)  + (ll)rand();
            ll val2 = ((ll)(rand() ) << 30 + (rand()) << 15)  + (ll)rand();
            mapa[{{a1, b1}, {a2, b2}}] = {val1, val2};
            update(a1, b1, val1, 0);
            update(a2+1, b2+1, val1, 0);
            update(a2+1, b1, -val1, 0);
            update(a1, b2+1, -val1, 0);

            update(a1, b1, val2, 1);
            update(a2+1, b2+1, val2, 1);
            update(a2+1, b1, -val2, 1);
            update(a1, b2+1, -val2, 1);
        }
        else if(t == 3){
            if(read(a1, b1, 0) == read(a2, b2, 0) && read(a1, b1, 1) == read(a2, b2, 1))
                printf("Yes\n");
            else printf("No\n");
        }
        else{
            ll val1 = mapa[{{a1, b1}, {a2, b2}}].first;
            ll val2 = mapa[{{a1, b1}, {a2, b2}}].second;
            mapa[{{a1, b1}, {a2, b2}}] = {0, 0};
            update(a1, b1, -val1, 0);
            update(a2+1, b2+1, -val1, 0);
            update(a2+1, b1, val1, 0);
            update(a1, b2+1, val1, 0);

            update(a1, b1, -val2, 1);
            update(a2+1, b2+1, -val2, 1);
            update(a2+1, b1, val2, 1);
            update(a1, b2+1, val2, 1);
        }
    }
}#include<bits/stdc++.h>
#define MAX 2600
#define P 1073741823
#define ii pair<int, int>
#define ll long long
using namespace std;
ll tree[MAX][MAX][2];

void updatey(int x, int y, ll val, int k)
{
    while(y < MAX)
    {
        tree[x][y][k] += val;
        y += (y & -y);
    }
}
void update(int x, int y, ll val, int k)
{
    while(x < MAX)
    {
        updatey(x, y, val, k);
        x += (x & -x);
    }
}
 
ll ready(int x, int y, int k)
{
    ll custo = 0;
    while(y > 0)
    {
        custo += tree[x][y][k];
        y -= (y & -y);
    }
    return custo;
}
ll read(int x, int y, int k)
{
    ll custo = 0;
    while(x > 0)
    {
        custo += ready(x, y, k);
        x -= (x & -x);
    }
 
    return custo;
}
map<pair<ii, ii>, pair<ll, ll> > mapa;
int main(){
    int n, m, q, t, a1, b1, a2, b2;
    scanf("%d %d %d", &n, &m, &q);
    srand(time(NULL));

    for(int k = 0; k < q; k++){
        scanf("%d %d %d %d %d", &t, &a1, &b1, &a2, &b2);
            if(t == 1){
            ll val1 = ((ll)(rand()) << 30 + (rand()) << 15)  + (ll)rand();
            ll val2 = ((ll)(rand() ) << 30 + (rand()) << 15)  + (ll)rand();
            mapa[{{a1, b1}, {a2, b2}}] = {val1, val2};
            update(a1, b1, val1, 0);
            update(a2+1, b2+1, val1, 0);
            update(a2+1, b1, -val1, 0);
            update(a1, b2+1, -val1, 0);

            update(a1, b1, val2, 1);
            update(a2+1, b2+1, val2, 1);
            update(a2+1, b1, -val2, 1);
            update(a1, b2+1, -val2, 1);
        }
        else if(t == 3){
            if(read(a1, b1, 0) == read(a2, b2, 0) && read(a1, b1, 1) == read(a2, b2, 1))
                printf("Yes\n");
            else printf("No\n");
        }
        else{
            ll val1 = mapa[{{a1, b1}, {a2, b2}}].first;
            ll val2 = mapa[{{a1, b1}, {a2, b2}}].second;
            mapa[{{a1, b1}, {a2, b2}}] = {0, 0};
            update(a1, b1, -val1, 0);
            update(a2+1, b2+1, -val1, 0);
            update(a2+1, b1, val1, 0);
            update(a1, b2+1, val1, 0);

            update(a1, b1, -val2, 1);
            update(a2+1, b2+1, -val2, 1);
            update(a2+1, b1, val2, 1);
            update(a1, b2+1, val2, 1);
        }
    }
}#include<bits/stdc++.h>
#define MAX 2600
#define P 1073741823
#define ii pair<int, int>
#define ll long long
using namespace std;
ll tree[MAX][MAX][2];

void updatey(int x, int y, ll val, int k)
{
    while(y < MAX)
    {
        tree[x][y][k] += val;
        y += (y & -y);
    }
}
void update(int x, int y, ll val, int k)
{
    while(x < MAX)
    {
        updatey(x, y, val, k);
        x += (x & -x);
    }
}
 
ll ready(int x, int y, int k)
{
    ll custo = 0;
    while(y > 0)
    {
        custo += tree[x][y][k];
        y -= (y & -y);
    }
    return custo;
}
ll read(int x, int y, int k)
{
    ll custo = 0;
    while(x > 0)
    {
        custo += ready(x, y, k);
        x -= (x & -x);
    }
 
    return custo;
}
map<pair<ii, ii>, pair<ll, ll> > mapa;
int main(){
    int n, m, q, t, a1, b1, a2, b2;
    scanf("%d %d %d", &n, &m, &q);
    srand(time(NULL));

    for(int k = 0; k < q; k++){
        scanf("%d %d %d %d %d", &t, &a1, &b1, &a2, &b2);
            if(t == 1){
            ll val1 = ((ll)(rand()) << 30 + (rand()) << 15)  + (ll)rand();
            ll val2 = ((ll)(rand() ) << 30 + (rand()) << 15)  + (ll)rand();
            mapa[{{a1, b1}, {a2, b2}}] = {val1, val2};
            update(a1, b1, val1, 0);
            update(a2+1, b2+1, val1, 0);
            update(a2+1, b1, -val1, 0);
            update(a1, b2+1, -val1, 0);

            update(a1, b1, val2, 1);
            update(a2+1, b2+1, val2, 1);
            update(a2+1, b1, -val2, 1);
            update(a1, b2+1, -val2, 1);
        }
        else if(t == 3){
            if(read(a1, b1, 0) == read(a2, b2, 0) && read(a1, b1, 1) == read(a2, b2, 1))
                printf("Yes\n");
            else printf("No\n");
        }
        else{
            ll val1 = mapa[{{a1, b1}, {a2, b2}}].first;
            ll val2 = mapa[{{a1, b1}, {a2, b2}}].second;
            mapa[{{a1, b1}, {a2, b2}}] = {0, 0};
            update(a1, b1, -val1, 0);
            update(a2+1, b2+1, -val1, 0);
            update(a2+1, b1, val1, 0);
            update(a1, b2+1, val1, 0);

            update(a1, b1, -val2, 1);
            update(a2+1, b2+1, -val2, 1);
            update(a2+1, b1, val2, 1);
            update(a1, b2+1, val2, 1);
        }
    }
}#include<bits/stdc++.h>
#define MAX 2600
#define P 1073741823
#define ii pair<int, int>
#define ll long long
using namespace std;
ll tree[MAX][MAX][2];

void updatey(int x, int y, ll val, int k)
{
    while(y < MAX)
    {
        tree[x][y][k] += val;
        y += (y & -y);
    }
}
void update(int x, int y, ll val, int k)
{
    while(x < MAX)
    {
        updatey(x, y, val, k);
        x += (x & -x);
    }
}
 
ll ready(int x, int y, int k)
{
    ll custo = 0;
    while(y > 0)
    {
        custo += tree[x][y][k];
        y -= (y & -y);
    }
    return custo;
}
ll read(int x, int y, int k)
{
    ll custo = 0;
    while(x > 0)
    {
        custo += ready(x, y, k);
        x -= (x & -x);
    }
 
    return custo;
}
map<pair<ii, ii>, pair<ll, ll> > mapa;
int main(){
    int n, m, q, t, a1, b1, a2, b2;
    scanf("%d %d %d", &n, &m, &q);
    srand(time(NULL));

    for(int k = 0; k < q; k++){
        scanf("%d %d %d %d %d", &t, &a1, &b1, &a2, &b2);
            if(t == 1){
            ll val1 = ((ll)(rand()) << 30 + (rand()) << 15)  + (ll)rand();
            ll val2 = ((ll)(rand() ) << 30 + (rand()) << 15)  + (ll)rand();
            mapa[{{a1, b1}, {a2, b2}}] = {val1, val2};
            update(a1, b1, val1, 0);
            update(a2+1, b2+1, val1, 0);
            update(a2+1, b1, -val1, 0);
            update(a1, b2+1, -val1, 0);

            update(a1, b1, val2, 1);
            update(a2+1, b2+1, val2, 1);
            update(a2+1, b1, -val2, 1);
            update(a1, b2+1, -val2, 1);
        }
        else if(t == 3){
            if(read(a1, b1, 0) == read(a2, b2, 0) && read(a1, b1, 1) == read(a2, b2, 1))
                printf("Yes\n");
            else printf("No\n");
        }
        else{
            ll val1 = mapa[{{a1, b1}, {a2, b2}}].first;
            ll val2 = mapa[{{a1, b1}, {a2, b2}}].second;
            mapa[{{a1, b1}, {a2, b2}}] = {0, 0};
            update(a1, b1, -val1, 0);
            update(a2+1, b2+1, -val1, 0);
            update(a2+1, b1, val1, 0);
            update(a1, b2+1, val1, 0);

            update(a1, b1, -val2, 1);
            update(a2+1, b2+1, -val2, 1);
            update(a2+1, b1, val2, 1);
            update(a1, b2+1, val2, 1);
        }
    }
}