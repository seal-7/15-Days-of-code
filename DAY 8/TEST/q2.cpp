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
int s,m,d;
int cnt=0;
int recur(int j,int sum){
    if(sum>s){
        return 0;
    }
    if(sum==s){
        return 1;
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        if(abs(i-j)<=d and j!=0){
             ans+=recur(i,sum+i);
        }
        if(j==0){
            ans += recur(i,sum+i);
        }
    }
    return ans;
}
int main(){
    
    cin>>s>>m>>d;
    cout<<recur(0,0);
    //cout<<cnt<<endl;
    return 0;
}