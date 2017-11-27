//   Author : Misael Mateus 
//   Submission date: 2016-05-11 21:50:46
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    scanf("%d", &N);

    int atual = 1, cont = 0;
    while(cont < N)
    {
        int soma = 1;
        if(atual < 10)
            soma = 1;
        else if(atual < 100)
            soma = 2;
        else soma = 3;
        if(cont + soma >= N)
        {
            if(soma == 1)
                printf("%d\n", atual);
            if(soma == 2)
                if(cont + 1 == N)
                    printf("%d\n", atual / 10);
                else
                    printf("%d\n", atual % 10);
            if(soma == 3)
                if(cont + 1 == N)
                    printf("%d\n", atual / 100);
                else if(cont + 2 == N)
                    printf("%d\n", (atual % 100) /10);
                else
                    printf("%d\n", atual % 10);
            break;
        }
        else
            cont += soma, atual += 1;
    }
    return 0;
}
