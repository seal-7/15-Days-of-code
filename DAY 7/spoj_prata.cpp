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
ll tellMe(ll t,vector<int> vec){
	ll sum=0;	
	for(int i=0;i<vec.size();i++){
		ll x=(2*t)/vec[i];
		ll sr=sqrt(1+(4*x));
		sum+=((-1+sr)/2);
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int p;
		cin>>p;
	    int chefs;
	    cin>>chefs;
	    vector<int> vec(chefs);
	    for(int i=0; i< chefs; i++){
	    	cin>>vec[i];
	    }
	    ll l=0,r=INT_MAX;
	    ll ans=0;
	    for(int i=0;i<100;i++){
	    	ll mid=(l+r)/2;
	    	if(tellMe(mid,vec)>=p){
	    		r=mid-1;
	    		ans=mid;
	    	}
	    	else{
	    		l=mid+1;
	    	}
	    }
	    cout<<ans<<endl;
	}
	return 0;
}