/*
Cho ma trận A[M][N]. Nhiệm vụ của bạn hãy tìm số bước đi ít nhất dịch chuyển từ vị trí A[1][1] đến vị trí A[M][N]. Biết mỗi bước đi ta chỉ được phép dịch chuyển đến vị trí A[i][j+A[i][j]] hoặc vị trí A[i+A[i][j]][j] bên trong ma trận.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là hai số M, N; phần thứ hai là các phần tử của ma trận A[][]; các số được viết cách nhau một vài khoảng trống.
T, M, N, A[i][j] thỏa mãn ràng buộc: 1≤T≤100; 1≤M, N, A[i][j]≤103.
Output:

Đưa ra kết quả mỗi test theo từng dòng. In ra -1 nếu không tìm được đáp án.
Ý tưởng: mỗi bước đi là trạng thái tiếp theo và đẩy vào trong hàng đợi
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		int a[n][m], chuaxet[n][m]; // ma trận chuaxet để kiểm tra xem phần tử a[i][j] đã được sinh ra trước đó hay chưa.
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin >> a[i][j];
				chuaxet[i][j] = 0; // chưa được sinh ra.
			}
		}
		queue<pair<pair<int,int>, int>> q; // dùng pair để lưu cặp chỉ số i, j hiện tại và số bước đi.
		q.push({{0, 0}, 0});
		int check = 0;
		while(!q.empty()){
			auto top = q.front(); // lấy ra vị trí hiện tại
			q.pop();
			int i = top.first.first, j = top.first.second; // lấy ra chỉ số i, j hiện tại.
			int cur_val = a[i][j]; // lấy ra giá trị a[i][j] hiện tại.
			if(i == n-1 && j == m-1){
				cout << top.second << endl;
				check++;
				break;
			}
			if((j + cur_val) < m && chuaxet[i][j + cur_val] == 0){
				q.push({{i, j + cur_val}, top.second + 1});
				chuaxet[i][j + cur_val] = 1;
			}
			if((i + cur_val) < n && chuaxet[i + cur_val][j] == 0){
				q.push({{i + cur_val, j}, top.second + 1});
				chuaxet[i + cur_val][j] = 1;
			}
		}
		if(check == 0) cout << -1 << endl;
	}
}
