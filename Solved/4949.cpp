//https://www.acmicpc.net/problem/4949

#include <iostream>
#include <vector>

using namespace std;

int main() {
	char c = getchar();

	while (1) {
		bool flag = true;
		char str[101] = { 0, };
		vector<char> stack;
		int i = 0;

		str[i++] = c;
		if (c == '(' || c == '[') stack.push_back(c);
		else if (stack.empty() && (c == ')' || c == ']')) flag = false;

		char n = c;

		c = getchar();

		if (n == '.' && c == '\n') break;

		while (c != '.') {
			str[i++] = c;

			if (c == '(' || c == '[') stack.push_back(c);

			if (c == ')') {
				if (stack.empty()) flag = false;
				else if (stack.back() == '(') stack.pop_back();
				else flag = false;
			}
			else if (c == ']') {
				if (stack.empty()) flag = false;
				else if (stack.back() == '[') stack.pop_back();
				else flag = false;
			}
			
			c = getchar();
		}

		getchar();

		if (!stack.empty()) flag = false;

		if (flag) cout << "yes" << endl;
		else cout << "no" << endl;

		stack.clear();
		c = getchar();
	}

	return 0;
}