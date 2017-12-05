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
	int n;
	cin>>n;
	vector<int> vec;
	int val;
	for(int i=0; i< n; i++){
		cin>>val;
		vec.pb(val);
	}
	vector<int> dp(n,0);
	dp[0]=1;
	for(int i=1; i< n; i++){
		for(int j=i-1;j>=0;j--){
			if(vec[j]<vec[i]){
				dp[i]=max(dp[i],vec[j]);
				if(j-1<0){
					dp[i]++;
				}
			}
		}		
	}
	for(int i=0; i< n; i++){
		cout<<dp[i]<<" ";
	}
	cout<<dp[n-1]<<endl;
	return 0;
}