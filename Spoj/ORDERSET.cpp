#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;

using ordered_set = tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>;

struct node_t {
  ordered_set vals;
  void clear() {
    vals.clear();
  }
  void add(int v) {
    vals.insert(v);
  }
  void remove(int v) {
    vals.erase(v);
  }
  int count(int val) {
    return vals.order_of_key(val);
  }

  int k_th_element(int k){
  	auto it = vals.find_by_order(k);
  	if(it == end(vals))
  		return -1;
  	else
  		return *it;
  }
} s;
int main(){
  int n;
  scanf("%d", &n);

  char c;
  int x;
  for(int i = 0; i < n; i++){
      scanf(" %c %d", &c, &x);
      if(c == 'I') 
        s.add(x);
      else if(c == 'D')
        s.remove(x);
      else if(c == 'C')
        printf("%d\n", s.count(x));
      else {
        int ans = s.k_th_element(x-1);
        if(ans == -1)
          printf("invalid\n");
        else
          printf("%d\n", ans);
      }
  }
}