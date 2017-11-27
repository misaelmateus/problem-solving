//   Author : Misael Mateus 
//   Submission date: 2015-08-25 14:48:25
#include <cstdio>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char text[n];
    scanf("%s", &text);
    int cont = 0;
    for(int i = 1; i < n; i++)
        if(text[i] == '.' && text[i-1] == '.')
            cont++;
    for(int i = 0; i < m; i++)
    {
        char c;
        int p;
        scanf(" %d %c", &p, &c);
        if(c != '.' && text[p-1] != '.');
        else if(c == '.' && text[p-1] == '.');
        else if(c == '.' && p > 1 && text[p - 2] == '.' && p < n && text[p] == '.')
            cont += 2;
        else if(c == '.' && ( ( p > 1 && text[p - 2] == '.')  || (p < n && text[p] == '.') )  )
            cont += 1;
        else if(c == '.');
        else if(p > 1 && text[p - 2] == '.' && p < n && text[p] == '.')
            cont -= 2;
        else if(( p > 1 && text[p - 2] == '.')  || (p < n && text[p] == '.') )
            cont -= 1;
        text[p-1] = c;
        printf("%d\n", cont);
    }
    return 0;
}