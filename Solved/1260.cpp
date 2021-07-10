//https://www.acmicpc.net/problem/1260

#include <iostream>
#include <queue>

using namespace std;

int N, M, V;
int matrix[1001][1001];
bool visited[1001];
queue<int> que;

void dfs(int curr) {
	visited[curr] = true;
	cout << curr << " ";

	for (int i = 1; i <= N; i++) {
		if (matrix[curr][i] && !visited[i]) dfs(i);
	}
}

void bfs(int curr) {
	que.push(curr);
	visited[curr] = true;

	cout << curr << " ";

	while (!que.empty()) {
		curr = que.front();
		for (int i = 1; i <= N; i++) {
			if (matrix[curr][i] && !visited[i]) {
				que.push(i);
				visited[i] = true;
				cout << i << " ";
			}
		}
		que.pop();
	}

}

int main() {
	scanf("%d %d %d", &N, &M, &V);

	int s, e;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &s, &e);
		matrix[s][e] = 1;
		matrix[e][s] = 1;
	}

	dfs(V);

	cout << endl;
	for (int i = 1; i <= N; i++) visited[i] = false;

	bfs(V);

	return 0;
}