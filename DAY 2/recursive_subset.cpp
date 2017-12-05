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
vector<int > vec;
vector<bool> check(10000,true);
void printAll(int pos){
	if(pos==vec.size()){
		for(int i=0; i< vec.size(); i++){
			if(check[i])
			cout<<vec[i]<<" ";
		}
		cout<<endl;
		return;
	}
		printAll(pos+1);
		check[pos]=false;
		printAll(pos+1);
		check[pos]=true;
}
int main(){
	int n;
	cin>>n;
	int val;
	for(int i=0; i< n; i++){
		cin>>val;
		vec.pb(val);
	}
	printAll(0);
	return 0;
}