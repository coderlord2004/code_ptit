#include<bits/stdc++.h>
using namespace std;
vector<int> a[2005];
int chuaxet[1000] = {0};
int dinh, canh, begin_point, end_point;
vector<int> path;
int found = 0;
void dfs(int u){
	chuaxet[u] = 1;
	path.push_back(u);
	if(u == end_point){
		found++;
		for(int i=0; i<path.size(); i++){
			cout << path[i] << " ";
		}
		cout << endl;
		return;
	}
	for(int v : a[u]){
		if(!chuaxet[v]){
			dfs(v);
		}
	}
	path.pop_back();
}
void init(){
	for(int i=1; i<=canh; i++){
		int x, y; cin >> x >> y;
		a[x].push_back(y);
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> dinh >> canh >> begin_point >> end_point;
		init();
		dfs(begin_point);
		if(found == 0) cout << -1 << endl;
		
		found = 0;
		memset(chuaxet, 0, sizeof(chuaxet));
		for(int i=0; i<1005; i++) a[i].clear();
		path.clear();
	}
}
