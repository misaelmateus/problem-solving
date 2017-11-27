//   Author : Misael Mateus 
//   Submission date: 2016-06-14 22:19:43
#include<bits/stdc++.h>
using namespace std;
map<int, int> mapa;
int n;
int main()
{

    cin >> n;
    bool resp = 0;
    for(int i = 0; i*1234567 <= n && !resp; i++)
    {
        for(int j = 0; j*123456 <= (n - i*1234567) && !resp; j++)
        {
            if((n - i*1234567 - j*123456) % 1234 == 0 )
                resp = 1;
        }
    }

    if(resp)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
