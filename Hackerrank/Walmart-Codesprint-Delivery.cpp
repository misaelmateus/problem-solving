#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int dist(int a, int b){
    if(a < b){ int aux = a; a = b; b = aux; }
    if(a == b)
        return 0;
    return 1 + dist(a/2, b);
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    
    int tot = 0;
    vector<int> r[m+1];
    
    for(int i = 0; i < m; i++){
        int t;
        cin >> t;
        for(int j = 0; j < t; j++)
        {
            int a;
            cin >> a;
            r[i+1].push_back(a);
        }
    }
    
    int atual = 1;
    while(q--){
        int food, person;
        cin >> food >> person;
        
        int menor = 100000000;
        for(int i = 0; i < r[food].size(); i++)
            if(menor > dist(atual, r[food][i]) + dist(r[food][i], person))
                menor = dist(atual, r[food][i]) + dist(r[food][i], person);
        tot += menor;
        atual = person;
    }
    
    cout << tot << endl;
    return 0;
}
