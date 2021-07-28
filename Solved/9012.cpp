//https://www.acmicpc.net/problem/9012

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	while (N--) {
		char str[51];
		vector<char> stack;
		bool flag = true;

		cin >> str;
		int i = 0;

		while (str[i] != 0) {
			if (str[i] == '(') {
				stack.push_back('(');
			}
			else if (str[i] == ')') {
				if (stack.empty()) {
					flag = false;
					break;
				}
				else stack.pop_back();
			}
			i++;
		}

		if (stack.empty() && flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}