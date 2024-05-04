#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<set<int>> ke(200000);
int chuaxet[100005];
int dinh, canh, cnt;

void init(){
	cin >> dinh >> canh;
	for(int i=1; i<=canh; i++){
		int x, y;
		cin >> x >> y;
		ke[x].insert(y);
		ke[y].insert(x);
	}
}
void dfs(int u){
	chuaxet[u] = 1;
	for(int v : ke[u]){
		if(!chuaxet[v]){
			++cnt;
			dfs(v);
		}
	}
}
int tplt(){
	int MAX = -1e9;
	for(int i=1; i<=dinh; i++){
		if(!chuaxet[i]){
		    cnt = 1;
			dfs(i);
			if(MAX < cnt) MAX = cnt;
		}
	}
	return MAX;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		init();
		cout << tplt() << endl;

		for(int i=0; i<2000; i++) ke[i].clear();
		memset(chuaxet, 0, sizeof(chuaxet));
	}
}
