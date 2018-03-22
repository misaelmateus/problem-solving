#include <bits/stdc++.h>

using namespace std;
int c[300][300];
pair<int, int> parent[300][300];
int m_j[] = {-1, 1, 2, 1, -1, -2};
int m_i[] = {-2, -2, 0, 2, 2, 0};

string movement[] = {"UL", "UR", "R", "LR", "LL", "L"};
void printShortestPath(int n, int i0, int j0, int i1, int j1) {
    memset(c, -1, sizeof(c));
    queue<pair<int, int> > q;
    
    q.push({i0, j0});
    c[i0][j0] = 0;
    while(q.size()){
        auto p = q.front();
        q.pop();
        
        for(int l = 0; l < 6; l++){
            int i = p.first + m_i[l];
            int j = p.second + m_j[l];
            
            if(i < 0 || j < 0 || i >= n || j >= n || c[i][j] != -1)
                continue;
            q.push({i, j});
            c[i][j] = c[p.first][p.second] + 1;
            parent[i][j] = p;
        }
    }
    if(c[i1][j1] == -1)
        cout << "Impossible\n";
    else{
        cout << c[i1][j1] << "\n";
        vector<string> ans;
        while(i1 != i0 || j1 != j0){
            auto p = parent[i1][j1];
            for(int l = 0; l < 6; l++){
                if(p.first + m_i[l] == i1 && p.second + m_j[l] == j1)
                    ans.push_back(movement[l]);
            }
            i1 = p.first, j1 = p.second;
        }
        reverse(ans.begin(), ans.end());
        for(auto u : ans)
            cout << u << " ";
    }
}

int main() {
    int n;
    cin >> n;
    int i_start;
    int j_start;
    int i_end;
    int j_end;
    cin >> i_start >> j_start >> i_end >> j_end;
    printShortestPath(n, i_start, j_start, i_end, j_end);
    return 0;
}
