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
int x,y;
int tellMe(int a,int b,int c,int which){
	int r=x,l;
	if(which==1)
		l=a;
	else if(which==2)
		l=b;
	else
		l=c;
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(which==1){
			if(mid+b>c and b+c>mid and c+mid>b){
				l=mid+1;
				ans=mid;
			}
			else{
				r=mid-1;
			}
		}
		if(which==2){
			if(a+mid>c and mid+c>a and c+a>mid){
				l=mid+1;
				ans=mid;
			}
			else{
				r=mid-1;
			}
		}
		if(which==3){
			if(a+b>mid and b+mid>a and mid+a>b){
				l=mid+1;
				ans=mid;
			}
			else{
				r=mid-1;
			}
		}
	}
	return ans;
}
int main(){
	cin>>x>>y;
	int a=y,b=y,c=y;
	int count=0;
	int l,m,n;
	while(a!=x or b!=x or c!=x){
		if(a!=x){
			a=tellMe(a,b,c,1);
			count++;
		}
		if(b!=x){
			b=tellMe(a,b,c,2);
			count++;
		}
		if(c!=x){	
			c=tellMe(a,b,c,3);
			count++;	
		}
	}
	cout<<count<<endl;	
	return 0;
}