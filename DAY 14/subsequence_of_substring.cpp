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
int dp[1000][1000];
int recur(int i,int j,string str1,string str2){
	if(i<0 or j<0){
		return 0;
	}
	if(str1[i]==str2[j]){
		return recur(i-1,j-1,str1,str2)+1;
	}
	return recur(i-1,j,str1,str2);
}
int main(){
	string str1,str2;
	cin>>str2>>str1;
	int max_ans=0;
	for(int i=str2.length();i>=0;i--){
		max_ans=max(max_ans,recur(str1.length()-1,i,str1,str2));
	}
	cout<<max_ans<<endl;
	return 0;
}