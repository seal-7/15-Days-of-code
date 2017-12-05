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
#define HIS 1
#define MY 0
vector<int> vec;
int sum,sum1;
int dp[3][1000][1000];
int recur(int i,int j,int turn){
	if(j<i){
		return 0;
	}
	if(dp[turn][i][j]!=0){
		return dp[turn][i][j];
	}
	if(turn == MY){
		return dp[turn][i][j]=max(vec[i]+recur(i+1,j,HIS),vec[j]+recur(i,j-1,HIS));
	}
	else{
		return dp[turn][i][j]=min(recur(i+1,j,MY),recur(i,j-1,MY));
	}
}
int main(){
	int n;
	cin>>n;
	int val;
	for(int i=0; i< n; i++){
		cin>>val;
		vec.pb(val);
	}
	cout<<recur(0,vec.size()-1,MY)<<endl;
	return 0;
}