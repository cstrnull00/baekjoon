//https://www.acmicpc.net/problem/4963

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define MAX 51

using namespace std;

int N, M;
int map[MAX][MAX];
int dir[8][2] = { {-1,0},{1,0},{0,1},{0,-1}, {-1,1}, {-1,-1}, {1, -1}, {1, 1} };

bool visited[MAX][MAX];

void dfs(int x, int y) {
	pair<int, int> next;
	vector<pair<int, int>> stack;

	stack.push_back(make_pair(x, y));
	visited[x][y] = true;

	while (!stack.empty()) {
		pair<int, int> curr = stack.back();
		stack.pop_back();

		for (int i = 0; i < 8; i++) {
			next.first = curr.first + dir[i][0];
			next.second = curr.second + dir[i][1];

			if (next.first >= 0 && next.first < M && next.second >= 0 && next.second < N) {
				if (map[next.first][next.second] != 0 && !visited[next.first][next.second]) {
					stack.push_back(next);
				}
				visited[next.first][next.second] = true;
			}
		}

	}
}

int main() {
	vector<int> islands;
	int cnt = 0;

	scanf("%d %d", &N, &M);

	while (N != 0 && M != 0) {
		cnt = 0;

		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &map[i][j]);

		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				if (!visited[i][j] && map[i][j] != 0) {
					dfs(i, j);
					cnt++;
				}

		islands.push_back(cnt);

		for(int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				visited[i][j] = false;

		scanf("%d %d", &N, &M);
	}

	for (auto i: islands) cout << i << endl;

	return 0;
}