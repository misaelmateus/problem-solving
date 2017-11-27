//   Author : Misael Mateus 
//   Submission date: 2017-03-10 17:19:11
#include<bits/stdc++.h>
#define L 1000000007
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> m(n);
  vector<int> k;
  vector<int> v;
  vector<int> k1;
  
  for(int i = 0; i < n; i++)
    cin >> m[i];
  
  sort(m.begin(), m.end());
  
  int cont = 1;
  for(int i = 1; i <= n; i++){
    if(i == n || m[i] != m[i-1])
      v.push_back(m[i-1]), k.push_back(cont), k1.push_back(cont+1), cont = 0;
    cont++;
  }
  
  n = k.size();
  bool flag = 0;
  long long ans = 1LL;
  for(int i = 0; i < n; i++)
    if(k[i] % 2 != 0 )
      flag = 1;
 
  for(int i = 0; i < n; i++){
    if(!flag)
      k[i] /= 2;
    else if(k1[i] % 2 == 0){
	k1[i] /= 2;
	break;	
    }
  }
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < k[i]; j++)
      ans = (ans*(long long)v[i])%L;
  }
  
  for(int i = 0; i < n; i++){
    long long ans1 = ans;
    for(int j = 0; j < k1[i]-1; j++)
      ans = (ans * ans1) % L;
  }
  
  cout << ans << endl;
  
  
  return 0;
}#include<bits/stdc++.h>
#define L 1000000007
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> m(n);
  vector<int> k;
  vector<int> v;
  vector<int> k1;
  
  for(int i = 0; i < n; i++)
    cin >> m[i];
  
  sort(m.begin(), m.end());
  
  int cont = 1;
  for(int i = 1; i <= n; i++){
    if(i == n || m[i] != m[i-1])
      v.push_back(m[i-1]), k.push_back(cont), k1.push_back(cont+1), cont = 0;
    cont++;
  }
  
  n = k.size();
  bool flag = 0;
  long long ans = 1LL;
  for(int i = 0; i < n; i++)
    if(k[i] % 2 != 0 )
      flag = 1;
 
  for(int i = 0; i < n; i++){
    if(!flag)
      k[i] /= 2;
    else if(k1[i] % 2 == 0){
	k1[i] /= 2;
	break;	
    }
  }
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < k[i]; j++)
      ans = (ans*(long long)v[i])%L;
  }
  
  for(int i = 0; i < n; i++){
    long long ans1 = ans;
    for(int j = 0; j < k1[i]-1; j++)
      ans = (ans * ans1) % L;
  }
  
  cout << ans << endl;
  
  
  return 0;
}#include<bits/stdc++.h>
#define L 1000000007
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> m(n);
  vector<int> k;
  vector<int> v;
  vector<int> k1;
  
  for(int i = 0; i < n; i++)
    cin >> m[i];
  
  sort(m.begin(), m.end());
  
  int cont = 1;
  for(int i = 1; i <= n; i++){
    if(i == n || m[i] != m[i-1])
      v.push_back(m[i-1]), k.push_back(cont), k1.push_back(cont+1), cont = 0;
    cont++;
  }
  
  n = k.size();
  bool flag = 0;
  long long ans = 1LL;
  for(int i = 0; i < n; i++)
    if(k[i] % 2 != 0 )
      flag = 1;
 
  for(int i = 0; i < n; i++){
    if(!flag)
      k[i] /= 2;
    else if(k1[i] % 2 == 0){
	k1[i] /= 2;
	break;	
    }
  }
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < k[i]; j++)
      ans = (ans*(long long)v[i])%L;
  }
  
  for(int i = 0; i < n; i++){
    long long ans1 = ans;
    for(int j = 0; j < k1[i]-1; j++)
      ans = (ans * ans1) % L;
  }
  
  cout << ans << endl;
  
  
  return 0;
}#include<bits/stdc++.h>
#define L 1000000007
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> m(n);
  vector<int> k;
  vector<int> v;
  vector<int> k1;
  
  for(int i = 0; i < n; i++)
    cin >> m[i];
  
  sort(m.begin(), m.end());
  
  int cont = 1;
  for(int i = 1; i <= n; i++){
    if(i == n || m[i] != m[i-1])
      v.push_back(m[i-1]), k.push_back(cont), k1.push_back(cont+1), cont = 0;
    cont++;
  }
  
  n = k.size();
  bool flag = 0;
  long long ans = 1LL;
  for(int i = 0; i < n; i++)
    if(k[i] % 2 != 0 )
      flag = 1;
 
  for(int i = 0; i < n; i++){
    if(!flag)
      k[i] /= 2;
    else if(k1[i] % 2 == 0){
	k1[i] /= 2;
	break;	
    }
  }
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < k[i]; j++)
      ans = (ans*(long long)v[i])%L;
  }
  
  for(int i = 0; i < n; i++){
    long long ans1 = ans;
    for(int j = 0; j < k1[i]-1; j++)
      ans = (ans * ans1) % L;
  }
  
  cout << ans << endl;
  
  
  return 0;
}