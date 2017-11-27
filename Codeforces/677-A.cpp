//   Author : Misael Mateus 
//   Submission date: 2016-06-01 21:46:18
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, h;
    scanf("%d %d", &n, &h);
    int cont = 0;
    for(int i = 0; i < n; i++)
    {
        int aux;
        scanf("%d", &aux);
        cont++;
        if(aux > h)
            cont++;
    }

    printf("%d\n", cont);

    return 0;
}
