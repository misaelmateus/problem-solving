//   Author : Misael Mateus 
//   Submission date: 2015-08-25 16:51:38
#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    int moedas[n];
    bool possivel = false;
    for(int i = 0; i < n; i++){
        scanf("%d", &moedas[i]);
        if(moedas[i] == 1)
            possivel = true;
    }
    if(possivel == true)
        printf("-1\n");
    else
        printf("1\n");
    return 0;
}