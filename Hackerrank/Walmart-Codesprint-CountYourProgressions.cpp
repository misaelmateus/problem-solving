#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#define L 1000000009
using namespace std;


int main() {
    int n;
    cin >> n;
    int a[n];
    
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    vector< vector<int> > dp(110, vector<int>(220, 0) );
    int cont = 0;
    
    for(int i = 0; i < n; i++){
        cont++;
        for(int j = -100; j <= 100; j++){
            if(j + a[i] <= 100 && j + a[i] > 0){
                if(dp[a[i] + j][j+101] != 0)
                    cont += dp[a[i] + j][j+101];
                dp[a[i]][j+101] += dp[a[i] + j][j+101] + 1;
            }
            else
                dp[a[i]][j+101]++;
            cont %= L;
            dp[a[i]][j+101] %= L;
        }
        
    }
    
    cout << (cont + 1)%L << endl;
    return 0;
}