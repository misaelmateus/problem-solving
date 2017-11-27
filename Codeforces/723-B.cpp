//   Author : Misael Mateus 
//   Submission date: 2016-10-03 17:16:35
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int quant = 0;
    int m = 0;
    int p = 0;
    int flag = 0;
    
    for(int i = 0; i <= s.size(); i++){
        if(i == s.size()){
            if(flag && p > 0)
                quant++;
            if(!flag && p > m)
                m = p;
        }
        else if(s[i] == '_'){
            if(flag && p > 0)
                quant++;
            if(!flag && p > m)
                m = p;
            p = 0;
        }
        else if(s[i] == '('){
            if(p > m)
                m = p;
            p = 0;
            flag = 1;
        }
        else if(s[i] == ')'){
            if(p > 0)
                quant++;
            p = 0;
            flag = 0;
        }
        else
            p++;
    }
    
    cout << m << " " << quant << endl;
    
    return 0;
}