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
int lcs(string s1,string s2,int n,int m){
	if(n<0 or m<0){
		return 0;
	}
	if(s1[n]==s2[m]){
		return 1+lcs(s1,s2,n-1,m-1);
	}
	else{
		return max(lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1));
	}
}
int main(){
	int n,m;
	string s1,s2;
	cin>>s1>>s2;
 	cout<<lcs(s1,s2,s1.length()-1,s2.length()-1);
	return 0;
}