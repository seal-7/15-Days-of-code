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
/*

NOT SUBMITTED
*/

int tellMe(string str){
	int l=0,r=0,max_count=0;
	for(int i=0; i< str.length(); i++){		
		if(str[i]=='('){
			l++;
			max_count=max(max_count,min(l,r));
		}
		if(str[i]==')'){
			r++;	
			if(r>l){
				r=0,l=0;
		    }
			max_count=max(max_count,min(l,r));
		}
		 // cout<<str[i]<<" "<<r<<" "<<l<<" "<<max_count<<endl;
	}
	return max_count;
}
int main(){
	string str;
	cin>>str;
	cout<<tellMe(str)*2<<endl;
	return 0;
}