//   Author : Misael Mateus 
//   Submission date: 2017-11-01 21:30:46
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int s[n], g[n];
    for(int i = 0; i < n; i++){
        cin >> s[i] >> g[i];
    }

    int ma[n], mi[n];
    mi[0] = s[0];
    ma[0] = s[0] + g[0];
    for(int i = 1; i < n; i++){
        mi[i] = max(mi[i-1]-1, s[i]);
        ma[i] = min(ma[i-1]+1, s[i]+g[i]);
        if(ma[i] < mi[i]) {
            cout << "-1\n";
            return 0;
        }
    }
    long long tot = 0LL;
    int t = ma[n-1];
    tot += 1LL*t-s[n-1];
    vector<int> ans;

    ans.push_back(t);

    for(int i = n-2; i >= 0; i--){
        if(t > ma[i]) t--;
        if(t < mi[i]) t++;
        else if(t < ma[i]) t++;
        tot += 1LL *(t - s[i]);
        ans.push_back(t);
    }

    cout << tot << "\n";
    for(int i = ans.size()-1; i >= 0; i--) cout << ans[i] << " ";
    cout << "\n";
}
