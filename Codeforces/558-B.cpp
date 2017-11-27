//   Author : Misael Mateus 
//   Submission date: 2015-08-25 21:45:44
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main() {
    

    int n;
    scanf("%d", &n);
    int ordenado[n];
    map<int, int> ini;
    map<int, int> fim;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &ordenado[i]);
        if(ini[ordenado[i]] == 0)
            ini[ordenado[i]] = i+1;
        fim[ordenado[i]] = i+1;
    }
    sort(ordenado, ordenado+n);
    int maior = -1;
    int freq = 1;
    vector<int> lista;
    for(int i = 1; i < n; i++)
    {
        if(ordenado[i] == ordenado[i-1])
            freq++;
        else
        {
            if(freq > maior){
                maior = freq;
                lista.clear();
                lista.push_back(ordenado[i-1]);
            }
            else if(freq == maior)
                lista.push_back(ordenado[i-1]);
            freq = 1;
        }
    }
    
    if(freq > maior){
        maior = freq;
        lista.clear();
        lista.push_back(ordenado[n-1]);
    }
    else if(freq == maior)
        lista.push_back(ordenado[n-1]);
        
        
    int distancia = 20000000;
    int i_menor = -1, j_menor = -1;
    for(int i = 0; i < lista.size(); i++)
    {
        int atual = lista[i];
        int a = ini[atual];
        int b = fim[atual];
        if(b - a < distancia)
        {
            distancia = b - a;
            i_menor = a;
            j_menor = b;
        }
        
    }
    printf("%d %d\n", i_menor, j_menor);
    
    
    return 0;
}