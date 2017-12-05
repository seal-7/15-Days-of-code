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
class UnionFind {                                              
	private:
	  
	  vi p, rank, setSize;                       // remember: vi is vector<int>
	  int numSets;

	public:
	  UnionFind(int N) {
	    setSize.assign(N, 1); 
	    numSets = N; rank.assign(N, 0);
	    p.assign(N, 0);
	     for (int i = 0; i < N; i++)
	      	p[i] = i;
	    }
	  int findSet(int i) { 
	  	return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	  }
	  bool isSameSet(int i, int j) { 
	  	return findSet(i) == findSet(j);
	  }
	  void unionSet(int i, int j) { 
	    if (!isSameSet(i, j)) { 
	    	numSets--; 
	    	int x = findSet(i), y = findSet(j);
	    	// rank is used to keep the tree short
	    	if (rank[x] > rank[y]) {
	    		 p[y] = x; 
	    		 setSize[x] += setSize[y];
	    	}
	    	else{
	    	 p[x] = y;
	    	 setSize[y] += setSize[x];
	            if (rank[x] == rank[y]) 
	            	rank[y]++;
	        }
	    }
	  }
	  int numDisjointSets() { 
	  	return numSets;
	  }
	  int sizeOfSet(int i) { 
	  	return setSize[findSet(i)];
	  }
};
int main(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,pair<int,int> > > vec;
	int w,x,y;
	for(int i=0; i< m; i++){		
		cin>>x>>y>>w;
		vec.pb(make_pair(w,make_pair(x,y)));
	}
	sort(vec.begin(),vec.end());
	UnionFind  u(n);
	int ans=0;
	for(int i=0;i<m;i++){
		int x,y;
		x=vec[i].second.first;
		y=vec[i].second.second;
		if(!u.isSameSet(x-1,y-1)){
			u.unionSet(x-1,y-1);
			ans+=vec[i].first;
		}
	}	
	cout<<ans<<endl;
	return 0;
}