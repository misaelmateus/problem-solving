//   Author : Misael Mateus 
//   Submission date: 2017-01-07 04:09:54
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> r, l;
    int cont = 0;
    int ult = 1;
    for(int i = 1; i <= n; i++){
        int aux;
        cin >> aux;
        if(aux != 0)
            r.push_back(ult), l.push_back(i), ult = i+1, cont++;
    }
    if(cont == 0)
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        
        cout << r.size() << endl;
        
        for(int i = 0; i < r.size(); i++){
            if(i == r.size()-1)
                cout << r[i] << " " << n << endl;
            else cout << r[i] << " " <<  l[i] << endl;
        }
        
    }
}