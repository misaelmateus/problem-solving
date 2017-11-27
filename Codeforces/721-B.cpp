//   Author : Misael Mateus 
//   Submission date: 2016-09-30 19:42:05
#include<bits/stdc++.h>
using namespace std;
int q[101], t;
int main(){
    int n, k;
    cin >> n >> k;
    
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        q[s.size()]++;
    }
    
    cin >> s;
    t = s.size();
    
    int quant = 0;
    for(int i = 1; i < t; i++)
        quant += q[i];
    
    int best = 0, worse = 0;
    
    best = (quant / k)*5 + quant + 1;
    int qf = quant + q[t] - 1;
    worse = (qf / k)* 5 + qf + 1;
    
    cout << best << " " << worse << endl;
    
    
    return 0;
    
}