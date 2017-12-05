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
typedef vector<int> vi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define modulo(a, b) (a%b<0 ? a%b+b : a%b)

int main(){
	vector<int> v[1005];
    int q;
    cin>>q;
    while(q--){
    	int n,m,val1,val2,source;
    	cin>>n>>m;
    	for(int i=0; i< n+3; i++){
    		v[i].clear();
    	}
    	for(int i=0; i< m; i++){
    		cin>>val1>>val2;
    		v[val1].push_back(val2);
    		v[val2].push_back(val1);
    	}
    	cin>>source;

    	queue <int> que;
    	vector<bool> visited(n+5,false);
    	vector<int> distance(n+5,-1);
    	
    	que.push(source);
    	visited[source]=true;
    	distance[source]=0;
    	while(!que.empty()){
    		int p=que.front();
    		que.pop();
    		for(int i=0; i< v[p].size(); i++){
    			if(!visited[v[p][i]]){
    				que.push(v[p][i]);
    				distance[v[p][i]]=distance[p]+6;
    				visited[v[p][i]]=true;
    			}
    		}
    	}

    	for(int i=1; i<=n; i++){
    		if(i==source){
    			continue;	
    		}
    		else if (distance[i]==0)
    		{
    			cout<<-1<<" ";
    		}
    		else
    		cout<<distance[i]<<" ";
    	}
    	cout<<"\n";

    }
	return 0;
}