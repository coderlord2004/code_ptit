#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int t;
	cin >> t;
	while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        int a[n], b[m], c[k];
        for(int &x : a) cin >> x;
        for(int &x : b) cin >> x;
        for(int &x : c) cin >> x;
        int i=0, j=0, x=0;
        int check = 0;
        while(i<n && j<m && x<k){
            if(a[i] == b[j] && b[j] == c[x]){
                check++;
                cout << a[i] << " ";
                ++i; ++j; ++x;
            }
            else if(a[i] < b[j] || a[i] < c[x]) ++i;
            else if(b[j] < a[i] || b[j] < c[x]) ++j;
            else if(c[x] < a[i] || c[x] < b[j]) ++x;
        }
        if(check == 0) cout << "NO";
        cout << endl;
    }
}
