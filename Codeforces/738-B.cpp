//   Author : Misael Mateus 
//   Submission date: 2016-11-20 14:34:00
#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define ld long double

using namespace std;
int main(){
    ios::sync_with_stdio( false );
    int n, m;
    cin >> n >> m;
    int ans = 0;
    
    int M[n][m];
    int d[n][m][4]; // top, left, down, right
    memset(d, 0, sizeof(d));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> M[i][j];
            d[i][j][0] = (M[i][j]);
            if(i > 0)
                d[i][j][0] |= (d[i-1][j][0]);
            d[i][j][1] = (M[i][j]);
            if(j > 0)
                d[i][j][1] |= (d[i][j-1][1]);
        }
    }
    
    for(int i = n-1; i >= 0; i--)
        for(int j = m-1; j >= 0; j--){
            d[i][j][2] = (M[i][j]);
            if(i != n-1)
                d[i][j][2] |= (d[i+1][j][2]);
            
            d[i][j][3] = (M[i][j]);
            if(j != m-1)
                d[i][j][3] |= (d[i][j+1][3]);
            
            if(!M[i][j]) 
                ans += d[i][j][0] + d[i][j][1] + d[i][j][2] + d[i][j][3];
        }
        
    cout << ans << endl;
    
}