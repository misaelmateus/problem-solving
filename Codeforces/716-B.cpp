//   Author : Misael Mateus 
//   Submission date: 2016-09-17 19:24:51
#include<bits/stdc++.h>
using namespace std;
int l[26];
int main(){
    ios::sync_with_stdio( false );  
    string s;
    cin >> s;
    if(s.size() < 26){
        cout << -1 << endl;
        return 0;
    }
    int cont = 0;
    int tot = 0;
    for(int i = 0; i < 26; i++)
        if(s[i] <= 'Z' && s[i] >= 'A'){
            if(l[ (int)(s[i] - 'A')] == 0)
                tot++;
            l[ (int)(s[i] - 'A')]++;
        }
        else
            cont++;
    int a = 0;
    int b = 25;
    for(; b < s.size(); b++, a++){
        //cout << a << " " << cont << " " << tot << endl;
        if(tot + cont >= 26)
        {
            for(int i = a; i <= b && cont > 0; i++){
                if(s[i] == '?'){
                    for(int j = 0; j < 26; j++)
                        if(l[j] == 0)
                        {
                            s[i] = (char)(j + 'A');
                            cont--;
                            l[j]++;
                            break;
                        }
                }
            }
            break;
        }
        else{
            if(s[a] != '?'){
                if(l[(int)(s[a] - 'A')] == 1)
                    tot--;
                l[(int)(s[a] - 'A')]--;
            }
            else
                cont--;
            
            if(b + 1 < s.size() && s[b+1] != '?'){
                if(l[(int)(s[b+1] - 'A')] == 0)
                    tot++;
                l[(int)(s[b+1] - 'A')]++;
            }
            else
                cont++;
        }
    }
    if(b == s.size()){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < s.size(); i++)
        if(s[i] == '?')
            s[i] = 'A';
    cout << s << endl;

    return 0;
}