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
	int t,k;
	cin>>t>>k;
	vector<int> vec(100005,0);
	vector<int> cumsum(100005,0);
	cumsum[0]=1;
	for(int i=0; i<k; i++){
		vec[i]=1;	
	}
	for(int i=k;i<=100005;i++){
		vec[i]=(vec[i-1]+vec[i-k])%MOD;
	}
	for(int i=1;i<=100005;i++){
		cumsum[i]=(cumsum[i-1]+vec[i])%MOD;
	}
	while(t--){
       int a,b;
       cin>>a>>b;
       cout<<(cumsum[b]-cumsum[a-1]+MOD)%MOD<<endl;
	}
	return 0;
}

/*
8958
71050
1596
18405
20192
9668
288
33054
32860
2351
7720
20842
9129
31509
185
2796
13407
71416
2735
73794
4205
64678
1371
14919
46703
7657
38752
2195
36166
41212
3111
1056
3860
391
10128
357
8758
9313
*/