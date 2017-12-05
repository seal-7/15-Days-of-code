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
string str1;
	string str2;
	int n,m;
	vector<vector<int> > dp(2005,vector<int> (2005,-1));
int recur(int i,int j){
	if(i==n){
		return m-j;
	}
	if(j==m){
		return n-i;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	if(str1[i]==str2[j]){
		return dp[i][j]=recur(i+1,j+1);
	}
	return dp[i][j]=min(recur(i,j+1),min(recur(i+1,j+1),recur(i+1,j)))+1;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<=2000;i++){
			for(int j=0; j<=2000; j++){
				dp[i][j]=-1;
			}
		}
		cin>>str1>>str2;
		n=str1.length();
		m=str2.length();
		cout<<recur(0,0)<<"\n";
	}
	return 0;
}