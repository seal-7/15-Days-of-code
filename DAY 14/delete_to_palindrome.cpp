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
int memo[100][100];
int recur(string str,int i,int j){
	if(i>j){
		return 0;
	}
	if(memo[i][j]!=-1){
		return memo[i][j];
	}
	if(str[i]==str[j]){
		return memo[i][j]=recur(str,i+1,j-1);
	}
	return memo[i][j]=1+min(recur(str,i+1,j),recur(str,i,j-1));
}
int main(){
	string str;
	for(int i=0; i< 100; i++){
		for(int j=0; j< 100; j++){
	 		memo[i][j]=-1;		
		}
	}
	cin>>str;
	cout<<recur(str,0,str.length()-1);
	return 0;
}