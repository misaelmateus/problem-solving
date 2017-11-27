//   Author : Misael Mateus 
//   Submission date: 2015-08-27 13:58:47
#include <iostream>
#include <cstdio>a
#include <string>
#include <map>
using namespace std;

int main() {
    map<string, int> mapa;
    string a;
    cin >> a;
    int cont = 0;
    for(int i = 0; i <= a.size(); i++)
    {

        for(char j = 'a'; j <= 'z'; j++)
        {
            string novo = a;
            novo.insert(i, 1, j);
            if(mapa[novo] == 0)
                mapa[novo] = 1, cont += 1;
        }
    }
    printf("%d\n", cont);
    return 0;
}