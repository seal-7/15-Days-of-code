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
	 std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	int n,s;
	cin>>n>>s;
	int a[n];
	for(int i=0; i< n; i++){
		cin>>a[i];
	}
	int l=0,r=0;
	int maxsum=INT_MIN;
	int sum=0;
	while(r<n){
		sum+=a[r];
		if(sum>s){
			while(sum>s){
				sum-=a[l];
				l++;
			}			
		}
		maxsum=max(sum,maxsum);
		r++;
	}
	cout<<maxsum<<endl;
	return 0;
}