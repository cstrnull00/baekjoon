//https://www.acmicpc.net/problem/11724

#include <iostream>

using namespace std;

int n, m;
int matrix[1001][1001];
bool node[1001];

void dfs(int s) {
	node[s] = true;

	for (int i = 1; i <= n; i++) {
		if (matrix[s][i] && !node[i]) dfs(i);
	}
}

int main() {
	int cnt = 0;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		matrix[s][e] = 1;
		matrix[e][s] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (!node[i]) {
			dfs(i);
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}