//https://www.acmicpc.net/problem/11866

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	queue<int> q;
	for (int i = 1; i <= n; i++) q.push(i);

	vector<int> josephus;
	int t = 1, c;
	while (!q.empty()) {
		c = q.front();
		q.pop();
		if (t == k) {
			josephus.push_back(c);
			t = 0;
		}
		else q.push(c);
		t++;
	}

	cout << "<";
	for (auto i : josephus) {
		cout << i;
		if (i != josephus.back()) cout << ", ";
	}
	cout << ">";

	return 0;
}