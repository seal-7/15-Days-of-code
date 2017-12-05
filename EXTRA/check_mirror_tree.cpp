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
struct Node
{
    int key;
    struct Node* left, *right;
};
 
// Utility function to create new Node
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key  = key;
    temp->left  = temp->right = NULL;
    return (temp);
}
bool checkSymetric(Node *r1,Node *r2){
	if(r1==NULL and r2==NULL){
		return true;
	}
	if(r1!=NULL and r2!=NULL and r1->key==r2->key){
		return checkSymetric(r1->left,r2->right)&&checkSymetric(r2->left,r1->right);
	}
	return false;
}
 bool isSymmetric(Node *root){
 	return checkSymetric(root,root);
 }
int main(){
	 Node *root        = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(2);
    root->left->left  = newNode(3);
    root->left->right = newNode(4);
    root->right->left  = newNode(4);
    root->right->right = newNode(3);
 
    cout << isSymmetric(root);
	return 0;
}