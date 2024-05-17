/*
ĐẾM SỐ NODE LÁ CÂY NHỊ PHÂN TÌM KIẾM CÂN BẰNG

Hãy xây dựng một cây nhị phân tìm kiếm cân bằng từ dãy số A[] =(a0, a1, .., an-1}. Đếm số node lá của cây nhị phân tìm kiếm cân bằng.  Ví dụ với dãy A[]={40, 28, 45, 38, 33, 15, 25, 20, 23, 35, 30} ta sẽ có phép duyệt theo thứ tự trước của cây nhị phân tìm kiếm cân bằng với số node lá là 5 : 15, 23, 30, 35 45.
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
    int data;
    node* left;
    node* right;
    node(int x){
        data = x;
        left = right = NULL;
    }
};
int cnt = 0;
void duyet(node* tree){
    if(tree != NULL){
        if(tree->left ==NULL && tree->right == NULL) ++cnt;
        duyet(tree->left);
        duyet(tree->right);
    }
}
void insert(node* &tree, int x){
    if(tree == NULL) tree = new node(x);
    else{
        if(tree->data > x) insert(tree->left, x);
        else if(tree->data < x) insert(tree->right, x);
    }
}
void split(node* &tree, int a[], int l, int r){
    if(l<=r){
        int mid = (l+r)/2;
        insert(tree, a[mid]);
        split(tree, a, l, mid-1);
        split(tree, a, mid+1, r);
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a[n];
        node* tree = NULL;
		for(int &x : a) cin >> x;
		sort(a, a+n);
        split(tree, a, 0, n-1);
        duyet(tree);
        cout << cnt << endl;
        cnt = 0;
    }
    return 0;
}
