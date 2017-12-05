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
bool tellMe(ll dist,vector<int> vec,int c){
	int count=1;
	ll temp=vec[0]+dist;
	for(int i=1;i<vec.size();i++){
		if(vec[i]>=temp){
			count++;
			temp=vec[i]+dist;
		}
	}
	return count>=c;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,c,val,mainDist=0;
		cin>>n>>c;
		vector<int> vec;		
		for(int i=0; i< n; i++){
			cin>>val;
			vec.push_back(val);
		}
		sort(vec.begin(),vec.end());
		ll left=0,right=vec[vec.size()-1];
		ll mid=0,ans=0;
		while(left<=right){
			mid=(left+right)/2;
			if(tellMe(mid,vec,c)){
				left=mid+1;
				ans=mid;
			}
			else{
				right=mid-1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}