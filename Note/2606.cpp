#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, m, u, v, cnt = 0;
	int current, next;
	bool visit[101];
	vector<int> network[101];
	queue<int> infection;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		network[u].push_back(v);
		network[v].push_back(u);
	}

	infection.push(1);
	visit[1] = true;

	while (!infection.empty()) {
		current = infection.front();
		infection.pop();
		cnt++;
		for (int i = 0; i < network[current].size(); i++) {
			next = network[current][i];
			if (!visit[next]) {
				visit[next] = true;
				infection.push(next);
			}
		}

	}

	cout << --cnt;

	return 0;
}