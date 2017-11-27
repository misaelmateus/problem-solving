//   Author : Misael Mateus 
//   Submission date: 2016-10-03 21:07:03
#include<bits/stdc++.h>
#define MAXN 100
#define ii pair<int, int>
using namespace std;

int n, m, k;
int pX[] = {1, -1, 0, 0};
int pY[] = {0, 0, 1, -1};
int mark[MAXN][MAXN];
string s[MAXN];

bool cmp(set< ii > a, set< ii > b){
    return a.size() < b.size();
}
void dfs1(int i, int j){
    s[i][j] = 'a'; 
    
    for(int l = 0; l < 4; l++){
        int x = i + pX[l];
        int y = j + pY[l];
        
        if(x < 0 || y < 0 || x >= n || y >= m || s[x][y] != '.')
            continue;
            
        dfs1(x, y);
    }
    
}

void dfs(int i, int j, set<ii >& c){
     c.insert({i, j});
     mark[i][j] = 1;
     for(int l = 0; l < 4; l++){
        int x = i + pX[l];
        int y = j + pY[l];
        
        if(x < 0 || y < 0 || x >= n || y >= m || s[x][y] != '.' || mark[x][y])
            continue;
        dfs(x, y, c);
        
    }
}
int main(){
    cin >> n >> m >> k;
    vector< set<ii> > v;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    
    for(int i = 0; i < n; i++){
        if(s[i][0] == '.')
            dfs1(i, 0);
        if(s[i][m-1] == '.')
            dfs1(i, m-1);
    }
    for(int i = 0; i < m; i++){
        if(s[0][i] == '.')
            dfs1(0, i);
        if(s[n-1][i] == '.')
            dfs1(n-1, i);
    }
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(s[i][j] == '.' && !mark[i][j]){
                set<ii> c;
                dfs(i, j, c);
                v.push_back(c);
            }
        }
    
    
    sort(v.begin(), v.end(), cmp);
    int res = 0;
    
    for(int i = 0; i < v.size() - k; i++){
        res += v[i].size();
        set< ii >:: iterator it = v[i].begin(); 
        for( ; it!= v[i].end(); ++it)
            s[(*it).first][(*it).second] = '*';
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            s[i][j] = (s[i][j] == 'a') ? '.' : s[i][j];
    cout << res << endl;
    for(int i = 0; i < n; i++)
        cout << s[i] << endl;
    return 0;
}