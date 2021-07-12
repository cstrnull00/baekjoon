//https://www.acmicpc.net/problem/2667

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define MAX 26

using namespace std;

int N;
int map[MAX][MAX];
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

bool visited[MAX][MAX];

int dfs(int x, int y) {
	int cnt = 1;
	pair<int, int> next;
	vector<pair<int, int>> stack;

	stack.push_back(make_pair(x, y));
	visited[x][y] = true;
	
	while (!stack.empty()) {
		pair<int, int> curr = stack.back();
		stack.pop_back();
		
		for (int i = 0; i < 4; i++) {
			next.first = curr.first + dir[i][0];
			next.second = curr.second + dir[i][1];

			if (next.first >= 0 && next.first < N && next.second >= 0 && next.second < N) {
				if (map[next.first][next.second] != 0 && !visited[next.first][next.second]) {
					stack.push_back(next);
					//curr = next;
					cnt++;	
				}
				visited[next.first][next.second] = true;
			}
		}
		
	}

	return cnt;
}

int main() {
	vector<int> complex;
	int cnt = 0;

	scanf("%d ", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = getchar() - '0';
		}
		getchar();
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && map[i][j] != 0) {
				complex.push_back(dfs(i, j));
				cnt++;
			}
		}
	}

	sort(complex.begin(), complex.end());

	cout << cnt << endl;
	for (int i = 0; i < cnt; i++) cout << complex[i] << endl;

	return 0;
}