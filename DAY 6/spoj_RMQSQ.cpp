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
vector<int> vec(100005);
	vector<int> seg(4*100005);
int create(int curr,int l,int r){
	if(l==r){
		return seg[curr]=vec[l];
	}
	return seg[curr]=min(create(2*curr,l,(l+r)/2),create(2*curr+1,((l+r)/2)+1,r));
}
int query(int curr,int ql,int qr,int l,int r){
	if(ql>r or qr<l){
		return INT_MAX;
	}
	else if(ql<=l and qr>=r){
		return seg[curr];
	}
	else{
		return min(query(2*curr,ql,qr,l,(l+r)/2),query(2*curr+1,ql,qr,(l+r)/2+1,r));
	}
}
int update(int curr,int ql,int qr,int l,int r,int val){
	
	if(l==r and l==ql){
		return seg[curr]=val;
	}
	else if((ql<l and qr<l )or(ql>r and qr>r) ){
		return seg[curr];
	}
	return seg[curr]=min(update(2*curr,ql,qr,l,(l+r)/2,val),update(2*curr+1,ql,qr,((l+r)/2)+1,r,val));
}
int main(){
	int n;
	cin>>n;	
	for(int i=1; i<=n; i++){
		cin>>vec[i];			
	}
	create(1,1,n);
	int q;
	//update(1,2,2,1,3,5);
	cin>>q;
	while(q--){
		int l, r;
		cin>>l>>r;
		cout<<query(1,l+1,r+1,1,n)<<endl;
	}
	return 0;
}