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
ll expo(ll n,ll m){
	if(m==2){
		return (n*n)%MOD;
	}
	if(m%2==0){
		return (expo(n,m>>1)*expo(n,m>>1))%MOD;
	}
	else{
		return (n*expo(n,m-1))%MOD;	
	}
}
ll powerMod(ll x,ll y){
    ll ans=1;
    ll square=x;
    if(y==0)
        return 1;
    while(y!=0){
        if(y%2)
            ans=ans*square;
        square=(square*square)%MOD;
        y=y/2;
        if(ans>MOD)
            ans=ans%MOD;
    }
    return ans;
}
int main(){
	ll n,m;
	cin>>n>>m;
	cout<<expo(n,m)<<" "<<powerMod(n,m);
	return 0;
}