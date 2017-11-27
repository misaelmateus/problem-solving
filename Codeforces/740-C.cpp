//   Author : Misael Mateus 
//   Submission date: 2016-11-23 22:04:34
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int a[n+1];
    memset(a, 0, sizeof(a));

    int men = 2*n;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        men = min(men, b-a+1);
 
    }
    
    for(int i = n-men+1; i <= n; i++)
        a[i] = i-(n-men+1);
    for(int i = n-men; i > 0; i--){
        a[i] = a[i+men];
    }
    
    cout << men << endl;
    for(int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
    
    return 0;
}