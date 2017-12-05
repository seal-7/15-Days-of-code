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
vector<int> adj[100005];
int recur(int i){
	if(adj[i].size()==0){
		return 0;
	}
	int sum=0;
	for(int j=0;j<adj[i].size(); j++){
		sum+=(1+recur(adj[i][j]));
	}
	return sum;
}
int main(){
	int n,q;
	cin>>n>>q;
	for(int i=0; i< n-1; i++){
		int x,y;
		cin>>x>>y;
		adj[x].pb(y);		
	}
	vector<int> pre(100005,0);
	for(int i=1;i<=n;i++){
		pre[i]=recur(i)+1;
	}
	for(int i=2;i<=n;i++){
		pre[i]=pre[i]+pre[i-1];
	}
	// for(int i=1;i<=n;i++){
	// 	cout<<pre[i]<<" ";
	// }
	// cout<<"\n";
	while(q--){
		int l,r,sum=0;
		cin>>l>>r;
		cout<<pre[r]-pre[l-1]<<endl;
	}
	return 0;
}