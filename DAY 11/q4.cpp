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
int mat[1000][1000];
int n,m,b;
void dfs(int i,int j){
	if(i<=0 or j<=0 or i>n or j>m or mat[i][j]==-1 or mat[i][j]==1){
		return ;
	}
	mat[i][j]=1;
	dfs(i,j-1);
	dfs(i-1,j);
	dfs(i,j+1);
	dfs(i+1,j);
}
void print(){
	for(int i=1; i<=n; i++){
		for(int j=1;j<m;j++){
			cout<<mat[i][j]<<" ";		
		}
		cout<<"\n";
	}
}
int main(){
	cin>>n>>m>>b;
	while(b--){
		int l,r;
		cin>>l>>r;
		mat[l][r]=-1;
	}
	int count=0;
		for(int i=1;i<=n;i++){
			for(int j=1; j<=m; j++){
				if(mat[i][j]==0){
					dfs(i,j);
					count++;
				}
			}
		}
		cout<<count<<endl;
	return 0;
}