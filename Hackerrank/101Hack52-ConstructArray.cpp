#include <bits/stdc++.h>
#define MOD 1000000007LL
#define MAXN 100100
#define ll long long
using namespace std;
ll dp[MAXN][2];
long countArray(int n, int k, int x) {
    // Return the number of ways to fill in the array.
    dp[1][0] = (ll)(x != 1);
    dp[1][1] = (ll)(x == 1);
    for(int i = 2; i <= n; i++){
        dp[i][0] = dp[i-1][1]*(ll)(k-1) + dp[i-1][0] *((ll)(k-2));
        dp[i][0] %= MOD;
        dp[i][1] = dp[i-1][0];
    }

    return dp[n][1];
}

int main() {
    int n;
    int k;
    int x;
    cin >> n >> k >> x;
    long answer = countArray(n, k, x);
    cout << answer << endl;
    return 0;
}
