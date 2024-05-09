/*
Cho một xâu chỉ gồm các kí tự ‘(‘ và ‘)’. Một dãy ngoặc đúng được định nghĩa như sau:

-     Xâu rỗng là 1 dãy ngoặc đúng.

-     Nếu A là 1 dãy ngoặc đúng thì (A) là 1 dãy ngoặc đúng.

-     Nếu A và B là 2 dãy ngoặc đúng thì AB là 1 dãy ngoặc đúng.

Cho một xâu S. Nhiệm vụ của bạn là hãy tìm dãy ngoặc đúng dài nhất xuất hiện trong xâu đã cho.
*/
#include <iostream> 
#include <stack> 
using namespace std; 
int main() {
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		stack<int> st;
		st.push(-1); // lưu vị trí của dấu trước dấu ngoặc đầu tiên
        int cnt = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(i); // push vị trí của dấu ngoặc mở
            }
            else{
                //nếu gặp ngoặc đóng thì pop
                //độ dài của dãy ngoặc đúng chính là vị trí dấu ngoặc đóng trừ đi vị trí trước của dấu ngoặc mở
                st.pop(); // pop dấu mở để đỉnh st là vị trí của dấu ngoặc trước đó
                //sau khi pop mà st ko rỗng thì cập nhật cnt coòn rỗng thì push thêm vị trí dấu hiện tại
                if(!st.empty()) cnt = max(cnt, i-st.top());
                else st.push(i);
            }
        }
		cout << cnt << endl;
	}
}
