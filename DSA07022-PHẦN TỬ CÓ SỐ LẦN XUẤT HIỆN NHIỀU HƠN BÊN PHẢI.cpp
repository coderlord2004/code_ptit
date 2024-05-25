/*
Cho mảng A[]  gồm n phần tử. Nhiệm vụ của bạn là tìm phần tử gần nhất phía bên phải có số lần xuất hiện lớn hơn phần tử hiện tại. Nếu không có phần tử nào có số lần xuất hiện lớn hơn phần tử hiện tại hãy đưa ra -1.

Ví dụ với dãy A[] = {1, 1, 2, 3, 4, 2, 1 }, ta nhận được kết quả ans[] = {-1, -1, 1, 2, 2, 1, -1} vì số lần xuất hiện mỗi phần tử trong mảng là F = {3, 3, 2, 1, 1, 2, 3} vì vậy phần tử A[0] = 1 có số lần xuất hiện là 3 và không có phần tử nào xuất hiện nhiều hơn 3 nên ans[0] = -1, tương tự như vậy với A[2]=2 tồn tại A[6] =1 có số lần xuất hiện là 3 nên ans[2] = 1.
*/
#include <bits/stdc++.h>
using namespace std;


int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        map<int,int> mp;
        for(int i=0; i<n; i++){
            cin >> a[i];
            mp[a[i]]++;
        }
        int cnt[n], kq[n];
        for(int i=0; i<n; i++) cnt[i] = mp[a[i]];
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && cnt[st.top()] <= cnt[i]) st.pop();
            if(st.empty()) kq[i] = -1;
            else kq[i] = a[st.top()];
            st.push(i);
        }
        for(int i=0; i<n; i++){
            cout << kq[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
