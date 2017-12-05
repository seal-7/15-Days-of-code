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
#define INF 1e18+7
vector<vector<int> > prime(1000+5,vector<int> (1000+5,0));
int n,m;
vector<vector<int> > vis(1000+5,vector<int> (1000+5,-1));
vector<pair<int,int> > p(100005);
int counter;
void recur(int i,int j,int ways){
	if(prime[i][j]==0 or i>n or j>m or vis[i][j]!=-1 or counter){
		return ;
	}
	vis[i][j]=1;
	p[ways]=make_pair(i,j);
	if(i==n and j==m){
	   counter=ways;
	}
	
		recur(i+1,j+1,ways+1);	
		recur(i+1,j,ways+1);
		recur(i,j+1,ways+1);

	
}
bool isPrime(ll n){
        if(n<=1)
          return false;
        if(n<=3)
          return true;
        if(!(n%2 and n%3))
          return false;
          ll c = ll(sqrt(n)+1e-7);
        for(int i=5;i<=c;i+=6){
            if(!(n%i and n%(i+2)))
               return false;
          }
        return true;
    }
int main(){

	cin>>n>>m;
	vector<vector<int> > vec(n+5,vector<int> (m+5,0));
	vector<vector<ll> > dp(n+5,vector<ll> (m+5,0));
	int val;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>vec[i][j];
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(isPrime(vec[i][j])){
				prime[i][j]=1;
			}
		}
	}
	dp[0][0]=1;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(prime[i][j]==1)
				dp[i][j]=(dp[i][j-1]+dp[i-1][j]+dp[i-1][j-1])%MOD;
		}
	}
	cout<<dp[n][m]<<endl;
	if(dp[n][m]){
		recur(1,1,1);
		for(int i=1;i<=counter;i++){
			cout<<p[i].first<<" "<<p[i].second<<endl;
		}
	}
	return 0;
}