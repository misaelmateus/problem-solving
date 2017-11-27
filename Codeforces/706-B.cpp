//   Author : Misael Mateus 
//   Submission date: 2016-08-11 22:26:52
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    sort(v.begin(), v.end());
    
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int m;
        cin >> m;
        vector<int>::iterator low;
        low = upper_bound (v.begin(), v.end(), m);
        if(m < v[0])
            cout << 0 << endl;
        else if(m > v[n-1])
            cout << n << endl;
        else
            cout << low - v.begin()<< endl;
    }
    
    return 0;
}