//   Author : Misael Mateus 
//   Submission date: 2016-10-22 20:58:58
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> p(26, -1);
    string s;
    cin >> s;
    int x, y;
    for(int i = 0; i < 27; i++)
        if(p[s[i] - 'A'] == -1)
            p[s[i] - 'A'] = i;
        else
            x = p[s[i] - 'A'], y = i;
    int a = (y - x);
    
    if(y - x - 1){
        deque<char> r1;
        deque<char> r2;
        for(int i = 0; i < a/2 + (a%2); i++)
            r1.push_back(s[x+i]);
        for(int i = x-1; i >= 0; i--)
            if(r1.size() < 13)
                r1.push_front(s[i]);
            else
                r2.push_back(s[i]);
        for(int i = 26; i > y; i--)
            if(r1.size() < 13)
                r1.push_front(s[i]);
            else
                r2.push_back(s[i]);
        for(int i = a-1; i >= a/2 + (a%2); i--)
            r2.push_back(s[x+i]);
        while(r1.size()){
            cout << r1.front();
            r1.pop_front();
        }
        cout << endl;
        while(r2.size()){
            cout << r2.front();
            r2.pop_front();
        }
        
        cout << endl;
    }
    else
        cout << "Impossible" << endl;
            
}