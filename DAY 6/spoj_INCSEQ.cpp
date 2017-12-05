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
	int n,k;
	cin>>n>>k;
	vector<int> vec(n);
	vector<int> dp(n+1,INT_MAX);
	vector<int> count(n+1,0);
	dp[0]=INT_MIN;
	for(int i=0;i<n;i++){
		cin>>vec[i];
		int pos=lower_bound(dp.begin(),dp.end(),vec[i])-dp.begin();
		dp[pos]=min(dp[pos],vec[i]);
		count[pos]=((count[pos]+1)%5000000);
	}
 	ll ans=0;
 	//int i=1;
 	for(int i=1; i<=n; i++){
 		cout<<count[i]<<" ";
 	}
 	// while(i<n){
 	// 	ll multi=1;
 	// 	for(int j=i;j<i+k;j++){
 	// 		if(j==n or count[j]==0){
 	// 			break;
 	// 		}
 	// 		multi*=count[i];
 	// 	}
 	// 	ans+=multi;
 	// 	i++;
 	// }
 	//cout<<ans<<endl;
	return 0;
}
