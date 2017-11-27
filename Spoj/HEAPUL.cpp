#include<bits/stdc++.h>
#define MAXN 50010
using namespace std;
struct item{
    string s;
    int b;
} items[MAXN];
int tree[MAXN*4];

int Max(int i, int j){
    if(items[i].b > items[j].b)
        return i;
    return j;
}
int query(int l, int r, int i, int j, int n){
    if(i >= l && j <= r)
        return tree[n];
    int mid = (i + j >> 1);
    if(mid + 1 > r)
        return query(l, r, i, mid, n << 1);
    if(mid < l)
        return query(l, r, mid+1, j, n << 1 | 1);
    return Max(query(l, r, i, mid, n << 1), query(l, r, mid+1, j, n << 1 | 1) ) ;
}
void build(int i, int j, int n){
    if(i == j){
        tree[n] = i;
        return ;
    }
    int mid = (i + j) >> 1;
    build(i, mid, n << 1);
    build(mid+1, j, n << 1 | 1);
    tree[n] = Max(tree[n << 1], tree[n << 1 | 1]);
}

int n;
void print(int i, int j){
    ios::sync_with_stdio(false);    
    if(i > j) return;
    int a = query(i, j, 1, n, 1);
    //cout << a << " ";
    cout << "(";
    print(i, a-1);
    cout << items[a].s;
    print(a+1, j);
    cout << ")";
}

int cmp(item A, item B){
    return A.s < B.s;
}
int main(){
    ios::sync_with_stdio(false);    
    while(cin >> n && n){
        for(int l = 1; l <= n; l++){
            cin >> items[l].s;
            int i;
            int t = items[l].s.size();
            for(i = 0; i< t && items[l].s[i] != '/'; i++);
            i++;

            items[l].b = 0;
            for(; i < t; i++) items[l].b = items[l].b*10 + (int)(items[l].s[i] - '0');
        }
        sort(items+1, items+n+1, cmp);
        build(1, n, 1);
        print(1, n);
        cout << "\n";
    }   
}