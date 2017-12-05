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
typedef vector<int> vi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define modulo(a, b) (a%b<0 ? a%b+b : a%b)
vector<int> v[1005];
vector<bool> vist[1005];
int n,m;
void dfs(int i,int j){
	if(i>=n or j>=m or i<0 or j<0 or vist[i][j]==true or v[i][j]==0)
		return;
	vist[i][j]=true;
	dfs(i+1,j);
	dfs(i,j+1);
	dfs(i-1,j);
	dfs(i,j-1);
	dfs(i-1,j-1);
	dfs(i-1,j+1);
	//dfs(i+1,j+1);
	dfs(i+1,j-1);
}
int main(){
	int val;
	cin>>n>>m;
	
	for(int i=0; i< n; i++){
		for(int j=0; j< m; j++){
			cin>>val;
			v[i].push_back(val);
			vist[i].push_back(false);
		}
	}
int count=0;
//cout<<v[0][0]<<"DSAD"<<endl;
	for(int i=0; i< n; i++){
		for(int j=0; j< m; j++){
			if(!vist[i][j] and v[i][j]==1){
				cout<<i<<" "<<j<<endl;
				dfs(i,j);
				count++;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}