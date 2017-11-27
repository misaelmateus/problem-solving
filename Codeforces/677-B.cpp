//   Author : Misael Mateus 
//   Submission date: 2016-06-01 21:51:09
#include<bits/stdc++.h>

#define ll long long

using namespace std;
int main()
{
    int n, h, k;
    scanf("%d %d %d", &n, &h, &k);
    ll atual = 0LL, total = 0LL;
    for(int i = 0; i < n; i++)
    {
        int aux;
        scanf("%d", &aux);
        if((ll)aux + atual <= (ll)h){
            atual += (ll)aux;
            continue;
        }
        int l = (int)( (atual + (ll)aux - (ll)h) /(ll)(k) );
        if((atual + (ll)aux - (ll)h) % (ll)(k) != 0)
            l++;
        atual -= (ll)(k*l);
        if(atual < 0)
            atual = 0;
        atual += aux;
        total += l;
    }
    if(atual % (ll)k != 0)
        total += 1LL;
    total += atual / (ll)(k);

    cout << total << endl;

    return 0;
}
