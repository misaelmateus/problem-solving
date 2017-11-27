#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MOD 1000000007LL

using namespace std;

ll fat[110];
ll inv_fat[110];
 
/* This function calculates (a^b) % MOD */
ll fastPow(ll a, ll b)
{
    ll res = 1LL;
    while (b > 0LL)
    {
        if (b & 1LL)
        {
            res *= a; res %= MOD;
        }
        a *= a; a %= MOD;
        b >>= 1;
    }
    return res;
}
 
/*
    Modular Multiplicative Inverse
    Using Euler's Theorem
*/
 
long long InverseEuler(ll n)
{
    return fastPow(n, MOD-2LL);
}
int main(){
	ios::sync_with_stdio(false);	
	int t;
	cin >> t;
	fat[0] = 1LL;
	inv_fat[0] = 1LL;

	fr(i, 1, 110) fat[i] = (fat[i-1]*i) % MOD;
	fr(i, 1, 110) inv_fat[i] = (InverseEuler(i) * inv_fat[i-1]) % MOD;
	while(t--){
		ll n;
		cin >> n;
		ll q2 = 0, q3 = 0, q5 = 0, q7 = 0;
		if(n == 0){
			ll ans = 1LL;
			for(ll tam = 1LL; tam <= 100; tam++){
				ans += (fastPow(10, tam) - fastPow(10, tam-1)) - fastPow(9, tam);
				ans += 2*MOD;
				ans %= MOD;
			}
			cout << ans << endl;
			continue;
		}


		while(n % 2 == 0) q2++, n /= 2;
		while(n % 3 == 0) q3++, n /= 3;
		while(n % 5 == 0) q5++, n /= 5;
		while(n % 7 == 0) q7++, n /= 7;
		if(n > 1) {
			cout << "0\n";
			continue;
		}
		
		ll v[10];
		v[5] = q5;
		v[7] = q7;
		ll ans = 0LL;
		for(v[4] = 0; 2*v[4] <= q2; v[4]++){
			for(v[9] = 0; 2*v[9] <= q3; v[9]++)
				for(v[6] = 0; v[6] + 2*v[4] <= q2 && v[6] + 2*v[9] <= q3; v[6]++){
					for(v[8] = 0; 3*v[8] + v[6] + 2*v[4] <= q2; v[8]++){
						v[2] = q2 - 2*v[4] - v[6] - 3*v[8];
						v[3] = q3 - v[6] - 2*v[9];

						if(v[2] < 0 || v[3] < 0) continue;
						ll sum1 = (v[2] + v[3] + v[4] + q5 + v[6] + q7 + v[8] + v[9]);
						ll q1 = 100 - sum1;
						if(q1 < 0) continue;
						for(v[1] = 0; v[1] <= q1; v[1]++){
							ll sum = v[1] + sum1;
							if(sum <= 0) continue;
							ll ans1 = fat[sum];
							
							fr(i, 1, 10)
								ans1 = (ans1 * inv_fat[v[i]]) % MOD;

							ans = (ans + ans1) % MOD;
						}


					}
				}
		}
		cout << (ans+MOD)%MOD << endl;
	}
}