//   Author : Misael Mateus 
//   Submission date: 2016-08-29 17:21:10
#include<bits/stdc++.h>
#define ll long long 
#define ii pair<int, int>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s[n];
    bool flag = 0;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        if(!flag && s[i][0] == 'O' && s[i][1] == 'O')
            flag = 1, s[i][0] = s[i][1] = '+';
        if(!flag && s[i][3] == 'O' && s[i][4] == 'O')
            flag = 1, s[i][3] = s[i][4] = '+';
    }
    if(flag){
        cout << "YES" << endl;
        for(int i = 0; i < n; i++)
            cout << s[i] << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}