/*
Cho biểu thức số học, hãy cho biết biểu thức số học có dư thừa các cặp ký hiệu ‘(’,’) ‘ hay không?
*/
#include <bits/stdc++.h> 

using namespace std; 
string solve(string s){
    stack<char> st;
    for(char c : s){
        if(c == ')'){
            bool check = true;
            while(st.top() != '('){
                char tmp = st.top();
                if(tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/') check = false; // không có toán tử là thừa dấu ngoặc
                st.pop();
            }
            // nếu check == true nghĩa là trong () không có toán hạng => ngoặc thừa
            if(check == true) return "Yes\n"; 
            st.pop();
        }
        else st.push(c);
    }
    return "No\n";
}
int main() {
	int t; cin >> t;
	while (t--) {
		string s; getline(cin>>ws, s);
		cout << solve(s);
	}
}
