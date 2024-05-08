/*
Cho cây nhị phân, nhiệm vụ của bạn là kiểm tra xem cây nhị phân có phải là một cây đủ hay không (full binary tree)? Một cây nhị phân được gọi là cây đủ nếu tất cả các node trung gian của nó đều có hai node con.
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	int data;
	node *left;
	node *right;
	node(int x){
		data = x;
		left = right = NULL;
	}
};
bool ok = true;
void duyet_NLR(node* tree){
	if(tree != NULL){
		node* l = tree->left;
		node* r = tree->right;
		if((l==NULL && r!=NULL) || (l!=NULL && r==NULL)) 
			ok = false;
		duyet_NLR(tree->left);
		duyet_NLR(tree->right);
	}
}
void insert(node* &tree, int u, int v, char c){
	if(tree == NULL) return;
	if(tree->data == u){
		if(c == 'L') tree->left = new node(v);
		else tree->right = new node(v);
	}
	else {
		insert(tree->left, u, v, c);
		insert(tree->right, u, v, c);
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int canh = n;
		node* tree = NULL;
		while(n--){
			int u, v;
			char c;
			cin >> u >> v >> c;
			if(tree == NULL){ // chua co node nao
				tree = new node(u); // tao node goc co gia tri data bang u
				if(c == 'L') tree->left = new node(v);
				else tree->right = new node(v);
			}
			else insert(tree, u, v, c);
		}
		duyet_NLR(tree);
		if(ok) cout << 1 << endl;
		else cout << 0 << endl;
		ok = true;
	}	
}
