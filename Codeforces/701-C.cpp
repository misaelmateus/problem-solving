//   Author : Misael Mateus 
//   Submission date: 2016-11-19 01:15:30
#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>

using namespace std;
int main(){
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> ult;
    map<char, int> mark;
    vector<char> type;
    for(int i = 0; i < n; i++){
        if(mark[s[i]] == 0)
            type.push_back(s[i]);
        mark[s[i]] = 1;
    }
    int ans = n+1;
    for(int i = 1; i <= n; i++){
        ult[s[i-1]] = i;
        int pos = i;
        for(int j = 0; j < type.size(); j++){
            char c = type[j];
            if(!ult[c])
            {
                pos = -1;
                break;
            }
            pos = min(pos, ult[c]);
        }
        if(pos == -1)
            continue;
        
        ans = min(ans, i - pos + 1);
    }
    
    cout << ans << endl;
}#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>

using namespace std;
int main(){
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> ult;
    map<char, int> mark;
    vector<char> type;
    for(int i = 0; i < n; i++){
        if(mark[s[i]] == 0)
            type.push_back(s[i]);
        mark[s[i]] = 1;
    }
    int ans = n+1;
    for(int i = 1; i <= n; i++){
        ult[s[i-1]] = i;
        int pos = i;
        for(int j = 0; j < type.size(); j++){
            char c = type[j];
            if(!ult[c])
            {
                pos = -1;
                break;
            }
            pos = min(pos, ult[c]);
        }
        if(pos == -1)
            continue;
        
        ans = min(ans, i - pos + 1);
    }
    
    cout << ans << endl;
}#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>

using namespace std;
int main(){
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> ult;
    map<char, int> mark;
    vector<char> type;
    for(int i = 0; i < n; i++){
        if(mark[s[i]] == 0)
            type.push_back(s[i]);
        mark[s[i]] = 1;
    }
    int ans = n+1;
    for(int i = 1; i <= n; i++){
        ult[s[i-1]] = i;
        int pos = i;
        for(int j = 0; j < type.size(); j++){
            char c = type[j];
            if(!ult[c])
            {
                pos = -1;
                break;
            }
            pos = min(pos, ult[c]);
        }
        if(pos == -1)
            continue;
        
        ans = min(ans, i - pos + 1);
    }
    
    cout << ans << endl;
}#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>

using namespace std;
int main(){
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> ult;
    map<char, int> mark;
    vector<char> type;
    for(int i = 0; i < n; i++){
        if(mark[s[i]] == 0)
            type.push_back(s[i]);
        mark[s[i]] = 1;
    }
    int ans = n+1;
    for(int i = 1; i <= n; i++){
        ult[s[i-1]] = i;
        int pos = i;
        for(int j = 0; j < type.size(); j++){
            char c = type[j];
            if(!ult[c])
            {
                pos = -1;
                break;
            }
            pos = min(pos, ult[c]);
        }
        if(pos == -1)
            continue;
        
        ans = min(ans, i - pos + 1);
    }
    
    cout << ans << endl;
}