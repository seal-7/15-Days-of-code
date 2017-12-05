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
struct node
{
	int val;
	node *next=NULL;
};
void add(node *head,int data){
	if(head==NULL){
		node *temp=new node();
		temp->val=data;
		temp->next=NULL;
		head=temp;
		return ;
	}
	if(head->next==NULL){	
		node *temp=new node();
		temp->val=data;
		temp->next=NULL;
		head->next=temp;
		return;
	}
	add(head->next,data);
}
void traverse(node *head){
	node *temp=head;
	while(head!=NULL){
		cout<<head->val<<endl;
		head=head->next;
	}
}
int main(){
	int n;
       	cin>>n;
	node * head=NULL;
 	int val;
	node *temp=head;
	for(int i=0;i<n;i++){
		cin>>val;
		add(temp,val);
	}
	traverse(head);	
	return 0;
}

