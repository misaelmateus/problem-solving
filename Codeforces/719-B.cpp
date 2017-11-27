//   Author : Misael Mateus 
//   Submission date: 2016-09-23 19:24:10
#include<bits/stdc++.h>
using namespace std;

int a[2], b[2];
char c[] = {'r', 'b' };
int main(){
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    string s;
    cin >> s;
    int p = 0; // r
    
    for(int i = 0; i < n; i++, p = 1 - p)
        if(s[i] == c[p] )
            continue;
        else a[1 - p]++;
    
    p = 1;
    for(int i = 0; i < n; i++, p = 1 - p)
        if(s[i] == c[p] )
            continue;
        else b[1 - p]++;
        
    int resp = a[0] + a[1] - min(a[0], a[1]);
    resp = min( resp, b[0] + b[1] - min(b[0], b[1]));
    
    cout << resp << endl;
    
    return 0;
}