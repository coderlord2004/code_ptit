/*
Cho mảng A[] gồm n phần tử. Hãy đưa ra các phần tử nhỏ hơn tiếp theo của phần tử lớn hơn đầu tiên phần tử hiện tại. Nếu phần tử hiện tại không có phần tử lớn hơn tiếp theo ta xem là -1. Nếu phần tử không có phần tử nhỏ hơn tiếp theo ta cũng xem là -1. Ví dụ với mảng A[] = {5, 1, 9, 2, 5, 1, 7} ta có kết quả là ans = {2, 2, -1, 1, -1, -1, -1} vì:
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
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && a[st.top()] <= a[i]) st.pop(); // pop lặp đến khi phần tử có chỉ số ở top lớn hơn phần tử hiện tại
            if(st.empty()) kq[i] = -1; // nếu sau khi pop hết nghĩa là không có phần tử lớn hơn đầu tiên thì là -1
            else{
                int check = 0, key = st.top(); // st.top() lưu vị trí của phần tử đầu tiên lớn hơn
                for(int j=key+1; j<n; j++){ //tìm sau vị trí đó phần tử đầu tiên nhỏ hơn
                    if(a[j] < a[key]){
                        kq[i] = a[j];
                        check++;
                        break;
                    }
                }
                if(check == 0 ) kq[i] = -1;
            }
            st.push(i);
        }
        for(int i=0; i<n; i++) cout << kq[i] << " ";
        cout << endl;
    } 
 
}
