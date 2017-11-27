//   Author : Misael Mateus 
//   Submission date: 2016-06-14 22:05:34
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string nomes;
    int before, after;
    int resp = 0;
    for(int i = 0; i < n; i++){
        cin >> nomes >> before >> after;
        if(before >= 2400 && after > before)
            resp = 1;
    }
    if(resp)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;


    return 0;
}
