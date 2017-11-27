//   Author : Misael Mateus 
//   Submission date: 2017-01-06 19:53:59
#include<bits/stdc++.h>
using namespace std;
int x[] = {1, 1, 1, -1, -1, -1, 0, 0};
int y[] = {1, -1, 0, 1, -1, 0, 1, -1};
bool f(int i ){
    if(i < 0 || i >= 4)
        return false;
    return true;
}
int main(){
    string m[4];
    for(int i = 0; i < 4; i++){
        cin >> m[i];
    }
    
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++){
            if(m[i][j] != 'x')
                continue;
            for(int k = 0; k < 8; k++){
                int i1 = i + x[k], j1 = j + y[k];
                int i2 = i + 2*x[k], j2 = j + 2*y[k];
                if(!(f(i1) && f(i2) && f(j1) && f(j2)) )
                    continue;
                if(m[i1][j1] == 'x' && m[i2][j2] == '.'
                || m[i2][j2] == 'x' && m[i1][j1] == '.'){
                    cout << "YES" << endl;
                    return 0;
                }
                
            }
            
        }
    cout << "NO" << endl;
    return 0;
}