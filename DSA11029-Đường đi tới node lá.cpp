#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<set<int>> a(100005);
int chuaxet[100005] = {0};
int canh;
vector<string> v;
void init(){
	for(int i=1; i<canh; i++){
		int x, y; cin >> x >> y;
		a[x].insert(y);
	}
}
void dfs(int u, string path){
	chuaxet[u] = 1;
	for(int v : a[u]){
		if(!chuaxet[v]){
			dfs(v, path +" "+ to_string(v));
		}
	}
	if(a[u].size() == 0) v.push_back(path);
}
bool cmp(string a, string b){
	int i = a.find_last_of(" ");
	int j = b.find_last_of(" ");
	return stoi(a.substr(i, a.size())) < stoi(b.substr(j ,b.size()));
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> canh;
		if(canh == 1) cout << 1 << endl;
		else {
			init();		
			dfs(1, "1");
			sort(v.begin(), v.end(), cmp);
			for(string s : v){
				for(int i=0; i<s.size(); i++){
					cout << s[i];
				}
				cout << endl;
			}
			v.clear();
		}
		memset(chuaxet, 0, sizeof(chuaxet));
		for(int i=0; i<a.size(); i++) a[i].clear();
	}	
}
