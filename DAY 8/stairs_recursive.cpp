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
vector< vector<int> >  memo(2,vector<int> (100000,-1));
int tellme(int n,bool flag){
	if(n<0){
		return 0;
	}
	if(n==0){
		return 1;
	}
	if(memo[flag][n]!=-1){
		return memo[flag][n];
	}








	
	if(flag){
		 memo[1][n]=tellme(n-1,true)+tellme(n-2,false);
	}
	else{
		return memo[0][n]=tellme(n-1,true);
	}
}
int main(){
	int n;
	cin>>n;
	cout<<tellme(n,true)<<endl;
	return 0;
}