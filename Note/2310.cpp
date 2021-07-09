//https://www.acmicpc.net/problem/2310

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct Room {
	char type;
	int gold;
}room[1005];

bool ans, visited[1005];
vector<int> enter[1005];
int n;

void dfs(int curr, int wallet) {
	if (room[curr].type == 'L' && wallet < room[curr].gold)
		wallet = room[curr].gold;

	if (room[curr].type == 'T') {
		if (wallet < room[curr].gold) return;
		else wallet -= room[curr].gold;
	}

	if (curr == n) { ans = true; return; }

	visited[curr] = true;
	for (int i = 0; i < enter[curr].size(); i++) {
		int next = enter[curr][i];
		if (!visited[next]) dfs(next, wallet);
	}
	visited[curr] = false;
}

int main() {
	int c;

	while (scanf("%d", &n)) {
		getchar();

		if (n == 0) break;

		for (int i = 0; i < 1005; i++)
			enter[i].clear();
		ans = false;

		for (int i = 1; i <= n; i++) {
			scanf("%c %d", &room[i].type, &room[i].gold);

			while (scanf("%d", &c)) {
				getchar();
				if (c == 0) break;
				enter[i].push_back(c);
			}
		}

		dfs(1, 0);

		if (ans) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}