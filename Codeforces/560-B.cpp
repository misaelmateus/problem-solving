//   Author : Misael Mateus 
//   Submission date: 2015-08-25 17:03:29
#include <cstdio>
using namespace std;

int main() {
    int x,y;
    int a,b,c,d;
    scanf("%d %d %d %d %d %d", &x, &y, &a, &b, &c, &d);
    bool possivel = false;
    
    if( a + c <= x && b <= y && d <= y)
        possivel = true;
    if(b + d <= y && a <= x && c <= x)
        possivel = true;
    if( a + d <= x && b <= y && c <= y)
        possivel = true;
    if(b + c <= y && a <= x && d <= x)
        possivel = true;
    
    int aux = a;
    a = b, b = aux;
    
    if( a + c <= x && b <= y && d <= y)
        possivel = true;
    if(b + d <= y && a <= x && c <= x)
        possivel = true;
    
    if( a + d <= x && b <= y && c <= y)
        possivel = true;
    if(b + c <= y && a <= x && d <= x)
        possivel = true;
        
    if(possivel)
        printf("YES\n");
    else
        printf("NO\n");
    
    return 0;
}