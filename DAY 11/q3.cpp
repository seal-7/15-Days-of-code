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
vector<int> vis(100005,false);

ll prims(int s,vector<pair<int,int> > vec[3005]){
	
	priority_queue< pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > > que;
	ll sum=0;
	que.push(make_pair(0,s));
	while(!que.empty()){
		pair<int,int> p=que.top();
		que.pop();
		if(vis[p.second]){
			continue;
		}
		vis[p.second]=true;
		sum+=p.first;
		for(int i=0;i<vec[p.second].size();i++){
			que.push(make_pair(vec[p.second][i].second,vec[p.second][i].first));
		}
	}
	
	return sum;
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,int> > vec[m+5];
	for(int i=0; i< m; i++){
		int x,y,z;
        cin>>x>>y>>z;
        vec[x].pb(make_pair(y,z));
        vec[y].pb(make_pair(x,z));
	}
	cout<<prims(0,vec);
	return 0;
}


