//   Author : Misael Mateus 
//   Submission date: 2016-12-14 19:51:52
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n == 1){
        cout << -1 << endl;
    }
    else{
        cout << n << " " << n+1 << " " << n*(n+1) << endl;
        return 0;
    }
}