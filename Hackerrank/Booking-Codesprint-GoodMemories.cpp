#include<bits/stdc++.h>
using namespace std;
int aux;
vector< vector<int> >gr ;
vector< int > mark;
int resp = 1;
void dfs(int atual){
    if(!resp)
        return;
    mark[atual] = 1;
    for(int i = 0; i < gr[atual].size(); i++){
        if(!mark[gr[atual][i]])
            dfs(gr[atual][i]);
        else if(mark[gr[atual][i]] == 1)
            resp = 0;
    }
    
    mark[atual] = 2;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        string line;
        int aux = 1;
        resp = 1;
        map< string, int > mapa;
        gr = vector< vector<int> >(1);
        scanf(" ");
        for(int i = 0; i < n; i++){
            getline(cin, line);
            int j;
            vector<int> v;
            for(int l = 0; l < line.size() ; l++){
                for(j = l; j < line.size() && line[j] != ','; j++);
                string nova = "";
                nova.append(line, l, j - l);
                if(!mapa[nova])
                    mapa[nova] = aux++;
                v.push_back(mapa[nova]);
                l = j;
            }
            gr.resize(aux);
            for(j = 0; j < v.size(); j++)
                for(int l =  j+1; l < v.size(); l++)
                    gr[v[j]].push_back(v[l]);
        }
        
        mark = vector<int>(aux, 0);
        for(int i = 1; i < aux; i++){
            if(!mark[i])
                dfs(i);
        }
        
        if(resp)
            cout << "ORDER EXISTS" << endl;
        else
            cout << "ORDER VIOLATION" << endl;
    }
    return 0;
}