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
	ll n,f;
	cin>>n>>f;
	vector<pair<ll,pair<ll,ll> > > vec;
	ll l,r;
	for(int i=0;i<n;i++){
		cin>>l>>r;		
		vec.pb(make_pair(((2*l)-r),make_pair(l,r)));
	}
	sort(vec.begin(),vec.end());
	ll check=0,ans=0,count=0;
	for(int i=n-1;i>=0;i--){
		cout<<vec[i].first<<" "<<vec[i].second.first<<" "<<vec[i].second.second<<endl;
		ans+=(min(2*vec[i].second.first,vec[i].second.second));
		 count++;
		 if(count==f){
		 	break;
		 }		
	}
	cout<<ans<<endl;
	return 0;
}