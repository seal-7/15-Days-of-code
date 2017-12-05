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
#define LEFT 1
#define RIGHT 1
vector<string> vec(20);
vector<int> Left(1000);
vector<int> Right(1000);
int n,m;
int recur(int f,int d){

	if(f==n-1 and d==LEFT){
		return Left[f];
	}
	if(f==n-1 and d==RIGHT){
		return Right[f];
	}
	if(d==LEFT){
		return 1+min(2*Left[f]+recur(f+1,LEFT),m+1+recur(f+1,RIGHT));
	}
	else{
		return 1+min(2*Right[f]+recur(f+1,RIGHT),m+1+recur(f+1,LEFT));
	}
}
int main(){
	cin>>n>>m;
	for(int i=0; i<n; i++){
		cin>>vec[i];
	}
	int x=n-1;
	bool check=false;
	for(int i=0; i< n; i++){
		int pos=0;
		for(int j=1; j<=m; j++){
			if(vec[i][j]=='1'){
				pos=j;
				check=true;
			}
		}
		Left[x]=pos;
		pos=0;
		for(int j=m; j>=1; j--){
			if(vec[i][j]=='1'){
				pos=j;
			}
		}
		Right[x]=(m-pos+1);
		x--;
	}
	 for(int i=n-1; i>=0; i--){
	 	cout<<Left[i]<<" "<<Right[i]<<endl;
	 }
	if(!check){
		cout<<0<<endl;
	}
	else{
		cout<<recur(0,LEFT)<<endl;
	}
	return 0;
}