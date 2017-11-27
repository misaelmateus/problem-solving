//   Author : Misael Mateus 
//   Submission date: 2016-08-04 21:04:16
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a = 0, b = 0;
    
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        if(x > y)
            a++;
        if(y > x)
            b++;
    }
    if(a > b)
        cout << "Mishka" << endl;
    else if(a < b)
        cout << "Chris" << endl;
    else
        cout << "Friendship is magic!^^" << endl;
        
    return 0;
}