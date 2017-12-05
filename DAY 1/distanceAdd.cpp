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
struct store{
	int m;
	int cm;
	int mm;
}
int main(){
	stringstream ss;	
	store s1,s2;
	string str;
	cin>>str;
	string temp;
	int i=0;
	for (i = 0;str[i]!='m'; i++) {
		temp+=str[i];
	}
	ss<<temp;
	ss>>s1.m;
	ss.clear();
	temp="";
	for(i=i+1;str[i]!='c' and str[i+1]!='m';i++){
		temp+=str[i];
	}
	ss<<temp;
	ss>>s1.cm;
	ss.clear();
	temp="";
	for (i=i+1; str[i]!='m' and str[i+1]!='m'; i++) {
		temp+=str[i];
	}
	ss<<temp;
	ss>>s1.mm;
	ss.clear();
	temp="";
	
	cin>>str;
	//string temp;
	i=0;
	for (i = 0;str[i]!='m'; i++) {
		temp+=str[i];
	}
	ss<<temp;
	ss>>s2.m;
	ss.clear();
	temp="";
	for(i=i+1;str[i]!='c' and str[i+1]!='m';i++){
		temp+=str[i];
	}
	ss<<temp;
	ss>>s2.cm;
	ss.clear();
	temp="";
	for (i=i+1; str[i]!='m' and str[i+1]!='m'; i++) {
		temp+=str[i];
	}
	ss<<temp;
	ss>>s2.mm;
	ss.clear();
	temp="";
	cout<<s1.m<<" "<<s1.cm<<" "<<s1.mm<<endl;
	return 0;
}

