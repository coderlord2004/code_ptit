/*
CÂY NHỊ PHÂN HOÀN HẢO

Bài làm tốt nhất
Cho cây nhị phân, nhiệm vụ của bạn là kiểm tra xem cây nhị phân có phải là một cây hoàn hảo hay không (perfect tree)? Một cây nhị phân được gọi là cây hoàn hảo nếu tất cả các node trung gian của nó đều có hai node con và tất cả các node lá đều có cùng một mức.
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
//Tìm chiều cao của cây:
int highOfTree = -1e9;
void duyet_NLR(node* tree, int level){
	if(tree != NULL){
		duyet_NLR(tree->left, level + 1);
		if(highOfTree < level) highOfTree = level;
		duyet_NLR(tree->right, level+1);
		if(highOfTree < level) highOfTree = level;
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
		duyet_NLR(tree, 1);
		//nếu số node của cây bằng 2^(chiều cao cây) - 1 thì đó là cây np hoàn hảo.
		if((canh+1) == (pow(2, highOfTree) - 1)) cout << "Yes\n";
		else cout << "No\n";
		highOfTree = -1e9;
	}	
}
