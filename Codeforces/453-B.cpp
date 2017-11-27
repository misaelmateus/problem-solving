//   Author : Misael Mateus 
//   Submission date: 2016-08-15 23:38:39
#include<bits/stdc++.h>
#define MAXN 111
using namespace std;
vector<int> a;
int n;
int dp[MAXN][(1 << 17)];
int primos[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
int bitmask[61];
void pre(){
    for(int j = 1; j <= 60; j++)
    {
        for(int l = 0; l < 17; l++)
            if(j % primos[l] == 0)
                bitmask[j] += (1 << l);
    }
}
int f2(int i, int mask){
    if(i >= n)
        return 0;
     if(i > 0)
            printf(" ");  
     for(int j = 1; j <= 60; j++ ){
        int mask1 = bitmask[j];;
        if(mask & mask1)
            continue;
        if((dp[i+1][mask | mask1] == -1 ? 0 : dp[i+1][mask | mask1]) + abs(j - a[i]) == dp[i][mask] ){
            printf("%d", j);
            f2(i+1, mask|mask1);
            break;
        }
                
     }
}
int f(int i, int mask){
    if(i >= n)
        return 0;
    if(dp[i][mask] != -1)
        return dp[i][mask];
    dp[i][mask] = 10000000;

    for(int j = 1; j <= 60; j++ ){
        int mask1 = bitmask[j];
        
        
        if(mask1 & mask)
            continue;
        
        if(dp[i][mask] > f(i+1, mask | mask1) + abs(j - a[i])){
            dp[i][mask] = f(i+1, mask | mask1) + abs(j - a[i]);
        }
    }

    return dp[i][mask];
}
int main(){
    cin >> n;
    pre();
    a = vector<int>(n);
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    f(0, 0);
    f2(0, 0);
    cout << endl;
    
    return 0;
}