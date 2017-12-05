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
	vector<int> pre(n+1,INT_MAX);
	pre[0]=INT_MIN;
	for(int i=0; i< n; i++){
		cin>>val;
		vec.pb(val);
		int ind=upper_bound(pre.begin(),pre.end(),val)-pre.begin();
		if(pre[ind-1]!=val)
		pre[ind]=min(val,pre[ind]);

		for(int i=0; i< n; i++){
			cout<<pre[i]<<" ";
		}
		cout<<"\n";
	}

	int count=0;
	for(int i=1;i<n;i++){
		if(pre[i]==INT_MAX)
			break;
		count++;
		//cout<<pre[i]<<" ";
	}
	cout<<count<<endl;

	return 0;
}