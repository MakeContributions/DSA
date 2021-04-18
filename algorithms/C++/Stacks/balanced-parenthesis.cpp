#include<bits/stdc++.h>
using namespace std;
bool isBalanced(string s) {
	stack<char> st;
	char ch;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			st.push(s[i]);
			continue;
		}
		if (st.empty())
			return false;
		switch (s[i]) {
		case ')':
			ch = st.top();
			st.pop();
			if (ch == '{' || ch == '[')
				return false;
			break;
		case '}':
			ch = st.top();
			st.pop();
			if (ch == '(' || ch == '[')
				return false;
			break;
		case ']':
			ch = st.top();
			st.pop();
			if (ch == '(' || ch == '{')
				return false;
			break;
		}
	}
	return (st.empty());
}
int main() {
	string input = "{}[({})]";
	if (isBalanced(input))
		cout << "Balanced";
	else
		cout << "Not Balanced";
	return 0;
}
