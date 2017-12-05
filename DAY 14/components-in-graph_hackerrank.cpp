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
	int n;
	cin>>n;
	vector<pair<int,int> > vec;
	int max_elem=INT_MIN;
	for(int i=0; i< n; i++){
		int x,y;
		cin>>x>>y;
		max_elem=max(max_elem,max(x,y));
		vec.pb(make_pair(x-1,y-1));
	}
	UnionFind u(max_elem);
	for(int i=0; i< n; i++){
		if(!u.isSameSet(vec[i].first,vec[i].second)){
			u.unionSet(vec[i].first,vec[i].second);
		}
	}
	int max_size=INT_MIN,min_size=INT_MAX;
	for(int i=0; i< n; i++){
		max_size=max(max_size,u.sizeOfSet(vec[i].first));
		max_size=max(max_size,u.sizeOfSet(vec[i].second));
		min_size=min(min_size,u.sizeOfSet(vec[i].first));
		min_size=min(min_size,u.sizeOfSet(vec[i].second));
	}
	cout<<min_size<<" "<<max_size<<endl;
	return 0;
}