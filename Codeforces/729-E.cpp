//   Author : Misael Mateus 
//   Submission date: 2016-11-21 14:36:04
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, s;
    cin >> n >> s;
    vector<int> a(n+1);
    vector<int> q(n, 0);
    int ans = 0;
    int max_level = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(i == s && a[i] != 0)
            a[i] = 0, ans++;
        q[a[i]]++;
        if(a[i] > max_level)
            max_level = a[i];
    }
    
    int i = 0;
    while(i != max_level){
        if(q[i] != 0){
            i++;
            continue;
        }
        if(q[max_level] == 0){
            max_level--;
            continue;
        }
        if(q[0] > 1)
            q[0]--, q[i]++, ans++;
        else{
            q[max_level]--, q[i]++, ans++;
        }
    }
    
    ans += q[0] - 1;
    cout << ans << endl;
    
}