//   Author : Misael Mateus 
//   Submission date: 2016-10-03 21:22:20
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    string s;
    cin >> a >> s;
    if(s[3] > '5')
        s[3] = '0';
    if(a == 12){
        if(s[0] == '1' && s[1] > '2')
            s[1] = '0';
        if(s[0] == '0' && s[1] == '0')
            s[1] = '1';
        if(s[0] > '1'){
            if(s[1] == '0')
                s[0] = '1';
            else
                s[0] = '0';
        }
    }
    else{
        if(s[0] == '2' && s[1] > '3')
            s[1] = '0';
        if(s[0] > '2')
            s[0] = '0';
    }
    
    cout << s << endl;
    return 0;
}