#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
#define getcx getchar_unlocked
#define pc(x) putchar_unlocked(x)

 
inline int readInt()
{
    bool minus = false;
    register int result = 0;
    register char ch = getchar_unlocked();
    while (true)
    {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break ;
        ch = getchar_unlocked();
    }
    if (ch == '-') minus = true; 
    else result = ch-'0';
    while (true)
    {
        ch = getchar_unlocked();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus) return -result;
    else return result;
}
 
inline void writeInt ( int n )
{
    register int N = n, rev, count = 0 ;
    rev = N ;
    if (N == 0) 
    { 
        pc('0');  return ;
    }
    while ((rev % 10) == 0) 
    { 
        count++; rev /= 10;
    } //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) 
    { 
        rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;
    }  //store reverse of N in rev
    while (rev != 0) 
    { 
        pc(rev % 10 + '0'); rev /= 10 ;
    }
    while (count--) pc('0') ;
}


int lis[MAXN];

int update(int n, int k){
	while(n < MAXN){
		lis[n] = max(lis[n], k);
		n += (n & -n);
	}
}
int query(int n){
	int ans = 0;
	while(n > 0){
		ans = max(ans, lis[n]);
		n -= (n & -n);
	}
	return ans;
}

// ----------- treap -------------------------
typedef struct item * pitem;

pitem T;
struct item {
	int prior, value, cnt;
	int ma;
	bool rev;
	pitem l, r;

	item(int _value){
		ma = value = _value;
		prior = rand();
		l = r = 0;
	}
};

int cnt (pitem it) {
	return it ? it->cnt : 0;
}

int Ma (pitem it) {
	return it ? it->ma : 0;
}

void upd_cnt (pitem it) {
	if (it){
		it->cnt = cnt(it->l) + cnt(it->r) + 1;
		it->ma = max(it->value, max( Ma(it->l), Ma(it->r) )  );
	}
}


void merge (pitem & t, pitem l, pitem r) {
	if (!l || !r)
		t = l ? l : r;
	else if (l->prior > r->prior)
		merge (l->r, l->r, r),  t = l;
	else
		merge (r->l, l, r->l),  t = r;
	upd_cnt (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
	if (!t)
		return void( l = r = 0 );
	int cur_key = add + cnt(t->l);
	if (key <= cur_key)
		split (t->l, l, t->l, key, add),  r = t;
	else
		split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
	upd_cnt (t);
}

int find (pitem t, int key, int add = 0) {
	if (!t)
		return 0;
	int cur_key = add + cnt(t->l);
	if(key == cur_key)
		return t->value;
	if (key < cur_key)
		find (t->l, key, add);
	else
		find (t->r, key, add + 1 + cnt(t->l));
}

void reverse (pitem t, int l, int r) {
	pitem t1, t2, t3;
	split (t, t1, t2, l);
	split (t2, t2, t3, r-l+1);
	t2->rev ^= true;
	merge (t, t1, t2);
	merge (t, t, t3);
}

void insert(int pos, int value){
	pitem l, r;
	split(T, l, r, pos);
	pitem new_item = new item(value);
	merge(l, l, new_item);
	merge(T, l, r);
}




int main(){
	srand(time(NULL));
	int n, q;
	n = readInt();
	q = readInt();
	for(int i = 1; i <= n; i++)
		insert(i-1, i);
	for(int i = 0; i < q; i++){
		int a, b;
		a = readInt();
		b = readInt();
		a--, b--;
		pitem t1, t2, t3;
		split(T, T, t1, a);
		split(t1, t1, t2, 1);
		merge(T, T, t2);
		split(T, T, t2, b);
		merge(T, T, t1);
		merge(T, T, t2);
	}
	for(int i = 0; i < n; i++){
		int val = find(T, i);
		update(val, query(val-1) + 1);
	}
	int ans = query(MAXN-1);
	writeInt(n - ans);
	puts("\n");
	return 0;
}