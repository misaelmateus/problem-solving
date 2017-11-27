//   Author : Misael Mateus 
//   Submission date: 2016-09-13 22:32:13
#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    scanf("%d", &n);
    set<int> v;
    
    for(int i = 0; i < n; i++){
        int aux;
        scanf("%d", &aux);
        v.insert(aux);
    }
    if(v.size() > 3)
    {
        printf("NO\n");
        return 0;
    }
    set<int>::iterator it = v.begin();
    if(v.size() <= 2)
        printf("YES\n");
    else{
        int a = *it;
        it++;
        int b = *it;
        it++;
        int c = *it;
        if(c - b == b - a)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}