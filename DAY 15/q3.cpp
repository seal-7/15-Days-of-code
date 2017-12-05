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
int vec[20][20];
int n;
int ans=INT_MAX;
bool vis[20];
void recur(int i,int count,int sum){
	if(count==n){
		if(vec[i][0]!=0){
			ans=min(ans,sum+vec[i][0]);
		}
		return ;
	}
	for(int j=0; j< n; j++){
		if(i!=j and !vis[j] and vec[i][j]!=0){
			vis[j]=true;
			if(sum+vec[i][j]<ans)
				recur(j,count+1,sum+vec[i][j]);
			vis[j]=false;
		}
	}
}
int main(){
	cout<<max("11,21","11,12")<<endl;
	int t;
	cin>>t;
	while(t--){		
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>vec[i][j];
			}
		}
		for(int i=0;i<20;i++){
			vis[i]=false;
		}
		vis[0]=true;
		recur(0,1,0);
		cout<<ans<<endl;
		ans=INT_MAX;
	}
	return 0;
}