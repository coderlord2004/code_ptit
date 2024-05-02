

#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> a[2000];
vector<pair<int, int>> bri; // khởi tạo danh sách chứa cạnh cầu
int chuaxet[1005] = {0};
int id[1005], low[1005]; // id[u] là thứ tự duyệt của đỉnh u, mảng 
//low[u] chứa id nhỏ nhất trong các đỉnh mà u có thể đi đến	 
int dinh, canh, cnt = 0;

void init(){
	for(int i=1; i<=canh; i++){
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
}
void dfs(int u, int par){
	chuaxet[u] = 1;
	low[u] = id[u] = ++cnt;
	for(int v : a[u]){
		if(!chuaxet[v]){
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] > id[u]){ // nếu đỉnh thấp nhất mà u có thể đi tới vẫn lớn hơn thứ tự đã duyệt u thì (u, v) là cạnh cầu.
				bri.push_back({min(u, v), max(u, v)}); // đảm bảo u luôn nhỏ hơn v trước khi push_back
			}
		}
		else if(v != par) low[u] = min(low[u], id[v]);
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> dinh >> canh;
		init();
		dfs(1, 0);
		sort(bri.begin(), bri.end());
		for(auto it : bri){
			cout << it.first << " " << it.second << " ";
		}
		cout << endl;

		cnt = 0;
		for(int i=0; i<2000; i++) a[i].clear();
		bri.clear();
		memset(chuaxet, 0, sizeof(chuaxet));
		memset(id, 0, sizeof(id));
		memset(low, 0, sizeof(low));

	}
}
