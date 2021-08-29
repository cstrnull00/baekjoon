//https://www.acmicpc.net/problem/1012

#include <iostream>
#include <vector>

using namespace std;

int t, m, n, k;
int map[51][51];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0,0,-1,1 };

void dfs(int x, int y) {

	map[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (map[nx][ny]) {
				dfs(nx, ny);
			}
		}
	}

}

int main() {

	cin >> t;

	while (t--) {
		int cnt = 0;
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j]) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout << cnt << endl;
	}

	return 0;
}