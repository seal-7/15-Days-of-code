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
	int n;
	cin>>n;
	vector<string> vec;
	vector<string> sorted;
	vector<int> v(10000,0);
	v[2]=3;
	v[3]=4;
	for(int i=4;i<=10000;i++){
		v[i]=v[i-2]+3;
	}
	string str;
	for(int i=0; i< n; i++){
		getline(cin,str);
		vec.pb(str);
	}
	getline(cin,str);
		vec.pb(str);		
	sorted=vec;
	 sort(sorted.begin(),sorted.end());
	 int count=0;
	for(int i=0;i<vec.size();i++){
		if(vec[i]!=sorted[i]){
			count++;
		}
	}
	if(count==0){
		cout<<0<<endl;
	}
	else{
    	cout<<v[count]<<endl;
	}
	return 0;
}