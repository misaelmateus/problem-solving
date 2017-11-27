//   Author : Misael Mateus 
//   Submission date: 2016-11-20 14:22:40
#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define ld long double

using namespace std;
int main(){
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    string s;
    cin >> s;
    string go = "go";
    string ogo = "ogo";
    string ans = "";
    for(int i = 0; i < s.size(); i++){
        string aux;
        aux.assign(s, i, 3);
        if(aux != ogo)
        {
            ans += s[i];
            continue;
        }
        ans += "***";
        while(i+2 < n)
        {
            aux.assign(s, i+1, 2);
            if(aux == go)
            {
                i+= 2;
            }
            else
                break;
        }
    }
    cout << ans << endl;
}