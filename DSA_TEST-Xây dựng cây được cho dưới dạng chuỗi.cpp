/*
Một cây nhị phân được biểu diễn như một string trong đó các số trong string là giá trị của node, các xâu ký tự có giá trị "N" biểu diễn giả trị NULL của cây con trái hoặc cây con phải theo mức. Vì dụ với xâu S = "1 2 3 N N 4 6 N 5 N N 7 N" là biểu diễn của cây nhị phân theo mức dưới đây:

Phép duyệt các node trên cây theo RNI. được tiến hành bằng cách kiểm tra nếu cây khác rồng ta duyệt RNL sang cây con phải, sau đó thăm node và đuyệt RNI sang cây con trải ví dụ với cây ở trên ta có kết quả là RNL(root) = 6 3 5 7 4 1 2

Cho xâu kỳ tư biểu diễn cây nhị phân theo mức, nhiệm vụ của bạn là đưa ra kết quả của phép duyệt cây RNL

Input:

• Dòng đầu tiên đưa vào số lượng bộ test T

• Những đòng tiếp theo đâm vào các xâu S là biểu diễn cây nhị phân theo mức.
Ràng buộc: 15 T≤100:15 length(S)≤10000.
Output:
• Đưa ra kết quả mỗi test theo từng dòng
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
    string data;
    node* left;
    node* right;
    node(string x){
        data = x;
        left = right = NULL;
    }
};
void insert(node* &tree, vector<string> v){
    queue<node* > q;
    tree = new node(v[0]);
    int idx = 1;

    q.push(tree);
    while(!q.empty() && idx < v.size()){
        node* t = q.front(); // lấy ra node gốc để tạo 2 node con đang xét có node gốc là t
        q.pop();
        string x = v[idx]; // xét node con bên trái
        if(x != "N"){
            t->left = new node(x);
            q.push(t->left);
        }
        ++idx; // xét tới node con bên phải
        if(idx >= v.size()) break;
        x = v[idx];
        if(x != "N"){
            t->right = new node(x);
            q.push(t->right);
        }
        ++idx;
    }
}
void duyet_RNL(node* tree){
    if(tree != NULL){
        duyet_RNL(tree->right);
        cout << tree->data << " ";
        duyet_RNL(tree->left);
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        string s;
        node* tree = NULL;
        getline(cin>>ws, s);
        stringstream ss(s);
        string tmp;
        vector<string> v;
        while(ss >> tmp) v.push_back(tmp);
        insert(tree, v);
        duyet_RNL(tree);
        cout << endl;
    }
    return 0;
}
