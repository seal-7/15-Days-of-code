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
typedef vector<int> vi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define modulo(a, b) (a%b<0 ? a%b+b : a%b)
int tellind(vector<int> vec,int l,int r,int x){
	int mid=(l+r)/2;
	if(l>r){
		return -1;
	}
	if(vec[mid]==x){
		return mid;
	}
	if(x>vec[mid]){
		return tellind(vec,mid+1,r,x);
	}
	else{
		return tellind(vec,l,mid-1,x);
	}
}
int main(){
	int n;
	cin>>n;
	vector<int> vec;
	int val;

	for(int i=0;i<n;i++){
		cin>>val;		
		vec.pb(val);
	}
	sort(vec.begin(),vec.end());
	int find;
	cin>>find;	
	cout<<tellind(vec,0,vec.size()-1,find);
	return 0;
}

