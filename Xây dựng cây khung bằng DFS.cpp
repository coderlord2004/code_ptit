/*
Cho đồ thị vô hướng G=(V, E). Hãy xây dựng một cây khung của đồ thị G với đỉnh u ∈ V là gốc của cây bằng thuật toán DFS.

Input

Dòng đầu tiên gồm một số nguyên T (1 ≤ T ≤ 20) là số lượng bộ test.

Tiếp theo là T bộ test, mỗi bộ test có dạng sau:

Dòng đầu tiên gồm 3 số nguyên N=|V|, M=|E|, u (1 ≤ N ≤ 103, 1 ≤ M ≤ 105, 1 ≤ u ≤ N).
M dòng tiếp theo, mỗi dòng gồm 2 số nguyên a, b (1 ≤ a, b ≤ N, a ≠ b) tương ứng cạnh nối hai chiều từ a tới b.
Dữ liệu đảm bảo giữa hai đỉnh chỉ tồn tại nhiều nhất một cạnh nối.
Output

Với mỗi bộ test, nếu tồn tại cây khung thì in ra N – 1 cạnh của cây khung với gốc là đỉnh u trên N – 1 dòng theo thứ tự duyệt của thuật toán DFS. Ngược lại nếu không tồn tại cây khung thì in ra -1.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> a[2000];
vector<pair<int, int>> tree;
int chuaxet[1005] = {0};
int dinh, canh, nguon;
void init(){
	for(int i=1; i<=canh; i++){
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
}
void dfs(int u){
	chuaxet[u] = 1;
	for(int v : a[u]){
		if(!chuaxet[v]){
			tree.push_back({u, v});
			dfs(v);
		}
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> dinh >> canh >> nguon;
		init();
		dfs(nguon);		
			
		if(tree.size() < dinh-1){
			cout << -1 << endl;
		}
		else{
			for(int i=0; i<tree.size(); i++)
				cout << tree[i].first << " " << tree[i].second << endl;	
		}
		tree.clear();
		for(int i=0; i<2000; i++) a[i].clear();
		memset(chuaxet, 0, sizeof(chuaxet));
	}
}
