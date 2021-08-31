//https://www.acmicpc.net/problem/1697

#include <iostream>
#include <queue>
#include <utility>

#define MAX 100001

using namespace std;

int n, k;
bool visit[MAX];

int bfs() {
	queue<pair<int, int>> que;
	que.push({ n, 0 });

	while (!que.empty()) {
		int curr = que.front().first;
		int sec = que.front().second;
		que.pop();
		
		visit[curr] = true;

		if (curr == k) return sec;
		
		if (curr + 1 < MAX && !visit[curr + 1]) que.push({ curr + 1, sec + 1 });
		if (curr - 1 >= 0 && !visit[curr - 1]) que.push({ curr - 1, sec + 1 });
		if (curr * 2 < MAX && !visit[curr * 2]) que.push({ curr * 2, sec + 1 });
	}
}

int main() {
	cin >> n >> k;
	cout << bfs();
	return 0;
}