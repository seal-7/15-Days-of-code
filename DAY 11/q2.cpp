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

ll n;


ll binarySearch(ll f,ll l,ll j){
    ll val,ans=0;
    while(f<=l){
      val= (f>>1)+(l>>1) + (f&l&1);
      
      if(val*(val+1)/2 - (j*(j+1))/2  <=n){    
          f=val+1;
          ans= max(ans,val);
      }else{
        l=val-1;    
      }
    }

    return ans;
}

int main(){
    cin>>n;

    for (int i = 1; i <=n; ++i)
    {
         ll val= binarySearch(i,n,i-1);
         if(val*(val+1)/2 - (i*(i-1))/2 ==n){
            cout<<i<<" "<<val;
            break;
         }
    }

    
}