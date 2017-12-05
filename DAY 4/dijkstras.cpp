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
vector<int> dijkastra(vector<pair<int,int> > adj[3005],int source){
	vector<bool> vis(3005,false);
	vector<int> ans(3005,-1);
	priority_queue< pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > > que;
	que.push(make_pair(0,source));
	while(!que.empty()){
		pair<int,int> p;
		p=que.top();
		que.pop();
		if(vis[p.second]){
			continue;
		}
		vis[p.second]=true;
		if(p.second!=source){
			//ans.insert(make_pair(p.second,p.first));
			ans[p.second]=p.first;
		}	
		for(int i=0;i<adj[p.second].size();i++){			
			que.push(make_pair(p.first+adj[p.second][i].first,adj[p.second][i].second));						
		}

	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){	
		int n,m;
		cin>>n>>m;
		vector<pair<int,int> > adj[n+5];
		while(m--){
			int x,y,w;
			cin>>x>>y>>w;
			adj[x].pb(make_pair(w,y));
			adj[y].pb(make_pair(w,x));		
		}
		int s;
		cin>>s;
		vector<int> ans=dijkastra(adj,s);
		for(int i=1; i<=n; i++){
			if(i==s){
				continue;
			}
			else{
				cout<<ans[i]<<" ";
			}
		}
		cout<<"\n";
	}
	return 0;
}