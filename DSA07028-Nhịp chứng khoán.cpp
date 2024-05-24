/*
Bạn là một nhà đầu tư chứng khoán nổi tiếng. Nhiệm vụ hàng ngày của bạn là tính nhịp tăng giảm của phiên chứng khoán trong N ngày để có thể bắt kịp thị trường. Nhịp chứng khoán của ngày thứ i được định nghĩa là số ngày liên tiếp từ ngày thứ i trở về mà giá chứng khoán bé hơn hoặc bằng với giá chứng khoán của ngày i.
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int &x : a) cin >>x;
        stack<int> st;
        int kq[n];
        st.push(0);
        for(int &x : kq) x=1;
        for(int i=0; i<n; i++){
            while(!st.empty() && a[st.top()] <= a[i]){
                st.pop();   
            }
            if(!st.empty()){
                kq[i] += (i-st.top()-1);
            }
            else kq[i] += i;
            st.push(i);
        }
        for(int i=0; i<n; i++){
            cout << kq[i] << " ";
        }
        cout << endl;
    } 
 
}
