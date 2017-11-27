//   Author : Misael Mateus 
//   Submission date: 2016-09-17 19:20:43
#include <bits/stdc++.h>

using namespace std;
 
int main(){
     
    ios::sync_with_stdio( false );
    
    
    int n, c, cont = 1;
    cin >> n >> c;
    int ult;
    cin >> ult;
    for(int i = 1; i < n; i++){
        int a;
        cin >> a;
        if(a - ult > c)
            cont = 1;
        else
            cont++;
        ult = a;
    }
    
    cout << cont << endl;
    return 0;
}