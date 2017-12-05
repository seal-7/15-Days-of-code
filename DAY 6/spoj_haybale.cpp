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
int n,k;
void update_point(int i,vector<int> &bit,int value){
	while(i<=n){
		bit[i]+=value;
		i+=(i&(-i));
	}
}
void update_range(int l,int r,vector<int> &bit){	
	update_point(l,bit,1);
	update_point(r+1,bit,-1);
}
int query(int i,vector<int> &bit){
	int sum=0;
	while(i!=0){
		sum+=bit[i];
		i=i&(i-1);
	}
	return sum;
}
int main(){
	cin>>n>>k;
	vector<int> bit(n+1,0);
	while(k--){
		int l,r;
		cin>>l>>r;
		update_range(l,r,bit);
		for(int i=1; i<=8; i++){
			cout<<bit[i]<<" ";
		}
		cout<<"\n";
		//cout<<query(3,bit)<<endl;
	}
	vector<int> vec;
	for(int i=1; i<=n; i++){
		vec.pb(query(i,bit));
	}
	for(int i=1; i<=8; i++){
		cout<<query(i,bit)<<" ";
	}
	sort(vec.begin(),vec.end());
	//cout<<vec[n/2]<<endl;
	return 0; 
}