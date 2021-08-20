//https://www.acmicpc.net/problem/11659

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;

	cin >> n >> m;
	vector<int> num;

	num.push_back(0);

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		num.push_back(input + num.back());
	}

	while (m--) {
		int s, e;
		cin >> s >> e;
		cout << num[e] - num[s - 1] << '\n';
	}

	return 0;
}