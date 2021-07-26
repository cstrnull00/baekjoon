//https://www.acmicpc.net/problem/2164

#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n;
	queue<int> q;

	cin >> n;

	for (int i = 1; i <= n; i++) q.push(i);

	int t = 1;

	while (!q.empty()) {
		q.pop();
		if (q.empty()) break;
		t = q.front();
		q.pop();
		q.push(t);
	}

	cout << t;

	return 0;
}