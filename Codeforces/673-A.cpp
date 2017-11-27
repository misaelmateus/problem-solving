//   Author : Misael Mateus 
//   Submission date: 2016-05-07 21:34:06
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    scanf("%d", &N);

    int x[91];
    memset(x, 0, sizeof(x));
    for(int i = 0; i < N; i++)
    {
        int aux;
        scanf("%d", &aux);
        x[aux] = 1;
    }
    int i = 1, cont = 0;
    for(; i <= 90; i++)
    {
        if(!x[i])
        {
            cont++;
            if(cont == 15)
                break;
        }
        else
            cont = 0;
    }
    if(i == 91)
        i--;

    printf("%d\n", i);


    return 0;
}
