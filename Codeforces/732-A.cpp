//   Author : Misael Mateus 
//   Submission date: 2016-10-17 20:35:57
#include<bits/stdc++.h>
using namespace std;
int main(){
    int k, r;
    cin >> k >> r;
    if(k % 10 == 0)
    {
        cout << 1 << endl;
        return 0;
    }
    int resp = 10;
    for(int l = 9; l >= 1; l--){
        int p = k*l;
        if(p % 10 == 0 || p % 10 == r)
            resp = l;
    }
    
    cout << resp << endl;
    
    return 0;
}