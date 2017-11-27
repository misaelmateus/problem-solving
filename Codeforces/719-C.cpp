//   Author : Misael Mateus 
//   Submission date: 2016-10-03 21:31:13
#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio( false );
    int n, t, flag1 = 1;
    cin >> n >> t;
    string s;
    cin.ignore();
    cin >> s;
    if(s[0] == '0') flag1 = 0;
    priority_queue<int> pq;
    int flag = 0;

    for(int i = 0; i < s.size(); i++){
        if(flag)
            if(s[i] > '4')
                pq.push(-i);

        if(s[i] == '.')
            flag = 1;
    }

    while(!pq.empty() && t){
        t--;
        int u = -pq.top();
        pq.pop();

        if(u >= n)
            break;

        n = u;
        if(s[u-1] == '.'){
            n = u-1;
            for(int i = u-2; i >= 0; i--){
                if(s[i] == '9')
                    s[i] = '0';
                else{
                    s[i]++;
                    break;
                }
            }
        }
        else{
            s[u-1]++;
            if(s[u-1] == '5')
                pq.push(-u+1);
        }
    }

    if(s[0] == '0' && flag1) cout << 1;
    for(int i = 0; i < n; i++)
        cout << s[i];

    cout << endl;

    return 0;
}
