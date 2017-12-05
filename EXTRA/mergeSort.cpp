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

void merge(vector<int> &vec,int start,int mid,int end){
	int p=start;
	int q=mid+1;
	int x=0;
	vector<int> arr(end-start+1,0);
	for(int i=start;i<=end;i++){
		if(p>mid){
			arr[x++]=vec[q++];
		}
		else if(q>end){
			arr[x++]=vec[p++];
		}
		else if(vec[p]<vec[q]){
			arr[x++]=vec[p++];
		}
		else{
			arr[x++]=vec[q++];
		}
	}

	for(int i=0;i<x;i++){
		vec[start++]=arr[i];
	}
}
void merge_sort(vector<int> &vec,int start,int end){
	if(start<end){
		int mid=(start+end)/2;
		merge_sort(vec,start,mid);
		merge_sort(vec,mid+1,end);
		merge(vec,start,mid,end);
	}
}
int main(){
	int n;
	cin>>n;
	int val;
	vector<int> vec(n+5,0);
	for(int i=0;i<n;i++){
		cin>>vec[i];
	}	
	merge_sort(vec,0,n-1);
	for(int i=0;i<n;i++){
		cout<<vec[i]<<endl;
	}
	return 0;
}

