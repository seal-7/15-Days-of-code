#include<bits/stdc++.h>
using namespace std;
vector<int> d;
int ans, n;
 
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        vector<int>::iterator it = upper_bound(d.begin(), d.end(), x);
        if (it == d.end()) d.push_back(x);
        else *it = x;
         for(int i=0; i< n; i++){
    		cout<<d[i]<<" ";	
    	}
    	cout<<"\n";
    }
   
    printf("\nLIS = %d", d.size());
    return 0;


// 11
// 3 4 -1 5 6 2 3 12 7 9 10