//   Author : Misael Mateus 
//   Submission date: 2017-10-27 14:22:23
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int pointer; //Keeps track of the best line from previous query
vector<long long> M; //Holds the slopes of the lines in the envelope
vector<long long> B; //Holds the y-intercepts of the lines in the envelope
//Returns true if either line l1 or line l3 is always better than line l2
bool bad(int l1,int l2,int l3)
{
	/*
	intersection(l1,l2) has x-coordinate (b1-b2)/(m2-m1)
	intersection(l1,l3) has x-coordinate (b1-b3)/(m3-m1)
	set the former greater than the latter, and cross-multiply to
	eliminate division
	*/
	return (B[l3]-B[l1])*(M[l1]-M[l2] + 0.0)<(B[l2]-B[l1] + 0.0)*(M[l1]-M[l3]);
}
//Adds a new line (with lowest slope) to the structure
void add(long long m,long long b)
{
	//Firt, let's add it to the end
	M.push_back(m);
	B.push_back(b);
	//If the penultimate is now made irrelevant between the antepenultimate
	//and the ultimate, remove it. Repeat as many times as necessary
	while (M.size()>=3&&bad(M.size()-3,M.size()-2,M.size()-1))
	{
		M.erase(M.end()-2);
		B.erase(B.end()-2);
	}
}
// only works for query values non decreasing
//Returns the minimum y-coordinate of any intersection between a given vertical
//line and the lower envelope
long long query(long long x)
{
	//If we removed what was the best line for the previous query, then the
	//newly inserted line is now the best for that query
	if (pointer>=M.size())
		pointer=M.size()-1;
	//Any better line must be to the right, since query values are
	//non-decreasing
	while (pointer<M.size()-1&&
	  M[pointer+1]*x+B[pointer+1]<M[pointer]*x+B[pointer])
		pointer++;
	//cout << pointer << " " << M[pointer] << " " << B[pointer] << endl;
	return M[pointer]*x+B[pointer];
}
#define MAXN 100010
ll dp[MAXN];
int main(){
	int n;
	scanf("%d", &n);
	ll a[n], b[n];
	for(int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for(int i = 0; i < n; i++)
		scanf("%lld", &b[i]);
	add(a[n-1], 0);
	for(int i = n-2; i >= 0; i--){
		dp[i] = query(b[i]);
		add(a[i], dp[i]);
		//cout << dp[i] << endl;
	}

	printf("%lld\n", dp[0]);
}#include<bits/stdc++.h>
using namespace std;
#define ll long long
int pointer; //Keeps track of the best line from previous query
vector<long long> M; //Holds the slopes of the lines in the envelope
vector<long long> B; //Holds the y-intercepts of the lines in the envelope
//Returns true if either line l1 or line l3 is always better than line l2
bool bad(int l1,int l2,int l3)
{
	/*
	intersection(l1,l2) has x-coordinate (b1-b2)/(m2-m1)
	intersection(l1,l3) has x-coordinate (b1-b3)/(m3-m1)
	set the former greater than the latter, and cross-multiply to
	eliminate division
	*/
	return (B[l3]-B[l1])*(M[l1]-M[l2] + 0.0)<(B[l2]-B[l1] + 0.0)*(M[l1]-M[l3]);
}
//Adds a new line (with lowest slope) to the structure
void add(long long m,long long b)
{
	//Firt, let's add it to the end
	M.push_back(m);
	B.push_back(b);
	//If the penultimate is now made irrelevant between the antepenultimate
	//and the ultimate, remove it. Repeat as many times as necessary
	while (M.size()>=3&&bad(M.size()-3,M.size()-2,M.size()-1))
	{
		M.erase(M.end()-2);
		B.erase(B.end()-2);
	}
}
// only works for query values non decreasing
//Returns the minimum y-coordinate of any intersection between a given vertical
//line and the lower envelope
long long query(long long x)
{
	//If we removed what was the best line for the previous query, then the
	//newly inserted line is now the best for that query
	if (pointer>=M.size())
		pointer=M.size()-1;
	//Any better line must be to the right, since query values are
	//non-decreasing
	while (pointer<M.size()-1&&
	  M[pointer+1]*x+B[pointer+1]<M[pointer]*x+B[pointer])
		pointer++;
	//cout << pointer << " " << M[pointer] << " " << B[pointer] << endl;
	return M[pointer]*x+B[pointer];
}
#define MAXN 100010
ll dp[MAXN];
int main(){
	int n;
	scanf("%d", &n);
	ll a[n], b[n];
	for(int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for(int i = 0; i < n; i++)
		scanf("%lld", &b[i]);
	add(a[n-1], 0);
	for(int i = n-2; i >= 0; i--){
		dp[i] = query(b[i]);
		add(a[i], dp[i]);
		//cout << dp[i] << endl;
	}

	printf("%lld\n", dp[0]);
}#include<bits/stdc++.h>
using namespace std;
#define ll long long
int pointer; //Keeps track of the best line from previous query
vector<long long> M; //Holds the slopes of the lines in the envelope
vector<long long> B; //Holds the y-intercepts of the lines in the envelope
//Returns true if either line l1 or line l3 is always better than line l2
bool bad(int l1,int l2,int l3)
{
	/*
	intersection(l1,l2) has x-coordinate (b1-b2)/(m2-m1)
	intersection(l1,l3) has x-coordinate (b1-b3)/(m3-m1)
	set the former greater than the latter, and cross-multiply to
	eliminate division
	*/
	return (B[l3]-B[l1])*(M[l1]-M[l2] + 0.0)<(B[l2]-B[l1] + 0.0)*(M[l1]-M[l3]);
}
//Adds a new line (with lowest slope) to the structure
void add(long long m,long long b)
{
	//Firt, let's add it to the end
	M.push_back(m);
	B.push_back(b);
	//If the penultimate is now made irrelevant between the antepenultimate
	//and the ultimate, remove it. Repeat as many times as necessary
	while (M.size()>=3&&bad(M.size()-3,M.size()-2,M.size()-1))
	{
		M.erase(M.end()-2);
		B.erase(B.end()-2);
	}
}
// only works for query values non decreasing
//Returns the minimum y-coordinate of any intersection between a given vertical
//line and the lower envelope
long long query(long long x)
{
	//If we removed what was the best line for the previous query, then the
	//newly inserted line is now the best for that query
	if (pointer>=M.size())
		pointer=M.size()-1;
	//Any better line must be to the right, since query values are
	//non-decreasing
	while (pointer<M.size()-1&&
	  M[pointer+1]*x+B[pointer+1]<M[pointer]*x+B[pointer])
		pointer++;
	//cout << pointer << " " << M[pointer] << " " << B[pointer] << endl;
	return M[pointer]*x+B[pointer];
}
#define MAXN 100010
ll dp[MAXN];
int main(){
	int n;
	scanf("%d", &n);
	ll a[n], b[n];
	for(int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for(int i = 0; i < n; i++)
		scanf("%lld", &b[i]);
	add(a[n-1], 0);
	for(int i = n-2; i >= 0; i--){
		dp[i] = query(b[i]);
		add(a[i], dp[i]);
		//cout << dp[i] << endl;
	}

	printf("%lld\n", dp[0]);
}#include<bits/stdc++.h>
using namespace std;
#define ll long long
int pointer; //Keeps track of the best line from previous query
vector<long long> M; //Holds the slopes of the lines in the envelope
vector<long long> B; //Holds the y-intercepts of the lines in the envelope
//Returns true if either line l1 or line l3 is always better than line l2
bool bad(int l1,int l2,int l3)
{
	/*
	intersection(l1,l2) has x-coordinate (b1-b2)/(m2-m1)
	intersection(l1,l3) has x-coordinate (b1-b3)/(m3-m1)
	set the former greater than the latter, and cross-multiply to
	eliminate division
	*/
	return (B[l3]-B[l1])*(M[l1]-M[l2] + 0.0)<(B[l2]-B[l1] + 0.0)*(M[l1]-M[l3]);
}
//Adds a new line (with lowest slope) to the structure
void add(long long m,long long b)
{
	//Firt, let's add it to the end
	M.push_back(m);
	B.push_back(b);
	//If the penultimate is now made irrelevant between the antepenultimate
	//and the ultimate, remove it. Repeat as many times as necessary
	while (M.size()>=3&&bad(M.size()-3,M.size()-2,M.size()-1))
	{
		M.erase(M.end()-2);
		B.erase(B.end()-2);
	}
}
// only works for query values non decreasing
//Returns the minimum y-coordinate of any intersection between a given vertical
//line and the lower envelope
long long query(long long x)
{
	//If we removed what was the best line for the previous query, then the
	//newly inserted line is now the best for that query
	if (pointer>=M.size())
		pointer=M.size()-1;
	//Any better line must be to the right, since query values are
	//non-decreasing
	while (pointer<M.size()-1&&
	  M[pointer+1]*x+B[pointer+1]<M[pointer]*x+B[pointer])
		pointer++;
	//cout << pointer << " " << M[pointer] << " " << B[pointer] << endl;
	return M[pointer]*x+B[pointer];
}
#define MAXN 100010
ll dp[MAXN];
int main(){
	int n;
	scanf("%d", &n);
	ll a[n], b[n];
	for(int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for(int i = 0; i < n; i++)
		scanf("%lld", &b[i]);
	add(a[n-1], 0);
	for(int i = n-2; i >= 0; i--){
		dp[i] = query(b[i]);
		add(a[i], dp[i]);
		//cout << dp[i] << endl;
	}

	printf("%lld\n", dp[0]);
}