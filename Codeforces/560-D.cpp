//   Author : Misael Mateus 
//   Submission date: 2015-08-25 18:40:25
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string ordena(string atual)
{
    int t = atual.size();
    if(t == 1 || t % 2 == 1)
        return atual;
    t /= 2;
    string novo[2];
    
    novo[0] = novo[1] = "";
    novo[0].insert(0, atual, 0, t);
    novo[1].insert(0, atual, t, t);
    
    novo[0] = ordena(novo[0]);
    novo[1] = ordena(novo[1]);
    
    int primeiro = 0;
    if(novo[0] <= novo[1])
    {
        novo[0].insert(t, novo[1]);
        return novo[0];
    }
    novo[0].insert(0, novo[1]);
    return novo[0];
    
    
}
int main() {
    string a, b;
    cin >> a >> b;
    a = ordena(a);
    b = ordena(b);
    if(a == b)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}