/*
 ____    _____      _      _               _____ 
/ ___|  | ____|    / \    | |             |___  |
\___ \  |  _|     / _ \   | |      _____     / / 
 ___) | | |___   / ___ \  | |___  |_____|   / /  
|____/  |_____| /_/   \_\ |_____|          /_/   

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define modulo(a, b) (a%b<0 ? a%b+b : a%b)
#define PI 3.1415926535897
#define ceil(a,b) ((a+b-1)/b)
#define MOD 1000000007
vector<int> memo(100005,-1);
int fib(int i){
	if(i<=0){
		return 0;		
	}
	if(i==1){
		return 1;
	}
	if(memo[i]!=-1){
		return memo[i];
	}
	return memo[i]=((fib(i-2)+fib(i-1))%MOD);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(memo[n-1]==-1)			
			cout<<fib(n-1);
		else
			cout<<memo[n-1];
		cout<<"\n";
	}
	return 0;
}