/*Kiểm tra đồ thị có tồn tại chu trình hay không và truy vết chu trình đó*/
#include<bits/stdc++.h>
using namespace std;

vector<int> a[2005];
int color[2001] = {0};
int dinh, canh, parent[1005];
int dich;
void init(){
    for(int i=1; i<=canh; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
}

bool dfs(int u){
    color[u] = 1; // chưa duyệt hết các đỉnh kề
    for(int v : a[u]){
        if(color[v] == 0){
            parent[v] = u;
            if(dfs(v)) {
                return true;
            }
        }
        else if(color[v] == 1){
			dich = u; // truy vết từ u vì khi tìm thấy đường dẫn thì v trùng với đỉnh nguồn.
            return true;
        }
    }
    color[u] = 2; //đã duyệt xong
    return false;
}
// hàm truy vết từ đích trở về nguồn:
void truy_vet(int nguon){
	vector<int> path;
	path.push_back(nguon);
	while(nguon != dich){
		path.push_back(dich);
		dich = parent[dich];
	}
	path.push_back(nguon);
	for(int i=path.size()-1; i>=0; i--)
		cout << path[i] << " ";
	cout << endl;
}


int main(){
    int t; cin >> t;
    while(t--){
        cin >> dinh >> canh;
        init();
        int check = 0;
        for(int i=1; i<=dinh; i++){
            if(color[i] == 0){
                if(dfs(i)){
                    cout << "YES\n";
                    check++;
                    truy_vet(i);
                    break;
                }
            }
        }
        if(check == 0) cout << "no path!\n";
        
        memset(parent, 0, sizeof(parent));
        for(int i=0; i<1005; i++) a[i].clear();
        memset(color, 0, sizeof(color));
    }
    return 0;
}
