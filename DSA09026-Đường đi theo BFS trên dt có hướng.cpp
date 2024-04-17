#include<bits/stdc++.h>
using namespace std;
vector<int> a[2005];
int chuaxet[2001] = {0}, pre[2001];
int dinh, canh, nguon, dich;


void init(){
	for(int i=1; i<=canh; i++){
		int x, y; cin >> x >> y;
		a[x].push_back(y);
	}
}
void truy_vet(){
	if(chuaxet[dich] == 0){
		cout << -1 << endl;
		return;
	}
	vector<int> path;
	while(dich != nguon){
		path.push_back(dich);
		dich = pre[dich];
	}		
	path.push_back(nguon);
	for(int i=path.size()-1; i>=0; i--)
		cout << path[i] << " ";
	cout << endl;
}
void bfs(int u){
	queue<int> q;
	q.push(u);
	chuaxet[u] = 1;
	while(!q.empty()){
		int s = q.front();
		q.pop();
		for(int v : a[s]){
			if(!chuaxet[v]){
				q.push(v);
				chuaxet[v] = 1;
				pre[v] = s;
			}
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> dinh >> canh >> nguon >> dich;
		init();
		bfs(nguon);
        truy_vet();
		memset(pre, 0, sizeof(pre));
		for(int i=0; i<1005; i++) a[i].clear();
		memset(chuaxet, 0, sizeof(chuaxet));
	}
}
