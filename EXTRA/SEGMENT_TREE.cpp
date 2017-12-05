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
vector<int> seg(4*100005);
vector<int> vec;
map<long, long> F;

ll f(ll n) {
	if (F.count(n)) return F[n];
	ll k=n/2;
	if (n%2==0) { 
		return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % MOD;
	} else { 
		return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % MOD;
	}
}

int build(int curr,int l,int r){
	if(l==r){
		return seg[curr]=vec[l];
	}
	return seg[curr]=__gcd(build(curr*2,l,(l+r)/2),build((2*curr)+1,(l+r)/2+1,r));
}
int query(int curr,int l,int r,int ql,int qr){
	if(ql>r or qr<l or l>r){
		return 0;
	}
	if(l>=ql and r<=qr){
		return seg[curr];
	}
	return __gcd(query(2*curr,l,(l+r)/2,ql,qr),query((2*curr)+1,(l+r)/2+1,r,ql,qr));
}
int main(){
	int n,m;
	cin>>n>>m;
	int val;
	for(int i=0; i< n; i++){
		cin>>val;
		vec.pb(val);
	}
	build(1,0,n-1);
	F[0]=F[1]=1;
	while(m--){
		int l,r;
		cin>>l>>r;
		int fth=query(1,0,n-1,l-1,r-1);
		cout << f(fth-1) << endl;
	}
	return 0;
}

// 3 2
// 2 5 25
// 1 2
// 2 3