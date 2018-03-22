// Don't working correctly

#include<bits/stdc++.h>
#define MAXN 200010
#define MAX 800010
using namespace std;
int n;
set<int> m1;
vector<int> m;
int a[MAXN], b[MAXN];
vector<int> ans;
int tree[MAX];
int mark[MAX];

void build(int i, int j, int n){
    tree[n] = (j - i + 1);
    if(i == j) return;
    int middle = (i + j)/2;
    build(i, middle, 2*n);
    build(middle+1, j, 2*n+1);
}
void propagate(int n, int i, int j)
{
    if(mark[n] == 0)
        return ;
    tree[n] = 0; // update tree
    
    // mark sons
    mark[2*n] += mark[n];
    mark[2*n+1] += mark[n];
    mark[n] = 0;
}
void update(int i, int j, int l, int r, int n)
{
    propagate(n, l, r);
    if(l >= i && r <= j)
    {
        tree[n] = 0; // update current
        mark[2*n] += 1; // mark sons
        mark[2*n + 1] += 1;
        return ;
    }
    if(r < i || l > j)
        return ;
    
    int middle = (l + r) / 2;
    update(i, j, l, middle, 2*n);
    update(i, j, middle + 1, r, 2*n + 1);
    
    tree[n] = tree[2*n] + tree[2*n + 1]; // update current
 
}
int query(int i, int j, int l, int r, int n)
{
    if(r < i || l > j)
        return 0;
    propagate(n, l, r);
    if(l >= i && r <= j)
        return (int) tree[n];

    int middle = (l + r) / 2;
    return query(i, j, l, middle, 2*n) + query(i, j, middle + 1, r, 2*n + 1); // return according to the sons
}

void f(int i, int l, int r, int k){
    if(k == 0 || i == n){
        return ;
    }
    int beg = max(a[i], l);
    int end = min(b[i], r);
    if(beg > end){
        f(i+1, l, r, k);
        return ;
    }
    int pos2 = (int)( upper_bound(m.begin(), m.end(), end) - m.begin()) - 1;
    if(m[pos2] == end) 
        pos2--;
    pos2++;
    int pos1 = (int)( lower_bound(m.begin(), m.end(), beg) - m.begin());
    int tot = query(pos1 + 1, pos2, 1, m.size(), 1);
    
    if(tot >= k){
        ans.push_back(i);
        int aux = 0;
        f(i+1, beg, end, k);
    }
    else{
        update(pos1+1, pos2, 1, m.size(), 1);
        f(i+1, l, r, k - tot);
    }

}
int main(){
    int k;
    cin >> n >> k;
    
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        m1.insert(a[i]);
        m1.insert(b[i]);
    }
    set<vector<int> > s;
    for(auto it = m1.begin(); it != m1.end(); it++){
        vector<int> v;
        for(int j = 0; j < n; j++){
            if(a[j] <= (*it) && b[j] > (*it))
                v.push_back(j);
        }
        if(!s.count(v)){
            s.insert(v);
            m.push_back((*it));
        }
    }
    
    build(1, m.size(), 1);

    
    f(0, 0, 1000000010, k);
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i]+1 << " ";
    }
    cout << endl;
}