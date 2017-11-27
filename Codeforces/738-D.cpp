//   Author : Misael Mateus 
//   Submission date: 2016-11-20 14:53:43
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio( false );
    int n, a, b, k;
    string s;
    cin >> n >> a >> b >> k >> s;
    int cont = 0;
    int aux = 0;
    int flag = 1;
    for(int i = 0; i <= n; i++){
        if(i != n && s[i] == '0'){
            aux++;
        }
        else{
            cont += (aux/b);
            aux = 0;
        }
    }
    int x = cont - a + 1;
    cout << x << endl;
    
    int i = 0;
    while(x > 0){
        while(s[i] != '0')
            i++;
        int flag = 1;
        int j;
        for(j = i; j <= i + b - 1; j++){
            if(s[j] != '0')
            {
                flag = 0;
                break;
            }
        }
        if(flag){
            cout << i + b << " ";
            x--;
            i += b;
        }
        else{
            i = j;
        }
        
    }
    return 0;
}