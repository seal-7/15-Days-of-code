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
string str1;	
string str2;
string dp[1005][1005];
string recur(int i,int j){
	if(i<0 or j<0){
		return "";
	}
	if(dp[i][j]!="#"){
	 	return dp[i][j];
	}
	if(str1[i]==str2[j]){
		return dp[i][j]= recur(i-1,j-1)+str1[i];
	}
	string s1=recur(i-1,j);
	string s2=recur(i,j-1);
	if(s1.length()==s2.length())
		return dp[i][j]=min(s1,s2);
	else{
		if(s1.length()>s2.length()) return dp[i][j]=s1;
		else return dp[i][j]= s2;
	}
}
int main(){
	
	cin>>str1>>str2;
	for(int i=0; i< str1.length(); i++){
		for(int j=0; j< str2.length(); j++){
			dp[i][j]="#";
		}
	}
	string ans=recur(str1.length()-1,str2.length()-1);
	cout<<ans<<endl;	
	for(int i=0; i< str1.length(); i++){
		for(int j=0; j< str2.length(); j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}