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
	int t;
	cin>>t;

	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int> vec;
		int val;
		int sum=0;
		for(int i=0; i< n; i++){
			cin>>val;
			sum+=val;
			vec.pb(val);
		}
		sort(vec.begin(),vec.end());
		int sum1=0,sum2=0;
		for(int i=0;i<k;i++){
			sum1+=vec[i];
		}
		for(int i=n-k;i<n;i++){
			sum2+=vec[i];
		}

		cout<<max(abs(sum-2*sum1),abs(sum-(2*sum2)))<<endl;
			
	}
	return 0;
}