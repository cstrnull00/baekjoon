//https://www.acmicpc.net/problem/10773

#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> stack;
	int n, sum = 0;

	cin >> n;
	while (n--) {
		int num;
		cin >> num;

		if (num != 0)
			stack.push_back(num);
		else stack.pop_back();
	}

	if (!stack.empty())
		for (auto i : stack) sum += i;

	cout << sum;

	return 0;
}