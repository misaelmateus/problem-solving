//   Author : Misael Mateus 
//   Submission date: 2016-10-03 17:14:03
#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios::sync_with_stdio( false );
    int a[3];
    for(int i = 0; i < 3; i++)
        cin >> a[i];
    
    sort(a, a+3);
    int dist = a[2] - a[0];
    cout << dist << endl;
    
    return 0;
} 