#include<bits/stdc++.h>
using namespace std;
vector<int> a[2005];
int chuaxet[1000] = {0};
int dinh, canh, begin_point, end_point;
vector<int> path;


void stack_dfs(int u){
	int found = 0;
	stack<int> st;
	st.push(u);
	chuaxet[u] = 1;
	vector<int> path;
	path.push_back(u);
	while(!st.empty()){
		int s = st.top();
		if(s == end_point){
			for(int i=0; i<path.size(); i++)
				cout << path[i] << " ";
			cout << endl;
			found++;
			break;
		}
		st.pop();
		path.pop_back();
		for(int v : a[s]){
			if(!chuaxet[v]){
				chuaxet[v] = 1;
				st.push(s); st.push(v);
				path.push_back(s); path.push_back(v);
				break;
			}
		}
	}
	if(found == 0) cout << -1 << endl;
}
void init(){
	for(int i=1; i<=canh; i++){
		int x, y; cin >> x >> y;
		a[x].push_back(y);
	}
}
void reset(){
	memset(chuaxet, 0, sizeof(chuaxet));
	for(int i=0; i<1005; i++) a[i].clear();
	path.clear();
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> dinh >> canh >> begin_point >> end_point;
		init();
		stack_dfs(begin_point);
		//if(found == 0) cout << -1 << endl;
		
		reset();
	}
}
