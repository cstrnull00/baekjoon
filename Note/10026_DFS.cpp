//https://www.acmicpc.net/problem/10026

#include <iostream>
#include <string>

#define MAX 101

using namespace std;

int N;
bool visited[MAX][MAX];
char region[MAX][MAX];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		if (x + dx[i] < 0 || x + dx[i] >= N || y + dy[i] < 0 || y + dy[i] >= N) continue;
		if (!visited[x + dx[i]][y + dy[i]] && region[x][y] == region[x + dx[i]][y + dy[i]])
			dfs(x + dx[i], y + dy[i]);
	}
}

int main() {
	int cnt = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%s", region[i]);

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			if (!visited[i][j]) {
				dfs(i, j);
				cnt++;
			}
	cout << cnt << " ";

	cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
			if (region[i][j] == 'R') region[i][j] = 'G';
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!visited[i][j]) {
				dfs(i, j);
				cnt++;
			}
	cout << cnt;

	return 0;
}