//   Author : Misael Mateus 
//   Submission date: 2016-11-21 19:33:22
#include<bits/stdc++.h>
#define MAXN 4010
#define MAXV 1000000000


int sum[MAXN];
int n;
using namespace std;
int g(int i, int j){
    return i - (n - j) + 111;
}
int dp[MAXN][223][111];
int f(int i, int j, int k, int flag){
    if(i + k - 1 > j)
        return 0;
    if(dp[i][g(i, j)][k]){
        int ans = dp[i][g(i, j)][k];
        if(ans == MAXV)// caso resposta seja 0 eu armazeno no m[] MAXV
            return 0;
        return ans;
    }
    int ans;
    if(!flag){
        int a = sum[i+k-1] - sum[i-1];
        ans = a - f(i+k, j, k, 1-flag);
        if(i+k <= j){
            int b = sum[i+k] - sum[i-1];
            ans = max(ans, b - f(i+k+1, j, k+1, 1-flag));
            
        }
    
    }
    else
    {
        int a = sum[j] - sum[j-k];
        ans = a - f(i, j-k, k, 1-flag);
        if(j-k >= i){
            int b = sum[j] - sum[j-(k+1)];
            ans =  max(ans, b - f(i, j-(k+1), k+1, 1-flag));
        }
    }
    
    if(ans == 0)
        dp[i][g(i, j)][k] = MAXV;
    else
        dp[i][g(i, j)][k] = ans;
    //cout << i << " " << j << " " << ans << endl;
    return ans;
}
int main(){
    ios::sync_with_stdio( false );
    
    cin >> n;
    int a[n+1];
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sum[0] = 0;
    sum[1] = a[1];
    for(int i = 2; i <= n; i++)
        sum[i] = sum[i-1] + a[i];
    
    cout << f(1, n, 1, 0) << endl;
    
    return 0;
}#include<bits/stdc++.h>
#define MAXN 4010
#define MAXV 1000000000


int sum[MAXN];
int n;
using namespace std;
int g(int i, int j){
    return i - (n - j) + 111;
}
int dp[MAXN][223][111];
int f(int i, int j, int k, int flag){
    if(i + k - 1 > j)
        return 0;
    if(dp[i][g(i, j)][k]){
        int ans = dp[i][g(i, j)][k];
        if(ans == MAXV)// caso resposta seja 0 eu armazeno no m[] MAXV
            return 0;
        return ans;
    }
    int ans;
    if(!flag){
        int a = sum[i+k-1] - sum[i-1];
        ans = a - f(i+k, j, k, 1-flag);
        if(i+k <= j){
            int b = sum[i+k] - sum[i-1];
            ans = max(ans, b - f(i+k+1, j, k+1, 1-flag));
            
        }
    
    }
    else
    {
        int a = sum[j] - sum[j-k];
        ans = a - f(i, j-k, k, 1-flag);
        if(j-k >= i){
            int b = sum[j] - sum[j-(k+1)];
            ans =  max(ans, b - f(i, j-(k+1), k+1, 1-flag));
        }
    }
    
    if(ans == 0)
        dp[i][g(i, j)][k] = MAXV;
    else
        dp[i][g(i, j)][k] = ans;
    //cout << i << " " << j << " " << ans << endl;
    return ans;
}
int main(){
    ios::sync_with_stdio( false );
    
    cin >> n;
    int a[n+1];
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sum[0] = 0;
    sum[1] = a[1];
    for(int i = 2; i <= n; i++)
        sum[i] = sum[i-1] + a[i];
    
    cout << f(1, n, 1, 0) << endl;
    
    return 0;
}#include<bits/stdc++.h>
#define MAXN 4010
#define MAXV 1000000000


int sum[MAXN];
int n;
using namespace std;
int g(int i, int j){
    return i - (n - j) + 111;
}
int dp[MAXN][223][111];
int f(int i, int j, int k, int flag){
    if(i + k - 1 > j)
        return 0;
    if(dp[i][g(i, j)][k]){
        int ans = dp[i][g(i, j)][k];
        if(ans == MAXV)// caso resposta seja 0 eu armazeno no m[] MAXV
            return 0;
        return ans;
    }
    int ans;
    if(!flag){
        int a = sum[i+k-1] - sum[i-1];
        ans = a - f(i+k, j, k, 1-flag);
        if(i+k <= j){
            int b = sum[i+k] - sum[i-1];
            ans = max(ans, b - f(i+k+1, j, k+1, 1-flag));
            
        }
    
    }
    else
    {
        int a = sum[j] - sum[j-k];
        ans = a - f(i, j-k, k, 1-flag);
        if(j-k >= i){
            int b = sum[j] - sum[j-(k+1)];
            ans =  max(ans, b - f(i, j-(k+1), k+1, 1-flag));
        }
    }
    
    if(ans == 0)
        dp[i][g(i, j)][k] = MAXV;
    else
        dp[i][g(i, j)][k] = ans;
    //cout << i << " " << j << " " << ans << endl;
    return ans;
}
int main(){
    ios::sync_with_stdio( false );
    
    cin >> n;
    int a[n+1];
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sum[0] = 0;
    sum[1] = a[1];
    for(int i = 2; i <= n; i++)
        sum[i] = sum[i-1] + a[i];
    
    cout << f(1, n, 1, 0) << endl;
    
    return 0;
}#include<bits/stdc++.h>
#define MAXN 4010
#define MAXV 1000000000


int sum[MAXN];
int n;
using namespace std;
int g(int i, int j){
    return i - (n - j) + 111;
}
int dp[MAXN][223][111];
int f(int i, int j, int k, int flag){
    if(i + k - 1 > j)
        return 0;
    if(dp[i][g(i, j)][k]){
        int ans = dp[i][g(i, j)][k];
        if(ans == MAXV)// caso resposta seja 0 eu armazeno no m[] MAXV
            return 0;
        return ans;
    }
    int ans;
    if(!flag){
        int a = sum[i+k-1] - sum[i-1];
        ans = a - f(i+k, j, k, 1-flag);
        if(i+k <= j){
            int b = sum[i+k] - sum[i-1];
            ans = max(ans, b - f(i+k+1, j, k+1, 1-flag));
            
        }
    
    }
    else
    {
        int a = sum[j] - sum[j-k];
        ans = a - f(i, j-k, k, 1-flag);
        if(j-k >= i){
            int b = sum[j] - sum[j-(k+1)];
            ans =  max(ans, b - f(i, j-(k+1), k+1, 1-flag));
        }
    }
    
    if(ans == 0)
        dp[i][g(i, j)][k] = MAXV;
    else
        dp[i][g(i, j)][k] = ans;
    //cout << i << " " << j << " " << ans << endl;
    return ans;
}
int main(){
    ios::sync_with_stdio( false );
    
    cin >> n;
    int a[n+1];
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sum[0] = 0;
    sum[1] = a[1];
    for(int i = 2; i <= n; i++)
        sum[i] = sum[i-1] + a[i];
    
    cout << f(1, n, 1, 0) << endl;
    
    return 0;
}