//https://www.acmicpc.net/problem/14496

#include <iostream>
#include <queue>
#include <vector>

using namespace std;



int main() {
	vector<int> edge[1001];
	int change[1001];
	int a, b, N, M;
	int ta, tb;

	scanf("%d %d", &a, &b);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &ta, &tb);
		edge[ta].push_back(tb);
		edge[tb].push_back(ta);
	}

	for (int i = 0; i <= N; i++) change[i] = -1;

	queue<int> que;

	que.push(a);

	while (!que.empty()) {
		int curr = que.front();
		que.pop();
		change[a] = 0;

		if (curr == b) { cout << change[curr]; return 0; }

		for (int next : edge[curr]) {
			if (change[next] < 0) {
				que.push(next);
				change[next] = change[curr] + 1;
			}
		}
	}

	cout << -1;

	return 0;
}