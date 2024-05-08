#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<set<int>> a(100005);
int chuaxet[100005] = {0};
int canh;
void init(){
	for(int i=1; i<canh; i++){
		int x, y; cin >> x >> y;
		a[x].insert(y);
	}
}
int ans = -1e9;
void dfs(int u, int cnt){
	chuaxet[u] = 1;
	for(int v : a[u]){
		if(!chuaxet[v]){
			ans = max(ans, cnt);
			dfs(v, cnt+1);
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> canh;
		init();		
		dfs(1, 1);
		cout << ans <<endl;

		ans = -1e9;
		memset(chuaxet, 0, sizeof(chuaxet));
		for(int i=0; i<a.size(); i++) a[i].clear();
	}	
}
