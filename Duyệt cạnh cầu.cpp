

#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> a[2000];
vector<pair<int,int>> dscanh;
int chuaxet[1005] = {0};
int dinh, canh;

void init(){
	for(int i=1; i<=canh; i++){
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
		dscanh.push_back({x, y}); // khởi tạo dscanh
	}
}
void dfs(int u, int s, int t){ //(s, t) là cạnh cần loại bỏ
	chuaxet[u] = 1;
	for(int v : a[u]){
		if((u == s && v == t) || (u == t && v == s)) continue;
		if(!chuaxet[v]){
			dfs(v, s, t);
		}
	}
}
void canh_cau(){
	for(auto it : dscanh){ // duyệt dscanh
		int dem = 0;
		int x = it.first, y = it.second; // (x, y) là cạnh cần loại bỏ
		memset(chuaxet, 0, sizeof(chuaxet));
		for(int j=1; j<=dinh; j++){ //tìm số tplt của đt sau khi loại bỏ cạnh
			if(!chuaxet[j]){
				++dem;
				dfs(j, x, y);
			}
		}
		if(dem > 1){
			if(x > y) swap(x, y);
			cout << x << " " << y << " ";
		}
	}

}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> dinh >> canh;
		init();
		canh_cau();
		cout << endl;

		dscanh.clear();
		for(int i=0; i<2000; i++) a[i].clear();
		memset(chuaxet, 0, sizeof(chuaxet));
	}
}
