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

int main(){
	int n;
	cin>>n;
	vector<vector<int> > dp(2,vector<int> (10000,0));
	dp[0][0]=1;
	dp[0][1]=1;
	dp[1][0]=0;
	dp[1][1]=0;
	for(int i=2;i<=n;i++){
		dp[0][i]=dp[0][i-1]+dp[1][i-1];
		dp[1][i]=dp[0][i-2];
	}
	cout<<dp[0][n]+dp[1][n]<<endl;
	return 0;
}