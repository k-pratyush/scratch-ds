#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool isMatching(string s) {
    stack<char>st;
    for(char ch: s) {
        if(ch == '(') {
            st.push(ch);
        } else if(ch == ')') {
            if(st.empty()) {
                return false;
            } else {
                st.pop();
            }
        }
    }
    return st.empty()? true: false;
}

int main() {
    string s = "()()(";
    cout << isMatching(s) << endl;
}