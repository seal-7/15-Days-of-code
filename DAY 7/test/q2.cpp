#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
#define sz(a) int((a).size())
#define FOR(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define sor(a) sort((a).begin(),(a).end())
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()

int main(){
  int n;
  cin >> n;
  vector< ii > arr;
  int tmp1,tmp2;
  FOR(i,0,n){
    cin >> tmp1 >> tmp2;
    arr.push_back(mp(tmp1,tmp2));
  }
  sor(arr);
  int curr = arr[0].second;
  FOR(i,1,n){
    if( curr > arr[i].second ){
      curr = arr[i].first;
    }else{
      curr = arr[i].second;
    }
  }
  cout << curr << endl;
}