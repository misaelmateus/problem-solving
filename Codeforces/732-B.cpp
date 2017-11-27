//   Author : Misael Mateus 
//   Submission date: 2016-10-17 20:44:45
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int a[n+1];
    a[0] = k;
    int cont = 0;
    int aux;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] + a[i-1] < k)
            aux = k - (a[i] + a[i-1]), a[i] += aux, cont += aux;
    }
    
    cout << cont << endl;
    for(int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
    
    return 0;
}