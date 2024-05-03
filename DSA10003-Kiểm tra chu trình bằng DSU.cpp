#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<int,int>> dscanh;
int par[1005], sz[1005];
int dinh, canh;
void init(){
	cin >> dinh >> canh;
	for(int i=1; i<=canh; i++){
		int x, y;
		cin >> x >> y;
		dscanh.push_back({x, y});
	}
}
void makeSet(){
	for(int i=1; i<=dinh; i++){
		par[i] = i;
		sz[i] = 1;
	}
}
int Find(int u){
	if(u == par[u]) return u;
	return par[u] = Find(par[u]);
}
bool Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if(a == b) return true;
	if(sz[a] < sz[b]) swap(a, b);
	par[b] = a;
	sz[a] += sz[b];
	return false;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		init();
		makeSet();
		int check = 0;
		for(auto it : dscanh){
			if(Union(it.first, it.second)){
				cout << "YES\n";
				check++;
				break;
			}
		}	
		if(check==0) cout << "NO\n";
		dscanh.clear();
	}
}
