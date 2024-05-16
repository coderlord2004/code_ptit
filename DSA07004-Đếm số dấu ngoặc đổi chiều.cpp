/*
Cho một xâu chỉ gồm các kí tự ‘(‘, ‘) và có độ dài chẵn. Hãy đếm số lượng dấu ngoặc cần phải đổi chiều ít nhất, sao cho xâu mới thu được là một dãy ngoặc đúng.
*/
//Ý tưởng: tìm và xoá hết tất cả các dấu () đúng, nếu không tìm thấy thì xâu chỉ xảy ra 3 TH: )(, ((, ))
//ta chỉ cần đổi chiều dấu ) ở đầu và ( ở cuối và đếm số lần đổi
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
		string s; cin >> s;
		int cnt = 0;
		while(s.size()){
			int key = s.find("()");
			if(key != -1){
				s.erase(key, 2);
			}
			else {
				if(s[0] == ')'){
					s[0] = '(';
					++cnt;
				}
				if(s[s.size()-1] == '('){
					s[s.size()-1] = ')';
					++cnt;
				}
			}
		}
		cout << cnt << endl;
	}
}
