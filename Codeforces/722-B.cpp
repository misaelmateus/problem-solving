//   Author : Misael Mateus 
//   Submission date: 2016-10-01 19:20:24
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int v[n];
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    int flag = 1;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        
        int cont = 0;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'y')
                cont++;
        }
        if(cont != v[i])
            flag = 0;
    }
    
    if(flag)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
}